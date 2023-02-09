/******************************************************************************/
/* Programmer: Ian Jones                                                      */
/*                                                                            */
/* Program assignment02pe04: Reading from a File                              */
/*                                                                            */
/* Approximate completion time: 24 minutes                                    */
/******************************************************************************/

//This program takes a single integer from a file, and displays it to the user.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int fileNumber;  //holds the integer from the file
  ifstream inFile; //creates an object for extracting from a file
  
  //Opens testdata4 for extraction
  inFile.open("testdata4");
  
  //Tests if the file successfully opens, and prompts the user if it fails
  if (inFile)
  {
    //Extracts the number, and displays it to the terminal
    inFile >> fileNumber;
    cout << "The value in the file is " << fileNumber << endl;
  }
  else
    cout << "File failed to open!" << endl;

  //Closes the file
  inFile.close();

  return 0;
}
