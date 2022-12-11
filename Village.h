#pragma once
#include "Point.h"
#include "stdc++.h"
#include "House.h"
#include "Mill.h"
#include "Tree.h"
using namespace std;
class Village
{
public:
	Point bottom_left_back;
	float length, depth;
	int texture_house_roof[4];
	int texture_house_door, texture_house_wall, texture_house_window,
		texture_mill_door,  texture_mill_wall,  texture_mill_window,  texture_mill_roof, texture_mill_blade,
		texture_tree_brown,  texture_tree_green;
	vector <House> h;
	vector <Mill> m;
	vector <Tree> t;

	Village(void);
	~Village(void);
	Village(Point bottom_left_back,	float length, float depth, int texture_house_door,int texture_house_wall, int texture_house_window,int texture_house_roof[4],
		int texture_mill_door, int texture_mill_wall, int texture_mill_window, int texture_mill_roof, int texture_mill_blade,
		int texture_tree_brown, int texture_tree_green);
	void DrawVillage();
	
};

