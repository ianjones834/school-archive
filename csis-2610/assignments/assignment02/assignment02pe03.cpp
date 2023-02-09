/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment02pe03: Water Bill                                       */
/*                                                                            */
/* Approximate completion time: 30 minutes                                    */
/******************************************************************************/

//This program prompts the user for their quarterly water bill, and outputs
//their average monthly water bill along with a message that reacts to
//their water usage.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
  float waterBill, //holds the user entered quarterly water bill
        total,     //accumulates the total of the water bills for the year
        average;   //holds the average monthly water bill amount
  string waterMessage; //holds the message string to display to the user

  //Formats the output for the average monthly bill
  cout << fixed << setprecision(2) << showpoint;

  //Uses the quarter counter to prompt the user, and iterate through 4
  //quarters
  for (int quarter = 1; quarter <= 4; quarter ++)
  {
    cout << "Input your waterbill for quarter " << quarter << ": ";
    cin >> waterBill;
    
    //This uses total as an accumulator for water bill
    total += waterBill;
  }
  
  //Calculates the average monthly usage
  average = total / 12;
  
  //Decides which message should be displayed to the user based on 
  //their monthly water usage
  if (average > 75.00)
    waterMessage = "an excessive";
  else if (25 <= average && average <= 75)
    waterMessage = "a typical";
  else if (average < 25)
    waterMessage = "an exceptional";

  //Displays the average water bill to the user and a message related
  //to their water usage
  cout << endl << "Your average monthly bill is $" << average << endl;
  cout << "You are using " << waterMessage << " amount of water!" << endl;

  return 0;
}
