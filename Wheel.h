#pragma once
#include "Point.h"
class Wheel
{
public:
	Point center; 
	float rad, length, width, stick_length_another_side, stick_length_same_side, angle;
	int texture_wheel, texture_stick;
	Wheel(void);
	~Wheel(void);
	Wheel(Point center, float rad, float length, float width, int texture_wheel, int texture_stick, float stick_length_another_side, float stick_length_same_side);
	void DrawWheel();
};

