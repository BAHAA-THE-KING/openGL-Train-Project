#pragma once
#include "Point.h"
class Mill
{
public:
	Point bottom_left_back;
	float length, depth, hight_haram, hight_cube;
	float blades_length, blades_width;
	int texture_door, texture_wall, texture_window, texture_roof, texture_blades;
	float angle;
	Mill(void);
	~Mill(void);
	Mill(Point bottom_left_back,
	float length,float depth,float hight_haram,float hight_cube,
	int texture_door, int texture_wall, int texture_window, int texture_roof, int texture_blades);
	void DrawMill();

};

