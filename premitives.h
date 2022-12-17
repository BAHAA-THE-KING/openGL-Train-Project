#pragma once
#include "Point.h"
class premitives
{
public:
	premitives(void);
	~premitives(void);
	static void DrawBall(float rad, int texture=-1);
	 static void DrawCylinderBody(Point Base_center1, float Base_rad1, float Base_rad2, float height, int texture);
	 static void DrawRing(Point center, float radin, float radout, int texture);
	 static void DrawCupe(Point bottom_left_back, float length, float hight, float depth, int texture);
	 static void DrawCupe(Point bottom_left_back, float length, float hight, float depth, int texture, 
						  bool is_exist_front, bool is_exist_back, bool is_exist_right,
						  bool is_exist_left, bool is_exist_bottom, bool is_exist_top);
};

