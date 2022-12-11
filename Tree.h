#pragma once
#include "Point.h"
	
class Tree
{
public:
	Point bottom_left_back;
	float length, depth, hight_haram, hight_cube;
	 int texture_brown, texture_green;
	Tree(void);
	~Tree(void);
	Tree(Point bottom_left_back, float length, float depth, float hight_haram, float hight_cube, int texture_brown, int texture_green);
	void DrawTree();
};

