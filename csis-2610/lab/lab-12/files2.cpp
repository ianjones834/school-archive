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
  ofstream outFile;
	float gross;
	float net;
	float hours;
	float payRate;
	float stateTax;
	float fedTax;

	cout << fixed << setprecision(2) << showpoint;

  payfile.open("payroll.dat");
  outFile.open("pay.out");

  if (!payfile)
	{
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;
		return 1;
	}

	outFile << "Payrate Hours Gross Pay Net Pay" << endl;

  payfile >> hours;

  while (!payfile.eof())
	{
		payfile >> payRate >> stateTax >> fedTax;

		gross = payRate * hours;

		net = gross - (gross * stateTax) - (gross * fedTax);

    outFile << left << setw(8) << payRate << setw(6) << hours << setw(10)
            << gross << net << endl;

		payfile >> hours;
	}

	payfile.close();
  outFile.close();

	return 0;
}
