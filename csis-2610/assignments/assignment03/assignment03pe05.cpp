/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment03pe05: Inner Product of Two Arrays                      */
/*                                                                            */
/* Approximate completion time: 10 minutes                                    */
/******************************************************************************/

//this program finds the inner product of two arrays

#include <iostream>
using namespace std;

float inner(float [], float [], int); //prototype for the inner product

const int SIZE = 4; //sets the size of the arrays

int main()
{

  float u[SIZE], //declares the u array
        v[SIZE]; //declares the v array
  
  cout << "Calculate the inner product of two arrays!" << endl << endl;

  //prompts the user to enter in elements of the u array
  for (int i = 0; i < SIZE; i++)
  {
    cout << "Enter in number " << i + 1 << " (u array): ";
    cin >> u[i];
    cout << endl;
  }

  //prompts the user to enter in elements of the v array
  for (int i = 0; i < SIZE; i++)
  {
    cout << "Enter in number " << i + 1 << " (v array): ";
    cin >> v[i];
    cout << endl;
  }

  //displays the result of the inner product to the user
  cout << "The inner product of arrays u and v is " 
       << inner(u, v, SIZE) << endl;

  return 0;
}

/******************************************************************************/
/* Function: inner                                                            */
/*                                                                            */
/* Description: calculates the inner product of two arrays                    */
/*                                                                            */
/* Data in: Two arrays, and their size                                        */
/*                                                                            */
/* Data out: the inner product of those arrays                                */
/******************************************************************************/

float inner(float u[], float v[], int size)
{
  float innerSum = 0; //initializes an accumulator to 0

  //loops through the elements of each array multiplying them and adding 
  //them to the acumulator
  for (int i = 0; i < size; i++)
    innerSum += u[i] * v[i];

  return innerSum;
}
