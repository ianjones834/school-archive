/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment03pe02: Call by Reference                                */
/*                                                                            */
/* Approximate completion time: 15 minutes                                    */
/******************************************************************************/

//This program takes in two values from the user and swaps them

#include <iostream>
using namespace std;

void swap(int &, int &); //prototype for the swap function

int main()
{
  int valueOne, //holds the first entered value
      valueTwo; //holds the second enetered value
  
  cout << "This program will swap two values!" << endl << endl;

  //prompts the user to enter the first value
  cout << "Please input the first value, x: ";
  cin >> valueOne;
  cout << endl;

  //prompts the user to enter the second value
  cout << "Please input the second value, y: ";
  cin >> valueTwo;
  cout << endl;

  //calls the swap function
  swap(valueOne, valueTwo);

  //displays the results of the swap function to the user
  cout << "After the swap, x is equal to " << valueOne
       << " and y is equal to " << valueTwo << endl;

  return 0;
}

/******************************************************************************/
/* Function: swap                                                             */
/*                                                                            */
/* Description: This function takes in two values by reference and swaps      */
/*              them between the variables.                                   */
/*                                                                            */
/* Data in: two user entered integer values                                   */
/*                                                                            */
/* Data out: void, and the function changed the variables by reference        */
/******************************************************************************/

void swap(int &first, int &second)
{ 
  //swaps using three variables
  int temp = first;
  first = second;
  second = temp;
}
