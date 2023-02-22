// This program uses hours, pay rate, state tax and fed tax to determine gross
// and net pay.

// Ian Jones 

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  ifstream payfile;
	float gross;
	float net;
	float hours;
	float payRate;
	float stateTax;
	float fedTax;

	cout << fixed << setprecision(2) << showpoint;

  payfile.open("payroll.dat");

  if (!payfile)
	{
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;
		return 1;
	}

	cout << "Payrate	Hours	Gross Pay	Net Pay"
	     << endl << endl;

  payfile >> hours;

  while (!payfile.eof())
	{
		payfile >> payRate >> stateTax >> fedTax;

		gross = payRate * hours;

		net = gross - (gross * stateTax) - (gross * fedTax);

		cout << payRate << setw(15) << hours << setw(12) << gross
			 << setw(12) << net << endl;

		payfile >> hours;
	}

	payfile.close();

	return 0;
}
