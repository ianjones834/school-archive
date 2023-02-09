// This program prints "You Pass" if a student's average is
// // 60 or higher and prints "You Fail" otherwise

// Ian Jones

#include <iostream>
using namespace std;

int main()
{
  float average;  // holds the grade average

  cout << "Input your average:" << endl;
  cin >> average;

  if (average > 100)
    cout << "Invalid Data" <<endl;

  if (average >= 90 && average <= 100)
    cout << 'A' << endl;

  else if (average >= 80 && average <= 89)
    cout << 'B' << endl;
  
  else if (average >= 60 && average <= 79)
    cout << "You Pass" << endl;

  else if (average >= 0 && average <= 59)
    cout << "You Fail" << endl;

  return 0;
}
