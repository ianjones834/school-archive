#include <iostream>
using namespace std;

void printName(char *);

int main() 
{

  char last[10];

  cout << "Please enter your last name using at most 9 characters: ";
  cin.getline(last, 10);

  cout << "Your last name is ";
  printName(last);
  cout << "." << endl << endl;


  return 0;

}

void printName(char *str)
{
  while (*str)
    cout << *str++;
}
