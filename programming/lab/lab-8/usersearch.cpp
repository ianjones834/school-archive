// Ian Jones

#include <iostream>
#include <iomanip>
using namespace std;

void displayArray(int [], int);
void arraySort(int [], int);
int arraySearch(int [], int, int);
float arrayMean(int [], int);

const int SIZE = 50;

int main()
{
  int size,
      num,
      location;

  int array[SIZE];

  cout << fixed << showpoint << setprecision(2);

  cout << "Input the number of integer elements in the array: ";
  cin >> size;

  while (size < 1 || size > 50)
  {
    cout << "Invalid input. Size must be a positive integer less than 50" 
         << endl;
    cout << "Please try again: ";
    cin >> size;
  }

  cout << endl << "For an array of size " << size << endl;

  for (int count = 0; count < size; count++)
  {
    cout << "Input integer " << count + 1 << ": ";
    cin >> array[count];
  }

  cout << endl;
  
  cout << "The array you entered is:" << endl;
  displayArray(array, size);

  arraySort(array, size);

  cout << "The array after being sorted is:" << endl;
  displayArray(array, size);

  cout << "Enter the integer you would like to search for: ";
  cin >> num;
  cout << endl;

  location = arraySearch(array, size, num);

  if (location == -1)
    cout << "The integer " << num << " could not be found in the array.";
  else
    cout << "The integer " << num << " is in location " << location + 1 << ".";

  cout << endl << endl;

  cout << "The mean of the array is " << arrayMean(array, size) << "." 
       << endl;


  return 0;
}

void displayArray(int array[], int size)
{
  for (int count = 0; count < size; count++)
    cout << array[count] << " ";

  cout << endl << endl;
}

void arraySort(int array[], int size)
{
  int count,
      minLocation,
      minValue;

  for (count = 0; count < (size - 1); count ++)
  {
    minLocation = count;
    minValue = array[count];
    
    for(int i = count + 1; i < size; i++)
    {
      if (array[i] < minValue)
      {
        minValue = array[i];
        minLocation = i;
      }
    }

    array[minLocation] = array[count];
    array[count] = minValue;
  }
}

int arraySearch(int array[], int size, int value)
{
  int first = 0,
      last = size - 1,
      middle;
      
  while (first <= last)
  {
    middle = (first + last) / 2;
  
    if ( array[middle] == value )
      return middle;
    else if ( array[middle] > value )
      last = middle -1;
    else
      first = middle + 1;
  }

  return -1;
}

float arrayMean(int array[], int size)
{
  int sum = 0;

  for (int count = 0; count < size; count++)
    sum += array[count];
  
  return (static_cast<float>(sum) / size);
}
