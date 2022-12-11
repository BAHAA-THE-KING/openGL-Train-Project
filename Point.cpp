#include "Point.h"
#include "stdc++.h"
using namespace std;

Point::Point(void)
{
}


Point::~Point(void)
{
}


Point::Point(float x, float y, float z)
{
	this->x=x;
	this->y=y;
	this->z=z;
}

float Point::distance(Point a, Point b)
{
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
}

