// A simple program to calculate 
// the predetermined area of a rectangle.

// Ian Jones

#include <iostream>
using namespace std;

const int LENGTH = 8;
const int WIDTH = 3;

int main() {
	int perimeter;
	int area;

	perimeter = LENGTH * 2 + WIDTH * 2;
	area = LENGTH * WIDTH;

	cout << "The area of the rectangle is " << area << "." << endl;
	cout << "The perimeter of the rectangle is " << perimeter << "." << endl;
}	
