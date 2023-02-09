// This is a program that will average 3 grades

// Ian Jones

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  float firstGrade, secondGrade, thirdGrade;
  float average;
  
  cout << setprecision(2) << fixed << showpoint;

  // Prompts to input the first grade
  cout << "Please input the first grade" << endl;
  cin >> firstGrade;
  cout << endl;

  // Prompts to input the second grade
  cout << "Please input the second grade" << endl;
  cin >> secondGrade;
  cout <<endl;

  // Prompts to input the third grade
  cout << "Please input the third grade" << endl;
  cin >> thirdGrade;
  cout << endl;

  // Assigns the average
  average = (firstGrade + secondGrade + thirdGrade) / 3;

  // Outputs the average to the user
  cout << "The average of the three grades is " << average << endl;

  return 0;
}
