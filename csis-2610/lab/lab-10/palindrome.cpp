#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char *);

const int SIZE = 51;

int main()
{
  
  char palin[SIZE];

  cout << "Enter a string of at most 50 characters" << endl;
  cin.get(palin, SIZE);
  cout << endl;

  if (isPalindrome(palin))
    cout << "The string you entered is a palindrome!" << endl << endl;
  else
    cout << "The string you entered is not a palindrome." << endl << endl;

  return 0;
}

bool isPalindrome (char *str)
{
  int first = 0;
  int last = strlen(str) - 1;

  while (first < last)
  {
    if (str[first] != str[last])
      return false;

    first++;
    last--;
  }

  return true;
}
