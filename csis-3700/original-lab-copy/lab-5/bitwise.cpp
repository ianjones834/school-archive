//Ian Jones

#include <iostream>
using namespace std;

void showBits(unsigned int n) {
	for (int i = 31; i >= 0; i--)
		if (n & (1 << i))
			cout << '1';
		else
			cout << '0';

		cout << endl;
}

int countBits(unsigned int n) {
	int count = 0;

	while (n != 0) {
		count++;
		n &= n - 1;
	}

	return count;
}

int main(void) {
	unsigned int
		a, b, c;

	cout << "Enter two nonnegative integers: ";
	cin >> a >> b;
	cout << endl;

	cout << "The first integer in binary is:  ";
	showBits(a);

	cout << "The second integer in binary is: ";
	showBits(b);
	cout << endl;

	c = a & b;
	cout << "The & of both integers is: ";
	showBits(c);

	c = a | b;
	cout << "The | of both integers is: ";
	showBits(c);

	c = ~a;
	cout << "The ~ of the first integer is: ";
	showBits(c);

	c = a ^ b;
	cout << "The ^ of both integers is: ";
	showBits(c);

	cout << endl;

	c = a << b;
	cout << "The << of the first by the second is: ";
	showBits(c);
	cout << endl;

	cout << "The number of bits in the first integer is: " << countBits(a) << endl;

	return 0;
}
