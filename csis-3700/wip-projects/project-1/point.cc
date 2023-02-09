#include "point.h"

Point::Point(Fraction _x, Fraction _y) {
	x = _x;
	y = _y;
}

Point Point::operator+(Point rhs) {
	Fraction s, t;

	s = x + rhs.x;
	t = y + rhs.y;

	return Point(s, t);
}

Point Point::operator-(Point rhs) {
	Fraction s, t;

	s = x - rhs.x;
	t = y - rhs.y;

	return Point(s, t);
}

Fraction Point::operator*(Point rhs) {
	return (x * rhs.y) - (y * rhs.x);
}

Point Point::operator*(Fraction rhs) {
	Fraction s, t;

	s = x * rhs;
	t = y * rhs;

	return Point(s ,t);
}

Point Point::operator=(Point rhs) {
	x = rhs.x;
	y = rhs.y;

	return *this;
}

bool Point::operator==(Point rhs) {
	return x == rhs.x && y == rhs.y;
}

bool Point::operator!=(Point rhs) {
	return x != rhs.x || y != rhs.y;
}

std::istream &operator>>(std::istream &is, Point &p) {
	Fraction s, t;
	char ch;

	is >> ch >> s >> ch >> t >> ch;
	p = Point(s, t);

	return is;
}

std::ostream &operator<<(std::ostream &os, Point p) {
	os << "(" << p.getX() << "," << p.getY() << ")";

	return os;
}
