// This program tests a password for the American Equities
// web page to see if the format is correct

// Ian Jones 

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//function prototypes
bool testPassWord(char[]);
int countLetters(char*);
int countDigits(char*);

int main()
{
	char passWord[20];

	cout << "Enter a password consisting of exactly 5 "
		 << "letters and 3 digits:" << endl;

	cin.getline(passWord, 20);

	if (testPassWord(passWord))
		cout << "Please wait - your password is being verified" << endl;

	else
	{
		cout << "Invalid password. Please enter a password "
			 << "with exactly 5 letters and 3 digits" << endl;
		cout << "For example, my37RuN9 is valid" << endl;
	}

	// Fill in the code that will call countLetters and
	// countDigits and will print to the screen both the number of
	// letters and digits contained in the password.
  cout << "Your password contains " << countLetters(passWord) << " letters." 
       << endl;
  cout << "Your password contains " << countDigits(passWord) << " digits." 
       << endl;

	return 0;
}

//**************************************************************
//	testPassWord
//
//  task:	       determines if the word in the
//	               character array passed to it, contains
//	               exactly 5 letters and 3 digits.
//  data in:	   a word contained in a character array
//  data returned: true if the word contains 5 letters & 3
//	               digits, false otherwise
//
//**************************************************************
bool testPassWord(char custPass[])
{
	int numLetters, numDigits, length;

	length = strlen(custPass);
	numLetters = countLetters(custPass);
	numDigits = countDigits(custPass);

	if (numLetters == 5 && numDigits == 3 && length == 8)
		return true;
	else
		return false;
}

// the next 2 functions are from Sample Program 10.5

//*******************************************************************
//	countLetters
//
//  task:	       This function counts the number of letters
//	               (both capital and lower case) in the string
//  data in:	   pointer that points to an array of characters
//  data returned: number of letters in the array of characters
//
//*******************************************************************

int countLetters(char *strPtr)
{
	int occurs = 0;

	while (*strPtr != '\0')	// loop is executed as long as
		// the pointer strPtr does not point
		// to the null character which
		// marks the end of the string
	{
		if (isalpha(*strPtr))	// isalpha determines if
			occurs++;			// the character is a letter

		strPtr++;
	}

	return occurs;
}

//*******************************************************************
//	countDigits
//
//  task:	       This function counts the number of digits
//	               in the string
//  data in:	   pointer that points to an array of characters
//  data returned: number of digits in the array of characters
//
//*******************************************************************

int countDigits(char *strPtr)
{
	int occurs = 0;

	while (*strPtr != '\0')
	{
		if (isdigit(*strPtr))	// isdigit determines if
			occurs++;			// the character is a digit

		strPtr++;
	}

	return occurs;
}
