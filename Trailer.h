#pragma once
#include "Object.h"
#include "Point.h"
#include "Wheel.h"
#include "Window.h"
#include "Door.h"
class Trailer
{
public:
	Point bottom_left_back;
	float length, depth, hight;
	float door_length, door_hight;
	float  window_hight;
	bool window_is_on_right, window_is_on_left, door_is_on_side;
	Wheel wheel[4];
	Door d[3];
	int texture_wheel, texture_window, texture_door, texture_body, texture_cover, texture_cover_box;
	float wheel_rad, wheel_width, wheel_depth;
	Trailer(void);
	~Trailer(void);
	Trailer(Point bottom_left_back, float length, float depth, float hight,
			float door_length, float door_hight, bool door_is_on_side,
			float window_hight, bool window_is_on_left, bool window_is_on_right,
			float wheel_rad, float wheel_width, float wheel_depth,
			int texture_wheel, int texture_window, int texture_door, int texture_body, int texture_cover, int texture_cover_box);
	void DrawTrailer();
};

