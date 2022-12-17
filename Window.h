#pragma once
#include "Point.h"
class Window
{
public:
	Point bottom_left_back;
	float length, hight, phase, max_phase, min_phase;
	bool is_cover_open;
	int texture_window, texture_cover, texture_box;
	Window(void);
	~Window(void);
	Window(Point bottom_left_back, float length, float hight,  int texture_window, int texture_cover, int texture_box);
	void DrawWindow(float angle_y);
};

