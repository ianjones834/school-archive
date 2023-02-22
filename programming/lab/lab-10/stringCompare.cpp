#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 25;

int main()
{

  char firstName[MAX], secondName[MAX];
  int testValue;

  cout << "Please input the first name" << endl;
  cin.getline(firstName, MAX);
  cout << endl;

  cout << "Please input the second name" << endl;
  cin.getline(secondName, MAX);
  cout << endl;

  testValue = strcmp(firstName, secondName);

  cout << "The names are as follows" << endl;

  if (testValue == 0)
  {
    cout << firstName << endl << secondName << endl;
    cout << "The names are the same" << endl;
  }
  else if (testValue > 0)
    cout << secondName << endl << firstName << endl;
  else
    cout << firstName << endl << secondName << endl;

  cout << endl;

  return 0;
}

