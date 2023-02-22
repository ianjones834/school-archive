// This program will read in the quantity of a particular item and its price.
// It will then print out the total price.
// The input will come from the keyboard and the output will go to
// the screen.

// Ian Jones

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int	quantity; // contains the amount of items purchased 
	float itemPrice; // contains the price of each item
	float totalBill; // contains the total bill
  string itemName; // contains the name of the item

	cout << setprecision(2) << fixed << showpoint;	// formatted output 

  // Prompts user to input the name of the item
  cout << "Please input the name of the item" << endl;
  getline(cin, itemName);
  cout << endl;

  // Prompts user to input number of items
	cout << "Please input the number of items bought" << endl;
  cin >> quantity;
  cout << endl;

  // Prompts user to input price of items
  cout << "Please input the price of each item" << endl;
  cin >> itemPrice;
  cout << endl;

  // Calculates the total bill
  totalBill = quantity * itemPrice;

  // Outputs the item name and total bill in terminal
  cout << "The item that you bought is " << itemName << endl;
  cout << "The total bill is " << totalBill << endl;
  cout << endl;
	return 0;
}
