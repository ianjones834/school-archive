/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment02pe02: Persistence of a Number                          */
/*                                                                            */
/* Approximate completion time: 30 minutes                                    */
/******************************************************************************/

//This program will find the persistence of a user given positive integer,
//and run until a sentinel value of -1 is entered.

#include <iostream>
using namespace std;

int main()
{
  int userNumber,     //holds the number given by the user
      currentNumber,  //holds the number that is being manipulated
      digitProduct,   //holds the product of the digits of the current number
      persistence;    //holds the persistence of the requested number

  //Prompts the user to enter an integer number
  cout << "Enter a positive integer to calculate its persistence "
       << "(-1 to stop): ";
  cin >> userNumber;
  cout << endl;
  
  //Continually runs the program until the sentinel value -1 is entered
  while (userNumber != -1)
  { 
    //Resets the currentNumber and persistence after each iteration
    currentNumber = userNumber;
    persistence = 0;

    //Loop that increments the persistence for each number larger than 1 digit
    while (currentNumber > 9)
    { 
      //Resets digitProduct to 1 after each interation to find the next number
      digitProduct = 1;

      //Finds the next digitProduct of each number in the loop
      while (currentNumber > 0)
      {
        digitProduct = digitProduct * (currentNumber % 10);
        currentNumber /= 10;
      }

      //sets the current number to the digitProduct for 
      //the check and the next iteration
      //Increments persistence each iteration
      currentNumber = digitProduct;
      persistence++; 
    }

    //Displays the persistence to the user
    cout << "Persistence(" << userNumber << ") = " << persistence 
         << endl << endl;

    //Reprompts the user to find a new persistence
    cout << "Enter a number to calculate its persistence (-1 to stop): ";
    cin >> userNumber;
    cout << endl;
  }

  return 0;
} 
