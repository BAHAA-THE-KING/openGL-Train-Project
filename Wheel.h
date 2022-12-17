#pragma once
#include "Point.h"
class Wheel
{
public:
	Point center; 
	float rad, depth, width;
	int texture;
	Wheel(void);
	~Wheel(void);
	Wheel(Point center, float rad, float depth, float width, int texture);
	void DrawWheel();
};

