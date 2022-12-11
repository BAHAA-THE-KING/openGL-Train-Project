#pragma once
class Point
{
public:
	float x,y,z;
	Point(void);
	~Point(void);
	Point(float x, float y, float z);
	static float distance(Point a, Point b);
};

