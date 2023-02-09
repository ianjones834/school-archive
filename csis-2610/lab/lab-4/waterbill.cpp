// This program will calculate the average water spending for a year

// Ian Jones

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
  float quarter1, //holds quarter 1 bill
        quarter2, //holds quarter 2 bill
        quarter3, //holds quarter 3 bill
        quarter4, //holds quarter 4 bill
        average;  //holds calculated average
  
  string waterUsage; //holds the water usage messsage
   
  //Formats the display for the average bill
  cout << setprecision(2) << fixed << showpoint;

  //Prompts the user for quarter 1 bill
  cout << "Please input your water bill for quarter 1:" << endl;
  cin >> quarter1;

  //Prompts the user for quarter 2 bill
  cout << "Please input your water bill for quarter 2:" << endl;
  cin >> quarter2;

  //Prompts the user for quarter 3 bill
  cout << "Please input your water bill for quarter 3:" << endl;
  cin >> quarter3;

  //Prompts the user for quarter 4 bill
  cout << "Please input your water bill for quarter 4:" << endl;
  cin >> quarter4;

  //Calculates the monthly average of the 4 bills
  average = (quarter1 + quarter2 + quarter3 + quarter4) / 12;

  //Uses the average to assign a water usage message to the user
  if (average > 75.00)
    waterUsage = "excessive";
 
  else if (average >= 25.00 && average <= 75.00)
    waterUsage = "typical";
 
  else if (average < 25.00)
    waterUsage = "amazingly little";

  //Displays the average and the water usage message to the user
  cout << "Your average monthly bill is $" << average
       << ". You are using " << waterUsage << " amounts of water." << endl;
  
  return 0;
}
