/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment01pe07: Take a Guess!                                    */
/*                                                                            */
/* Approximate completion time: 10  minutes                                   */
/******************************************************************************/

//This program will ask the user to guess a random number between 1 and 6
//then display the correct answer after enter is pressed

#include <iostream>
#include <string>  //allows strings to be used
#include <cstdlib> //allows rand and srand
#include <ctime>   //allows time to be used
using namespace std;

const int MIN_VALUE = 1; //holds the minimum value for the random range
const int MAX_VALUE = 6; //holds the maximum value for the random range

int main() 
{
  string enter; //holds the enter input
  int random;   //holds the random number

  //Prompts the user to guess a number between 1 and 6
  cout << "Think a number between 1 and 6! (Press 'enter' when you are ready)";
  cout << endl;

  //Waits for the user to enter some string to continue the program
  getline(cin, enter);

  //Generates a random number between 1 and 6
  srand(time(0));
  random = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

  //Displays the random number to the user
  cout << "The correct answer is " << random << endl;

  return 0;
}
