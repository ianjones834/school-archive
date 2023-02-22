/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment01pe06: Using the sqrt Function                          */
/*                                                                            */
/* Approximate completion time: 5 minutes                                     */
/******************************************************************************/

//This is a program that takes a floating point number
//and displays the square root

#include <iostream>
#include <iomanip> //allows formatting of output
#include <cmath>   //allows square root function
using namespace std;

int main()
{
  float value1,     //holds value 1
        squareRoot; //holds the square root of value 1
  
  //Formats the output of the square root
  cout << setprecision(2) << fixed << showpoint; 
    
  //Prompts the user to input value 1
  cout << "Input any number" << endl;
  cin >> value1;
  cout << endl;

  //Calculates the sqaure root of value 1
  squareRoot = sqrt(value1);

  //Displays the square root of the value to the user
  cout << "The square root of the value is " << squareRoot << endl;

  return 0;
}
