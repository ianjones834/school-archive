// Ian Jones

#include <iostream>
using namespace std;

int main()
{
	char letter = 'a';

	do
  {
		cout << "Please enter a letter (or enter 'x' to exit)" << endl;
		cin >> letter;
    cout << endl;

		cout << "The letter you entered is " << letter << endl;
	} while (letter != 'x');

	return 0;
}

/* This code was not user friendly because it did not tell the user
 * how they should exit
 *
 * cout << "Please enter a letter"*/
