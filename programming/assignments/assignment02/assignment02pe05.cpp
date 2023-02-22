/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment02pe05: Reading from a File and Writing to Another File  */
/*                                                                            */
/* Approximate completion time: 15 minutes                                    */
/******************************************************************************/

//This program opens a file containing integers to sum them and display the
//integers and the sum to the user. It also saves the output to an output file
//specified by the user.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
  int fileNumber,    //holds the integer values from the file
      sum = 0;       //accumulates the sum of the integers
  string fileName;   //holds the user's file name
  ifstream inFile;   //declares the input object to extract the integers
  ofstream outFile;  //declares the output object to save to a file

   //Explains to the user the purpose of the program
  cout << "This program reads integers from a file," << endl
       << "calculates their sum, and saves the sum" << endl
       << "in another file." << endl << endl; 

  //Opens the file for extraction
  inFile.open("testdata5");

  //Tests if the file successfully opened
  if(inFile)
  {
    //Displays a message for the integers in the file to the user
    cout << "The integers read are: ";

    //Interates over every number in the file by evaluating the expression
    //then checking whether it is successful returns a true to iterate
    while(inFile >> fileNumber)
    { 
      //Uses the evaluated expression in the check to display the input 
      //then uses an accumulator to sum the numbers
      cout << fileNumber <<  " ";
      sum += fileNumber;
    }
    
    //Displays the final sum to the user
    cout << endl; 
    cout << "Their sum is " << sum << endl << endl;
    
    //Prompts the user to enter a file name that the sum will be saved to
    cout << "Enter a file name to write the sum to: ";
    cin >> fileName;
    cout << endl;

    //Creates and opens a file that has the user given file name
    outFile.open(fileName);
  
    //Sends the sum to the outFile, and checks if this process is successful.
    if(outFile << sum)
    {
      cout << "The sum " << sum << " was saved successfully to file " 
           << fileName << "." << endl;
    }
    else
    {
      cout << "There was an error saving to the file.";
    }
  }
  else
  {
    cout << "File failed to open!" << endl;
  }

  //Closes the inFile and outFile
  inFile.close();
  outFile.close();
  
  return 0;
} 
