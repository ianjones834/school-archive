// This program demonstrates the use of dynamic variables

// Ian Jones 

#include <iostream>
using namespace std;

const int MAXNAME = 10;

int main()
{
	int pos;
	char *name = nullptr;
	int *one = nullptr;
	int *two = nullptr;
	int *three = nullptr;
	int result;
  
  one = new int;
  two = new int;
  three = new int;
  name = new char[MAXNAME];

	cout << "Enter your last name with exactly 10 characters." << endl;
	cout << "If your name has < 10 characters, repeat last letter. " << endl
		 << "Blanks at the end do not count." << endl;

	for (pos = 0; pos < MAXNAME; pos++)
		cin >> name[pos];

	cout << "Hi ";

	for (pos = 0; pos < MAXNAME; pos++)
		cout << name[pos];

	cout << endl << "Enter three integer numbers separated by blanks" << endl;
  cin >> *one >> *two >> *three;
  cout << endl;

	// Fill in code to input three numbers and store them in the
	// dynamic variables pointed to by pointers one, two, and three.
	// You are working only with pointer variables

	// echo print
	cout << "The three numbers are " << endl;
  cout << *one << " " << *two << " " << *three << endl;
	// Fill in code to output those numbers

	result = *one + *two + *three;// Fill in code to calculate the sum of the three numbers

	cout << "The sum of the three values is " << result << endl;

  delete one;
  delete two;
  delete three;
  delete [] name;
    
	return 0;
}
