/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment01pe04: Sum of Two Values                                */
/*                                                                            */
/* Approximate completion time: 3 minutes                                     */
/******************************************************************************/  

//This program will sum two integer values from the terminal and display the sum

#include <iostream>
using namespace std;

int main() 
{
  int value1, //holds values 1
      value2, //holds value 2
      sum;    //holds the sum of value 1 and 2

  //Prompts the user to input value 1 and 2
  cout << "Input two integers" << endl;
  cin >> value1 >> value2;

  //sums value 1 and 2
  sum = value1 + value2;

  //Displays the sum to the user  
  cout << endl << "The sum is " << sum << endl;

  return 0;
}

