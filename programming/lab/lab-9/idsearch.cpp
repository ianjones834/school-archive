#include <iostream>
using namespace std;

bool linearSearch(int*, int, int);

int main() 
{
  int *id = nullptr;
  int numOfId;
  int value;

  cout << "Please input the number of id numbers: ";
  cin >> numOfId;
  cout << endl;

  id = new int [numOfId];

  if (id == nullptr)
  {
    cout << "Memory Allocation Error!" << endl;
    return 1;
  }

  for (int count = 0; count < numOfId; count++)
  {
    cout << "Please enter an id number: ";
    cin >> *(id + count);
  }

  cout << endl << "Please input an id number to be searched: " << endl;
  cin >> value;
  
  if (linearSearch(id, value, numOfId))
    cout << value << " is in the array." << endl;
  else
    cout << value << " is not in the array." << endl;

  delete [] id;

  return 0;
}

bool linearSearch(int* idArray, int value, int size)
{
  int i = 0;

  while(i < size)
  {
    if (idArray[i] == value)
      return true;
    else
      i++;
  }

  return false;
}
