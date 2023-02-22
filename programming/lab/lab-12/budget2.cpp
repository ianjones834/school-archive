// This program reads in from the keyboard a record of financial information
// consisting of a person’s name, income, rent, food costs, utilities and
// miscellaneous expenses. It then determines the net money
// (income minus all expenses)and places that information in a record
// which is then written to an output file.

// Ian Jones 

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

const int NAMESIZE = 15;

struct	budget	// declare a structure to hold name and financial information
{
	char name[NAMESIZE + 1];
	float income;		// person's monthly income 
	float rent;			// person's monthly rent
	float food;			// person's monthly food bill 
	float utilities;	// person's monthly utility bill 
	float miscell;		// person's other bills
	float net;			// person's net money after bills are paid
};

int main()
{
	fstream indata;
	ofstream outdata;	// output file of
						// student. 

  char choice = 'Y';
  int count = 0;

  budget person;

	indata.open("income.dat", ios::out | ios::binary);	// open file as binary
														// output.

	outdata.open("student.out");	// output file that we
									// will write student
									// information to. 

	outdata << left << fixed << setprecision(2);	// left indicates left
													// justified for fields 

  while (choice == 'Y' || choice =='y')
  {
	  cout << "Enter the following information" << endl;

	  cout << "Person's name: ";
	  cin.getline(person.name, NAMESIZE);

	  cout << "Income: ";
	  cin >> person.income;

    cout << "Rent: ";
    cin >> person.rent;

    cout << "Food: ";
    cin >> person.food;

    cout << "Utilities: ";
    cin >> person.utilities;

    cout << "Miscellaneous: ";
    cin >> person.miscell;

	  person.net = person.income - (person.rent + person.food + person.utilities
                 + person.miscell);
  
    cout << "Enter Y if you would like to input more data: ";
    cin >> choice;

    cin.ignore();
    
    indata.write(reinterpret_cast<char *>(&person), sizeof(person));
   
    count++;
    
  }

  indata.close();

	// write this record to the file
	// Fill IN CODE TO WRITE THE RECORD TO THE FILE indata (one instruction)
	// FILL IN THE CODE TO REOPEN THE indata FILE, NOW AS AN INPUT FILE.
  indata.open("income.dat", ios::in);

	// FILL IN THE CODE TO READ THE RECORD FROM indata AND PLACE IT IN THE

	// write information to output file
	outdata << setw(20) << "Name" << setw(10) << "Income" << setw(10) << "Rent"
		    << setw(10) << "Food" << setw(15) << "Utilities" << setw(15)
		    << "Miscellaneous" << setw(10) << "Net Money" << endl << endl;

	// FILL IN CODE TO WRITE INDIVIDUAL FIELD INFORMATION OF THE RECORD TO
	// THE outdata FILE.(several instructions)

  indata.read(reinterpret_cast<char *>(&person), sizeof(person));
  
  while (!indata.eof())
  { 
    outdata << setw(20) << person.name 
          << setw(10) << person.income
          << setw(10) << person.rent 
          << setw(10) << person.food
          << setw(15) << person.utilities 
          << setw(15) << person.miscell 
          << setw(10) << person.net << endl;

    indata.read(reinterpret_cast<char *>(&person), sizeof(person));
  }

  return 0;
}
