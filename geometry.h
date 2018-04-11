#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include <iostream>

using namespace std;

struct Point
{
	double x, y;
};

struct Triangle
{
	Point vertexes[3];
	double area, perimetr;
};

double calcDistance(const Point& pa, const Point& pb);

double calcTringleArea(Triangle tr);

double calcTringlePerim(Triangle tr);
#endif // !_GEOMETRY_H
