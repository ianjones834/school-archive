/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment01pe05: Average of Four Integers                         */
/*                                                                            */
/* Approximate completion time: 7 minutes                                     */
/******************************************************************************/

// This program will take the average of four integers and display it
// to the user

#include <iostream>
using namespace std;

int main()
{
  int value1, //holds value 1
      value2, //holds value 2
      value3, //holds value 3
      value4; //holds value 4
      
  float average; //holds the calculated average

  //Prompts the user to input four integers
  cout << "Input four integers" << endl;
  cin >> value1 >> value2 >> value3 >> value4;

  //Calculates the average of the four inputs
  average = (static_cast<float>(value1) + value2 + value3 + value4)/4;

  //Outputs the average to the user
  cout << "The average of the values is " << average << endl;

  return 0;
}
