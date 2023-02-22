/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment01pe03: The cin Object                                   */
/*                                                                            */
/* Approximate completion time: 5 minutes                                     */
/******************************************************************************/

//This is a program that will read an integer from the terminal and display it

#include <iostream>
using namespace std;

int main() 
{
  int value; //Holds the value to display

  //Prompts the user to input the value
  cout << "Input an Integer value" << endl;

  //Takes a value from the terminal and displays it 
  cin >> value;
  cout << endl << "The value is " << value << endl;

  return 0;
}
