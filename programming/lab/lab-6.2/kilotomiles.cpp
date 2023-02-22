// Ian Jones

// This program will convert miles to kilometers
// or vice versa.

#include <iostream>
using namespace std;

float MILE = 1.61; //1 mile is 1.61 kilometers
float KILO = 0.621; //1 kilometer is 0.621 miles

float mileToKilo(float); //prototype for function from miles to kilometers
float kiloToMile(float); //prototype for function from kilometers to miles

int main()
{
  float miles;      //holds values in miles
  float kilometers; //holds values in kilometers
  int userChoice;   //holds the users starting choice

  do
  {
    //prompts the user for the type of conversion
    cout << "Please input:" << endl
         << "1. To convert miles to kilometers." << endl
         << "2. To convert kilometers to miles." << endl
         << "3. To quit." << endl;
  
    cin >> userChoice;
    cout << endl;
    
    // checks the user choice to determine what conversion should be used
    if (userChoice == 1)
    {
      //prompts the user for the miles
      cout << "Please input the miles to be converted." << endl;
      cin >> miles;
      
      //calls mileToKilo and outputs the result to the user
      kilometers = mileToKilo(miles);
      cout << miles << " miles = " << kilometers << " kilometers."
           << endl << endl;
    }
    else if (userChoice == 2)
    {
      //prompts the user for the kilometers
      cout << "Please input the kilometers to be converted." << endl;
      cin >> kilometers;

      //calls kiloToMile to convert, and outputs the resut to the user
      miles =  kiloToMile(kilometers);
      cout << kilometers << " kilometers = " << miles << " miles." 
           << endl << endl;
    }
  } while (userChoice != 3); //loops until the user enters 3
  
  return 0;
}

//function takes in miles, and outputs the value converted to kilometers
float mileToKilo(float miles)
{
  float kilos;
  
  kilos = MILE * miles;

  return kilos;
}

//function takes in kilometers, and outputs the value converted to miles
float kiloToMile(float kilos)
{
  float miles;

  miles = KILO * kilos;

  return miles;
}
