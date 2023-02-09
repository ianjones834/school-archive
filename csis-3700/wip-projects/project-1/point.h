#include "fraction.h"
#include <iostream>

#ifndef _POINT_H
#define _POINT_H

class Point {
	public:
		Point(Fraction _x = Fraction(0, 1), Fraction _y = Fraction(0, 1));
		~Point() = default;

		Point operator+(Point rhs);
		Point operator-(Point rhs);
		Fraction operator*(Point rhs);
		Point operator*(Fraction rhs);
		Point operator=(Point rhs);
    
		bool operator==(Point rhs);
		bool operator!=(Point rhs);

		Fraction getX() {return x;}
		Fraction getY() {return y;}

	private:
		Fraction x, y;
};

std::istream &operator>>(std::istream &is, Point &p);
std::ostream &operator<<(std::ostream &os, Point p);

#endif
