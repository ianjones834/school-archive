#include <fstream> 
#include <iostream>
#include <iomanip>
using namespace std;

// This program reads records from a file. The file contains the
// following: student’s name, two test grades and final exam grade.
// It then prints this information to the screen.

// Ian Jones

const int NAMESIZE = 15;
const int MAXRECORDS = 50;

struct Grades	// declares a structure
{
	char name[NAMESIZE + 1];
	int test1;
	int test2;
	int final;
  char letter;
};

typedef Grades gradeType[MAXRECORDS];
// This makes gradeType a data type
// that holds MAXRECORDS
// Grades structures.

// FIll IN THE CODE FOR THE PROTOTYPE OF THE FUNCTION ReadIt
// WHERE THE FIRST ARGUMENT IS AN INPUT FILE, THE SECOND IS THE
// ARRAY OF RECORDS, AND THE THIRD WILL HOLD THE NUMBER OF RECORDS
// CURRENTLY IN THE ARRAY.
void readIt(ifstream&, gradeType, int&);

int main()
{
	ifstream indata;

	indata.open("graderoll.dat");

	int numRecord;	// number of records read in 

	gradeType studentRecord;

	if (!indata)
	{
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;

		return 1;
	}

	// FILL IN THE CODE TO CALL THE FUNCTION ReadIt.
  readIt(indata, studentRecord, numRecord); 

	// output the information
	for (int count = 0; count < numRecord; count++)
	{
		cout << studentRecord[count].name << setw(10)
			 << studentRecord[count].test1
			 << setw(10) << studentRecord[count].test2;
		cout << setw(10) << studentRecord[count].final
         << setw(10) << studentRecord[count].letter << endl;
	}

  indata.close();

	return 0;
}

//**************************************************************
//	readIt
//
//	task:	  This procedure reads records into an array of
//	          records from an input file and keeps track of the
//	          total number of records
//	data in:  data file containing information to be placed in
//	          the array
//	data out: an array of records and the number of records
//
//**************************************************************

void readIt(ifstream& inData, gradeType gradeRec, int& total)
{
	total = 0;
  float average = 0;

	inData.get(gradeRec[total].name, NAMESIZE);

	while (inData)
	{
		// FILL IN THE CODE TO READ test1
    inData >> gradeRec[total].test1;

		// FILL IN THE CODE TO READ test2
    inData >> gradeRec[total].test2;

		// FILL IN THE CODE TO READ final
    inData >> gradeRec[total].final;

    average = ((gradeRec[total].test1 + gradeRec[total].test2) * .3) +
              (gradeRec[total].final * .4);

    if (average >= 90)
      gradeRec[total].letter = 'A';
    else if (average < 90 && average >= 80)
      gradeRec[total].letter ='B';
    else if (average < 80 && average >= 70)
      gradeRec[total].letter = 'C';
    else if (average < 70 && average >= 60)
      gradeRec[total].letter ='D';
    else
      gradeRec[total].letter ='F';

		total++;	// add one to total

		// FILL IN THE CODE TO CONSUME THE END OF LINE
    inData.ignore(80, '\n');

		// FILL IN THE CODE TO READ name
    inData.get(gradeRec[total].name, NAMESIZE);
	}

}
