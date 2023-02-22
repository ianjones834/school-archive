// Ian Jones

#include <iostream>
using namespace std;

void swap(float&, float&); //prototype of a function that will pass by reference

int main()
{
  int first,  //holds the first value
      second; //holds the second value

  cout << "This program will swap two numbers!" << endl;

  //Prompts the user for the first number
  cout << "Enter the first number, then hit enter." << endl;
  cin >> first;

  //Prompts the user for the second number
  cout << "Enter the second number, then hit enter." << endl;
  cin >> second;

  //Confirms the user inputs
  cout << "Your input numbers were " << first << " and "
       << second << "." << endl << endl;

  //Call swap() to swap the values of first and second
  swap(first, second);
  
  //Displays the swapped values to the user 
  cout << "After swapping, the first number is " << first
       << " and the second number is " << second << "." << endl;

  return 0;
}

//swap() takes in first and second by reference to swap them and 
//give them back to main()
void swap(float& first, float& second)
{
  float temp;  //temp variable to hold a value for swapping

  //swaps the values of first and second
  temp = first;
  first = second;
  second = temp;
}
