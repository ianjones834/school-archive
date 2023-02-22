/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment02pe01: Unfilled Box                                     */
/*                                                                            */
/* Approximate completion time: 24 minutes                                    */
/******************************************************************************/

//This program creates a box of asterisks by user specification, and validates
//the user input to be within a certain range of values 1-20.

#include <iostream>
using namespace std;

int main()
{
  int length, height;  //holds values for length and height
  
  //Prompts user for the length and the height
  cout << "Enter in a length (must be less than 21): ";
  cin >> length;

  cout << "Enter in a height (must be less than 21): ";
  cin >> height;

  //Validates the length and height to be within the range 1-20
  while ((length < 1 || length > 20) || (height < 1 || height > 20))
  {
    cout << "Invalid input. Your values must be positive, and less than 21."
         << endl << "Try again!" << endl;

    cout << "Enter in a length (must be less than 21): ";
    cin >> length;

    cout << "Enter in a height (must be less than 21): ";
    cin >> height;
  } 

  cout << endl;

  //Uses countLength to display the specified length of asterisks
  for (int countLength = 1; countLength <= length; countLength++)
    cout << "*"; 

  //Uses countHieght create the heights line by line,
  //height-2 takes into consideration the top and bottom lines
  for (int countHeight = 1; countHeight <= (height-2); countHeight++)
  {
    cout << endl << "*";
    
    //Uses countLength to input the indicated number of spaces per line
    //Uses length-2 to take into consideration the end asterisks
    for(int countLength = 1; countLength <= (length-2); countLength++)
      cout << " ";
    
    //This prevents extra asterisks from being displayed if length is 1
    if (length > 1)
      cout << "*";
  }
  
  //If the height is 1 this check avoids printing an extra line
  if (height > 1)
  {
    cout << endl;

    //Uses countLength to print the last line of asterisks
    for (int countLength = 1; countLength <= length; countLength++)
      cout << "*";
  }

  cout << endl << endl;

  return 0;
}
