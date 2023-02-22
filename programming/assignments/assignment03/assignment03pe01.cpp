/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment03pe01: Iterative Fibonacci                              */
/*                                                                            */
/* Approximate completion time: 40 minutes                                    */
/******************************************************************************/

//This program will calculate the user requested nth fibonacci number.

#include <iostream>
using namespace std;

int fibonacci(int); //Prototype for fibonacci function
void menu(); //Prototype for the menu function

int main()
{
  int startChoice = 0; //defaults the user start choice to 0
  int userNum; //holds the value to be passed to the fibonacci function

  cout << "Calculate the nth Fibonacci number!" << endl << endl;

  //Runs the program while the user does not choose to exit
  while (startChoice != 2)
  {
    //displays the menu, and prompts the user for a choice
    menu();
    cin >> startChoice;
    
    //Uses a switch statement to determine the outcome of the user's choice
    switch (startChoice)
    {
      //case 1 is the case where a fibonacci number is computed
      case 1: 

        //prompts the user to enter an integer number
        cout << "Enter n: ";
        cin >> userNum;
        cout << endl;
        
        //validates the number is a positve integer. Reprompts the user if it
        //they enter a negative integer
        while (userNum <= 0)
        {
          cout << "n should be a positive integer (n >= 1). Please try again."
               << endl;
          cout << "Enter n: ";
          cin >> userNum;
          cout << endl;
        }

        //displays the result to the user using the fibonacci function
        cout << "fibonacci(" << userNum << ") = " << fibonacci(userNum)
             << endl;
        break;
      
      //case two displays an exit message to the user
      case 2:
        cout << "Thank you!" << endl;
        break;

      //the default tells the user their selection was invalid (i.e. not 1 or 2)
      //and asks them to try again
      default:
        cout << "Invalid choice. Please try again" << endl << endl;
    }
  }
}

/******************************************************************************/
/* Function: menu                                                             */
/*                                                                            */
/* Description: This function displays the user menu                          */
/*                                                                            */
/* Data in: none                                                              */
/*                                                                            */
/* Data out: void                                                             */
/******************************************************************************/

void menu()
{
  //Displays user menu
  cout << "1. Calculuate Fibonacci" << endl << "2. Exit" << endl
       << "(Enter 1 or 2)" << endl << endl;
}

/******************************************************************************/
/* Function: fibonacci                                                        */
/*                                                                            */
/* Description: This function calculates an nth fibonacci number              */
/*                                                                            */
/* Data in: Takes in an integer n                                             */
/*                                                                            */
/* Data out: Returns the nth fibonacci number                                 */
/******************************************************************************/

int fibonacci(int n)
{
  int lastNum = 1; //holds the last number in the sequence
  int currentNum = 1; //holds the current number of the sequence
  int nextNum; //holds the next number of the sequence

  //loops until the nth fibonacci is found. It only loops until n-2 because
  //currentNum by default is assigned to the second fibonacci number. 
  for (int count = 1; count <= (n - 2); count++)
  {
    //calculates the next number by adding the last two, and then reassigns
    //the values so that the next iteration will give the next number
    nextNum = currentNum + lastNum;
    lastNum = currentNum;
    currentNum = nextNum;  
  }
  
  //currentNum is returned giving the nth fibonacci
  return currentNum;
}
