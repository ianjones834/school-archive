//This is program will output the distance the an object falls
//using a user inputted maximum height and a time

//Ian Jones

#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
  const float GRAVITY = 9.8;

  int userTime,
      userHeight,
      time;
  float distance;

  cout << fixed << setprecision(1) << showpoint;

  cout << "Please input the time of fall in seconds:" << endl;
  cin >> userTime;
  cout << endl;

  cout << "Please input the height of the bridge in meters:" << endl;
  cin >> userHeight;
  cout << endl;

  cout << "Time Falling (seconds) Distance Fallen (meters)" << endl
       << setfill('*') << setw(48) << " " << endl;

  cout << setfill(' ') << left;

  for (time = 0; time <= userTime; time++)
  {
    distance = .5 * GRAVITY * time * time;
    cout << setw(23) << time << distance << endl;
  }

  if (distance > userHeight)
    cout << "Warning-Bad Data: The distance fallen exceeds the height of the bridge" << endl;

  return 0;
}

