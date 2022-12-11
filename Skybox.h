#pragma once
#include "Point.h"

class Skybox
{
public:
	Point bottom_left_back;
	float length, depth, hight;
	int texture;
	Skybox(void);
	~Skybox(void);
	Skybox(Point bottom_left_back, float length, float depth, float hight, int texture);
	void DrawSkybox();
};

