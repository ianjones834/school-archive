#include "point.h"

Fraction polygonArea(Point q[], int k);
bool isIntersect(Point p1, Point p2, Point q1, Point q2, Point &x);
bool isInsidePolygon(Point p, Point c, Point q[], int k);

int main() {
	int numPolygons,
			numHits,
			numVerticies[100];

	Point board,
				hit,
				polygon[100][21];

	std::cin >> board >> numPolygons;

	Fraction boardArea = board.getX() * board.getY(),
					 score(0,1);

	for (int i = 0; i < numPolygons; i++) {
		std::cin >> numVerticies[i];

		for (int j = 0; j < numVerticies[i]; j++) {
			std::cin >> polygon[i][j];
		}

		polygon[i][numVerticies[i]] = polygon[i][0];
	}

	std::cin >> numHits;

	for (int i = 0; i < numHits; i++) {
		std::cin >> hit;

		for (int j = 0; j < numPolygons; j++) {

			if (isInsidePolygon(hit, board, polygon[j], numVerticies[j])) {
				score = score + (boardArea / polygonArea(polygon[j], numVerticies[j]));
				numVerticies[j] = 0;
			}
		}
	}

	std::cout << "Score: " << score << std::endl;

	return 0;
}

Fraction polygonArea(Point polygon[], int numVerticies) {
	Fraction sum(0,1);

	for (int i = 1; i < numVerticies + 1; i++) {
		sum = (sum + (polygon[i - 1] * polygon[i]));
	}

	sum = sum / Fraction(2, 1);

	return sum;
}

bool isIntersect(Point p1, Point p2, Point q1, Point q2, Point &x) {
	Point r = p2 - p1,
				s = q2 - q1,
				v = q1 - p1;

	Fraction d = r * s;

	if (d != Fraction(0,1)) {
		Fraction t = (v * s) / d,
						 u = (v * r) / d;

		if ((Fraction(0, 1) < t) && (t < Fraction(1, 1)) && (Fraction(0, 1) < u) && (u < Fraction(1, 1))) {
			x = p1 + (r * t);
			return true;
		}
	}

	return false;
}

bool isInsidePolygon(Point hit, Point board, Point polygon[], int numVerticies) {
	int w = 0;

	Point v1(hit.getX(), Fraction(0, 1)),
				v2(hit.getX(), board.getY()),
				h1(Fraction(0, 1), hit.getY()),
				h2(board.getX(), hit.getY()),
				z1,
				z2,
				intersect;

	for (int i = 1; i < numVerticies + 1; i++) {
		if (isIntersect(v1, v2, polygon[i - 1], polygon[i], intersect)) {
			z1 = intersect - hit;
			z2 = polygon[i] - polygon[i - 1];

			if (z1.getY() * z2.getX() < Fraction(0, 1)) {
				w++;
			}
			else {
				w--;
			}
		}

		if (isIntersect(h1, h2, polygon[i - 1], polygon[i], intersect)) {
			z1 = intersect - hit;
			z2 = polygon[i] - polygon[i - 1];

			if (z1.getX() * z2.getY() > Fraction(0,1)) {
				w++;
			}
			else {
				w-- ;
			}
		}
	}

	if (w == 0)
		return false;

	return true;
}
