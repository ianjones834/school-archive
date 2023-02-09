// This program finds the average time spent programming by a student
// each day over a three day period.

// Ian Jones

#include <iostream>
using namespace std;

int main()
{
	int numStudents;
	float numHours, 
        totalProgramming, 
        totalBiology, 
        averageProgramming,
        averageBiology;
	int n;
  int student, day = 0;	// these are the counters for the loops

	cout << "This program will find the average number of hours a day"
		 << " that a student spent programming over a long weekend\n\n";

	cout << "How many students are there ?" << endl << endl;
	cin >> numStudents;
  cout << endl;

  cout << "How many days did the student work?" << endl;
  cin >> n;
  cout << endl;

	for (student = 1; student <= numStudents; student++)
	{
		totalProgramming = 0;
    totalBiology = 0;
		
    for (day = 1; day <= n; day++)
		{
			cout << "Please enter the number of hours worked by student " << student
           << " on Programming on day " << day << "." << endl;
			cin >> numHours;

			totalProgramming = totalProgramming + numHours;
		}

    for (day = 1; day <=n; day++)
    {
      cout << "Please enter the number of hours worked by student " << student
           << " on Biology on day " << day << "." << endl;
      cin >> numHours;

      totalBiology = totalBiology + numHours;
    }

		averageProgramming = totalProgramming / n;
    averageBiology = totalBiology / n;
		
    cout << endl;
		cout << "The average number of hours per day spent studying by "
			   << "student " << student << endl << " in Programming is " 
         << averageProgramming << " and in Biology is " << averageBiology 
         << endl << endl << endl << endl;
	}

	return 0;
}
