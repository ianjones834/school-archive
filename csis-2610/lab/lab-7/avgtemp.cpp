#include<iostream>
#include<iomanip>
using namespace std;

const int MAXTEMP = 50;

typedef float Temp[MAXTEMP];

void inputTemp(Temp, int&);
float avgTemp(Temp, int);
float highestTemp(Temp, int);
float lowestTemp(Temp, int);

int main()
{
  int numRows;
  Temp tempTable;
  float average,
        highest,
        lowest;

  cout << showpoint << setprecision(2) << fixed;

  inputTemp(tempTable, numRows);
  
  average = avgTemp(tempTable, numRows);
  highest = highestTemp(tempTable, numRows);
  lowest = lowestTemp(tempTable, numRows);

  cout << "The average temperature is " << average << endl;
  cout << "The highest temperature is " << highest << endl;
  cout << "The lowest temperature is " << lowest << endl;

  return 0;
}

void inputTemp(Temp table, int& rows)
{
  cout << "Please input the number of temperatures to be read (1 - 100)" << endl;
  cin >> rows;

  while(rows > MAXTEMP || rows < 1)
  {
    cout << "Please input a number between 1 and 100" << endl;
    cin >> rows;
  }
  
  for (int i = 0; i < rows; i++)
  {
    cout << "Input temperature " << i + 1 << ":" << endl;
    cin >> table[i];
    cout << endl;
  }
}

float avgTemp(Temp table, int rows)
{
  float sum = 0;
  float avg;

  for (int i = 0; i < rows; i++)
    sum += table[i];

  avg = sum / rows;

  return avg;
}

float highestTemp(Temp table, int rows)
{
  float highest = table[0];

  for (int i = 0; i < rows; i++)
    if (table[i] > highest)
      highest = table[i];

  return highest;
}

float lowestTemp(Temp table, int rows)
{
  float lowest = table[0];
  
  for (int i = 0; i < rows; i++)
    if (table[i] < lowest)
      lowest = table[i];

  return lowest;
}
