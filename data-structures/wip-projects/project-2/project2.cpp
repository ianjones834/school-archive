#include <iostream>
#include "dictionary.h"
#include "stack.h"

Dictionary variableDictionary;

struct value {
	std::string name = "";
	Fraction number;
};

Stack<value> numStack;
Stack<char> opStack;

value evaluate(std::string command);
bool hasPrecedence(char opStackOperator, char inputOperator);
value doOperation();

int main () {
	std::cout << "Welcome to my Calculator Project" << std::endl;
	std::cout << "(Type '#' to exit)" << std::endl;
	std::string userCommand = "";

	while (userCommand != "#") {
		try {
			std::getline(std::cin, userCommand);

			if (userCommand != "#") {
				value result = evaluate(userCommand);
				std::cout << result.number << std::endl << std::endl;
			}
		}
		catch (std::underflow_error &e) {
			std::cout << "Bad Expression" << std::endl << std::endl;
		}
		catch (std::domain_error &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
	}

	return 0;
}

value evaluate(std::string command) {
	numStack.clear();
	opStack.clear();

	opStack.push('$');
	int first = 0;

	while (first < command.length()) {
		if (command[first] >= '0' && command[first] <= '9') {
			std::string numString = "";

			while (command[first] >= '0' && command[first] <= '9') {
				numString += command[first];
				first++;
			}

			value num;
			num.number = Fraction(std::stoi(numString), 1);
			numStack.push(num);
		}
		else if ((command[first] >= 'A' && command[first] <= 'Z') || (command[first] >= 'a' && command[first] <= 'z')) {
			value variable;

			while ((command[first] >= 'A' && command[first] <= 'Z') || (command[first] >= 'a' && command[first] <= 'z')) {
				variable.name += command[first];
				first++;
			}

			numStack.push(variable);
		}
		else if (command[first] == '(') {
			opStack.push('(');
			first++;
		}
		else if (command[first] == ')') {
			while (opStack.peek() != '(') {
				numStack.push(doOperation());
			}

			opStack.pop();
			first++;
		}
		else if (command[first] == '*' || command[first] == '/' || command[first] == '+' || command[first] == '-' || command[first] == '=') {
			while (hasPrecedence(opStack.peek(), command[first])) {
				numStack.push(doOperation());
			}

			opStack.push(command[first]);
			first++;
		}
		else {
			first++;
		}
	}

	while (opStack.peek() != '$') {
		numStack.push(doOperation());
	}

	const uint32_t numStackSize = numStack.size(),
								 opStackSize = opStack.size();

	if (numStackSize != 1 || opStackSize != 1) {
		throw std::underflow_error("");
	}

	return numStack.pop();
}

bool hasPrecedence(char opStackOperator, char inputOperator) {
	if (opStackOperator == '*' || opStackOperator == '/') {
		return true;
	}
	else if (opStackOperator == '$' || opStackOperator == '=' || opStackOperator == '(') {
		return false;
	}
	else if ((opStackOperator == '+' || opStackOperator == '-') && (inputOperator == '*' || inputOperator == '/')) {
		return false;
	}

	return true;
}

value doOperation() {
	value result;

	value rightHand = numStack.pop(),
			  leftHand = numStack.pop();

	char operation = opStack.pop();

	switch (operation) {
		case '=': {
			if (rightHand.name != "") {
				rightHand.number = variableDictionary.search(rightHand.name);
			}
			variableDictionary.add(leftHand.name, rightHand.number);
			result.number = rightHand.number;
			break;
		}
		case '+': {
			if (leftHand.name != "") {
				leftHand.number = variableDictionary.search(leftHand.name);
			}

			if (rightHand.name != "") {
				rightHand.number = variableDictionary.search(rightHand.name);
			}

			result.number = leftHand.number + rightHand.number;
			break;
		}
		case '-': {
			if (leftHand.name != "") {
				leftHand.number = variableDictionary.search(leftHand.name);
			}

			if (rightHand.name != "") {
				rightHand.number = variableDictionary.search(rightHand.name);
			}

			result.number = leftHand.number - rightHand.number;
			break;
		}
		case '*': {
			if (leftHand.name != "") {
				leftHand.number = variableDictionary.search(leftHand.name);
			}

			if (rightHand.name != "") {
				rightHand.number = variableDictionary.search(rightHand.name);
			}

			result.number = leftHand.number * rightHand.number;
			break;
		}
		case '/': {
			if (leftHand.name != "") {
				leftHand.number = variableDictionary.search(leftHand.name);
			}

			if (rightHand.name != "") {
				rightHand.number = variableDictionary.search(rightHand.name);
			}

			if (rightHand.number.getNum() == 0) {
				throw  std::domain_error("Divide by Zero");
			}

			result.number = leftHand.number / rightHand.number;
			break;
		}
		default: {
			throw std::logic_error("Unknown Operator");
		}
	}

	return result;
}
