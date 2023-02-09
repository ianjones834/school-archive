/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment03pe03: Reverse                                          */
/*                                                                            */
/* Approximate completion time: 15 minutes                                    */
/******************************************************************************/

//This program displays the contents of array in reverse order from what
//they were entered as.

#include<iostream>
using namespace std;

const int SIZE = 10; //sets the maximum size of the array

int main()
{
  int userArray[SIZE]; //creates the array with the maximum size
 
  //explains the purpose of the program to the user
  cout << "Input ten integers, and this program will print them in reserve "
       << "order" << endl;
  
  //prompts the user to enter each number
  for (int i = 0; i < SIZE; i++)
  {
    cout << "Enter number " << i + 1 << ": ";
    cin >> userArray[i];
  }
  
  //displays an output message
  cout << endl << "In reverse order, the numbers you entered are: ";
   
  //displays the elements of the array in reverse order
  for (int i = 9; i > -1; i--)
  {
    cout <<userArray[i] << " ";
  }
  
  cout << endl;
    
  return 0;
}
