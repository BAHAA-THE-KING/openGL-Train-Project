#pragma once
#include "Point.h"
class Door
{
public:
	Point bottom_left;
	float length, hight, angle, angle_change;
	bool is_open;
	int texture;
	Door(void);
	~Door(void);
	Door(Point bottom_left, float length, float hight, int texture);
	void DrawDoor();
};

