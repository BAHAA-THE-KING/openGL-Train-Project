#pragma once
#include "Point.h"
#include "stdc++.h"
using namespace std;
class Door
{

public:
	Point bottom_left;
	float length, hight, angle, angle_change, angle_min, angle_max, angle_open_direction, safety_distance;
	bool is_open, is_move;
	int texture;
	Door(void);
	~Door(void);
	Door(Point bottom_left, float length, float hight, int texture, float angle, float angle_open_direction);
	void DrawDoor(bool *keys, Point pos);
	void Move();
	void OpenDoors(bool *keys, Point pos);
	bool CollisionDoor (Point pos);
};

