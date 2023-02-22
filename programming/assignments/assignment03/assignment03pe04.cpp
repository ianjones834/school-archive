/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment03pe04: Passing a Two-Dimensional Array                  */
/*                                                                            */
/* Approximate completion time: 10  minutes                                   */
/******************************************************************************/

//This program sums the contents of a two dimensional array by passing the 
//array as a function argument

#include <iostream>
using namespace std;

const int ROWS = 3; //Sets the maximum row size 
const int COLS = 4; //Sets the maximum column size

int sum(int [][COLS], int); //Prototype for the fucntion that sums all the
                            //elements

int main()
{
  int array[ROWS][COLS]; //declares a two dimensional array with set dimensions
  
  //Tells the user the purpose of th eprogram
  cout << "Sum the elements of a two-dimensional array!" 
       << endl; 

  //Prompts the user to enter the numbers in the array elements
  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
    {
      cout << "Enter a number to be stored in array[" << i << "][" << j
           << "]: ";
      cin >> array[i][j];
      cout << endl;
    }

  //displays their sum by calling the sum function
  cout << "Their sum is: " << sum(array, ROWS) << endl;

  return 0;
}

/******************************************************************************/
/* Function: sum                                                              */
/*                                                                            */
/* Description: sums the contents of the array                                */
/*                                                                            */
/* Data in: a two dimensional array, and it's number of rows                  */
/*                                                                            */
/* Data out: returns the sum of the elements of the array                     */
/******************************************************************************/

int sum(int array[][COLS], int rows)
{
  int sum = 0; //intializes an accumulator to 0
  
  //loops through every element and adds it to the acumulator
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < COLS; j ++)
      sum += array[i][j];

  return sum;
}
