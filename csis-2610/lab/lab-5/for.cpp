// This program has the user input a number n and then finds the
// mean of the first n positive integers

// Ian Jones

#include <iostream>
using namespace std;

int main()
{
	int firstValue, // value is some positive number n
      lastValue,
	    total = 0,	// total holds the sum of the first n positive numbers 
	    number,		  // the amount of numbers
      count = 0;
  float mean;		  // the average of the first n positive numbers

  cout << "Please enter a positive starting integer" <<endl;
  cin >> firstValue;

	cout << "Please enter a positive ending integer" << endl;
	cin >> lastValue;
  
	if (firstValue > 0)
	{
    for (number = firstValue; number <= lastValue; number++)
			{
        total = total + number;
        count++;
      }
			
		mean = static_cast<float>(total) / count;	
 
		cout << "The mean average of the values between " << firstValue
			 << " and " << lastValue << " is " << mean << endl;
	}
	else
	{
  	cout << "Invalid input - integer must be positive" << endl;
  }

	return 0;
}
