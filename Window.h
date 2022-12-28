#pragma once
#include "Point.h"
class Window
{
public:
	Point bottom_left_back;
	float length, hight, phase, max_length, min_length, curr_length, cover_change, interactive_distance, angle_y;
	bool is_open, is_move;
	int texture_window, texture_cover, texture_box;
	Window(void);
	~Window(void);
	Window(Point bottom_left_back, float length, float hight, float angle_y, int texture_window, int texture_cover, int texture_box);
	void DrawWindowCover(bool *keys, Point pos);
	void DrawWindowGlass();
	void Move();
	void OpenCover(bool *keys, Point pos);

};

