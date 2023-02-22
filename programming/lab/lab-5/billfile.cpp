// This program will read in the quantity of a particular item and its price.
// It will then print out the total price.
// The input will come from a data file and the output will go to
// an output file.

// Ian Jones

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ifstream dataIn;	// defines an input stream for a data file	
	ofstream dataOut;	// defines an output stream for an output file	
	int quantity;		// contains the amount of items purchased	
	float itemPrice;	// contains the price of each item	
	float	totalBill;	// contains the total bill, i.e. the price of all items

	dataIn.open("transaction.dat");	// This opens the file. 
	dataOut.open("bill.out");

  cout << setprecision(2) << fixed << showpoint;	// formatted output

  dataIn >> quantity >> itemPrice;

  totalBill = quantity * itemPrice;
  
	dataOut << "The price of the items is $" << totalBill << ".";

	return 0;
}
