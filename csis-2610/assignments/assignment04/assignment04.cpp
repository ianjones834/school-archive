/******************************************************************************/
/* Skeleton provided by S. Bassil (Spring 2022)                               */
/*                                                                            */
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program: assignment04                                                      */
/*                                                                            */
/* Approximate Completion Time: 3 hrs                                         */
/******************************************************************************/

/*
   This program populates an array with 5 integers, search for a specific
   integer using linear search algorithm or binary search algorithm.
   This program also sorts the array in ascending or descending order
   using bubble sorting algorithm or selection sorting algorithm.
   At any time, the user can print out the integers in the array.
*/

#include <iostream>
using namespace std;

/* functions prototypes */
int linearSearch(int array[], int size, int value);
int binarySearch(int array[], int size, int value);
void bubbleAscendingSort(int array[], int size);
void bubbleDescendingSort(int array[], int size);
void selectionAscendingSort(int array[], int size);
void selectionDescendingSort(int array[], int size);
void menu();
void swap(int &valueOne, int &valueTwo);


int main()
{
  const int size = 5;  //holds size of array
  int menuChoice;      //holds user choice
  int userArray[size]; //holds the user's array
  int searchValue;     //value that is being searched for
  int searchPosition;  //position of searched value
  bool flag = false;   //flag that allows binary search
  
  cout << "Welcome, Search and Sort your Array!" << endl << endl;
  
  //prompts user to input array
  cout << "Input five integers seperated by spaces: "; 

  for (int i = 0; i < size; i++)
    cin >> userArray[i];
  
  //prompts user for their menu decision
  cout << "What would you like to do?" << endl << endl;

  //runs until the quit option is chosen
  while (menuChoice != 8)
  {     
    //displays the menu
    menu();
      
    //prompts user for a menu choice
    cout << "Enter 1, 2, 3, 4, 5, 6, 7, or 8: ";
    cin >> menuChoice;
    cout << endl;
    
    //validates the menu choice value is on a range from 1 to 8
    //and it reprompts the user for a valid choice
    while (menuChoice < 1 || menuChoice > 8)
    {
      cout << "Invalid choice. Please input 1, 2, 3, 4, 5, 6, 7 or 8: ";
      cin >> menuChoice;
      cout << endl;
    }
    
    //decides the action based on the user decision
    switch (menuChoice)
    {
      case 1:
        //prompts the user for a search value
        cout << "Enter the value to search for: ";
        cin >> searchValue;
        cout << endl;
        
        //finds the value position using linear search
        searchPosition = linearSearch(userArray, size, searchValue);
          
        //displays the position to the user or displays a message that the
        //value is not in the array
        if(searchPosition == -1)
          cout << "The integer you're looking for is not in the array"
               << endl << endl;
        else
          cout << "The integer " << searchValue << " is in position "
               << searchPosition << "." << endl << endl;          
        break;

      case 2:
        //checks the ascending flag to allow a binary search
        if (flag)
        {  
          cout << "Enter the value to search for: ";
          cin >> searchValue;
          cout << endl;
          
          //finds the value position using binary search
          searchPosition = binarySearch(userArray, size, searchValue);
          
          //displays the position to the user or a message that the value is
          //not in the array
          if (searchPosition == -1)
            cout << "The integer you're looking for is not in the array"
                 << endl << endl;
          else
            cout << "The integer " << searchValue << " is in position "
                 << searchPosition << "." << endl << endl; 
        }   
        else
          cout << "The Array is not sorted in ascending order. "
               << "Binary Search cannot be used." << endl << endl; 
        break;

      case 3:
        //sorts the array in ascending order, and sets the flag
        //to true for binary search
        flag = true;
        bubbleAscendingSort(userArray, size);
        cout << "The Ascending Bubble Sort is done" << endl << endl;
        break;

      case 4: 
        //sorts the array in descending order, and sets the flag
        //to false for binary search
        flag = false;
        bubbleDescendingSort(userArray, size);
        cout << "The Descending Bubble Sort is done" << endl << endl;
        break;

      case 5: 
        flag = true;
        selectionAscendingSort(userArray, size);
        cout << "The Ascending Selection Sort is done" << endl << endl;
        break;

      case 6: 
        flag = false;
        selectionDescendingSort(userArray, size);
        cout << "The Descending Selection Sort is done" << endl << endl;
        break;

      case 7: 
        cout << "The array is" << endl;
        
        //loops through the array to display it
        for (int i = 0; i < size; i++)
          cout << userArray[i] << " ";
        cout << endl << endl;
        break;

      case 8: 
        cout << "Thank you for your time!" << endl << endl;
    }
  }

	return 0;
}

/******************************************************************************/
/* Function: linearSearch                                                     */
/*                                                                            */
/* Description: uses linear search to find an integer in the array            */
/*                                                                            */
/* Data in: array of integers, size of the array, the integer searching for   */
/*                                                                            */
/* Data out: position of the integer searching for if found, -1 otherwise     */
/******************************************************************************/

int linearSearch(int array[], int size, int value)
{ 
  //increments through each element in the array, and returns the position
  //if the value is found
  for (int i = 0; i < size; i++)
    if (array[i] == value)
      return i;

  return -1;
}

/******************************************************************************/
/* Function: binarySearch                                                     */
/*                                                                            */
/* Description: uses binary search to find an integer in the array            */
/*                                                                            */
/* Data in: array of integers, size of the array, the integer searching for   */
/*                                                                            */
/* Data out: position of the integer searching for if found, -1 otherwise     */
/******************************************************************************/

int binarySearch(int array[], int size, int value)
{
  int first = 0,        //holds the first index value
      last = size - 1,  //holds the last index value
      middle;           //holds the index value between the first and last
  
  //loops while the first index is less than the last index
  while (first <= last)
  {
    //calculates the next middle index
    middle = (first + last) / 2;
    
    //gets rid of the top half of the array if the middle value
    //is greater than the search value
    if (array[middle] > value)
      last = middle - 1;

    //gets rid of the bottom half of the array if the middle
    //value is less than the search value   
    else if (array[middle] < value)
      first = middle + 1;
    
    //returns the middle index. If the value is not less than and not greater
    //than it must be equal to the search value
    else
      return middle;
  }

  return -1;
}

/******************************************************************************/
/* Function: bubbleAscendingSort                                              */
/*                                                                            */
/* Description: sorts an array in ascending order using bubble sort           */
/*                                                                            */
/* Data in: array of integers, size of the array                              */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void bubbleAscendingSort(int array[], int size)
{
  //loops through the array mutliple times, and moves the biggest value
  //each time to the end
  for (int maxValue = size - 1; maxValue > 0; maxValue--)
    for (int i = 0; i < maxValue; i++)
      if (array[i] > array[i + 1])
        swap(array[i], array[i + 1]);
}

/******************************************************************************/
/* Function: bubbleDescendingSort                                             */
/*                                                                            */
/* Description: sorts an array in descending order using bubble sort          */
/*                                                                            */
/* Data in: array of integers, size of the array                              */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void bubbleDescendingSort(int array[], int size)
{
  //moves the smallest value in each loop to the end
  for (int minValue = size - 1; minValue > 0; minValue--)
    for (int i = 0; i < minValue; i++)
      if (array[i] < array[i + 1])
        swap(array[i], array[i + 1]);
}

/******************************************************************************/
/* Function: selectionAscendingSort                                           */
/*                                                                            */
/* Description: sorts an array in ascending order using selection sort        */
/*                                                                            */
/* Data in: array of integers, size of the array                              */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void selectionAscendingSort(int array[], int size)
{
	int index,
      minValue;
  
  //loops through every position of the array    
  for (int i = 0; i < (size - 1); i++)
  {
    //sets the current index to the next one that will be swapped
    index = i;
    minValue = array[i];
    
    //seraches the array for the smallest value  
    for (int j = i + 1; j < size; j++)
    {
      if (array[j] < minValue)
      {
        minValue = array[j];
        index = j;
      }
    }
    
    //swaps the current value with the smalllest value in the array
    swap(array[i], array[index]);
  }
}

/******************************************************************************/
/* Function: selectionDescendingSort                                          */
/*                                                                            */
/* Description: sorts an array in descending order using selection sort       */
/*                                                                            */
/* Data in: array of integers, size of the array                              */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void selectionDescendingSort(int array[], int size)
{	
  int index,
      maxValue;
      
  for (int i = 0; i < (size - 1); i++)
  { 
    //sets the current index to the one that will be swapped
    index = i;
    maxValue = array[i];
         
    //searches through the rest of the array for the biggest value 
    for (int j = i + 1; j < size; j++)
    {
      if (array[j] > maxValue)
      {
        maxValue = array[j];
        index = j;
      }
    }
    
    //swaps biggest value, and the value of the current index    
    swap(array[i], array[index]);
  }
}

/******************************************************************************/
/* Function: menu                                                             */
/*                                                                            */
/* Description: displays all the menu options to the user                     */
/*                                                                            */
/* Data in: none                                                              */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void menu()
{
  //displays menu
  cout << "1 - Find integer in array using Linear Search" << endl
       << "2 - Find integer in array using Binary Search" << endl
       << "3 - Sort integers in ascending order using Bubble Sort" << endl
       << "4 - Sort integers in descending order using Bubble Sort" << endl
       << "5 - Sort integers in ascending order using Selection Sort" << endl
       << "6 - Sort integers in descending order using Selection Sort" << endl
       << "7 - Print out integers in Array" << endl
       << "8 - Quit" << endl;
}

/******************************************************************************/
/* Function: swap                                                             */
/*                                                                            */
/* Description: swaps the values given                                        */
/*                                                                            */
/* Data in: integer value, and second integer value                           */
/*                                                                            */
/* Data out: the two values with positions swapped in memory                  */
/******************************************************************************/

void swap(int &valueOne, int &valueTwo)
{
  //uses temp variable to swap values
  int temp = valueOne;
  valueOne = valueTwo;
  valueTwo = temp;
}
