#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct circle
{
  float centerX,
        centerY,
        radius,
        area,
        circumference,
        distance;
};

const float PI = 3.14159;

int main()
{
  circle circ[6];
  circle *biggest = circ;

  for (int count = 0; count < 6; count++)
  {
    cout << "Please enter the radius of circle " << count + 1 << ": ";
    cin >> circ[count].radius;

    cout << "Please enter the x-coordinate of the center: ";
    cin >> circ[count].centerX;

    cout << "Please enter the y-coordinate of the center: ";
    cin >> circ[count].centerY;
    
    cout << endl;

    circ[count].area = PI * pow(circ[count].radius, 2.0);
    circ[count].circumference = 2 * PI * circ[count].radius;
    circ[count].distance = sqrt(pow(circ[count].centerX, 2.0)
      + pow(circ[count].centerY, 2.0));
  }

  cout << endl << endl;

  for (int count = 0; count < 6; count++)
  {
    if (biggest -> distance < circ[count].distance)
      biggest = circ + count;
  }

  cout << "The circle that is furthest from the origin is circle "
       << (biggest - circ) + 1 << endl << endl;

  for (int count = 0; count < 6; count++)
  {
    cout << "The area of circle " << count + 1 << "is: "
         << circ[count].area << endl;

    cout <<"The circumference of circle " << count + 1 << "is: "
         << circ[count].circumference << endl << endl;
  }

  return 0;
}

