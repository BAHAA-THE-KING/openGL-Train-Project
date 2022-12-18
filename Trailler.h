#pragma once

#include "Point.h"
#include "premitives.h"
#include "Wheel.h"
#include "Window.h"
#include "Door.h"
#include "stdc++.h"
using namespace std;
class Trailler
{
public:
	Point bottom_left_back;
	float length, hight, depth;
	Door door[3];
	Window window[2];
	vector <Wheel> wheel;
	float way_length, way_hight;
	int texture_body, texture_fence, texture_way;
	Trailler(void);
	~Trailler(void);
	Trailler(Point bottom_left_back, float length, float hight, float depth,
			float door_length, float door_hight, bool door_is_right,
			float window_hight, bool window_is_left, bool window_is_right,
			float way_length, float way_hight, 
			float wheel_rad, float wheel_length, float wheel_width,
			int texture_body, int texture_cover, int texture_cover_box, int texture_window,
			int texture_door, int texture_fence, int texture_way, int texture_wheel, int texture_wheel_stick);
	void DrawTrailler();


private:
	void DrawTop();
	void DrawBottom();
	void DrawBack();
	void DrawFront();
	void DrawLeft();
	void DrawRight();
	void DrawWay();
};

