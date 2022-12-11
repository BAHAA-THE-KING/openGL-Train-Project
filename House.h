#pragma once
#include "Point.h"
class House
{

public:
	Point bottom_left_back;
	float length, depth, hight_haram, hight_cube;
	 int texture_door, texture_wall, texture_window, texture_roof;
	House(void);
	~House(void);
	House(Point bottom_left_back,float length, float depth, float hight_haram, float hight_cube, int texture_door,int texture_wall,int texture_window,int texture_roof);
	void DrawHouse();
};

