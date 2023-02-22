#include <iostream>
#include <iomanip>
using namespace std;

// This program uses a structure to hold data about a rectangle

// Ian Jones 

// Fill in code to declare a structure named rectangle which has
// members length, width, area, and perimeter all of which are floats
struct rectangle {
  float length,
        width,
        area,
        perimeter;
};

int main()
{
  rectangle box;

	cout << "Enter the length of a rectangle: ";
  cin >> box.length;

	cout << "Enter the width of a rectangle: ";
  cin >> box.width;

	cout << endl << endl;
  
  box.area = box.width * box.length;
  box.perimeter = 2 * (box.width + box.length);

	cout << fixed << showpoint << setprecision(2);

  cout << "The area of the rectangle is " << box.area << endl
       << "The perimeter of the rectangle is " << box.perimeter << endl;

	return 0;
}
