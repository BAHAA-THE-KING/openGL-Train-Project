#include "Village.h"
#include "Point.h"

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include "texture.h"
#include "stdc++.h"
#include "House.h"
#include "Mill.h"
#include "Tree.h"
using namespace std;



Village::Village(void)
{
}


Village::~Village(void)
{
}
Village::Village(Point bottom_left_back,	float length, float depth, int texture_house_door,int texture_house_wall, int texture_house_window,int texture_house_roof[4],
				 int texture_mill_door, int texture_mill_wall, int texture_mill_window, int texture_mill_roof, int texture_mill_blade,
				 int texture_tree_brown, int texture_tree_green)
{
	this->bottom_left_back = bottom_left_back;
	this->length = length;
	this->depth= depth;
	this->texture_house_door= texture_house_door;
	this->texture_house_wall= texture_house_wall;
	this->texture_house_window= texture_house_window;
	for (int i=0; i<4; i++)
		this->texture_house_roof[i]= texture_house_roof[i];
	this->texture_mill_door= texture_mill_door;
	this->texture_mill_wall= texture_mill_wall;
	this->texture_mill_window= texture_mill_window;
	this->texture_mill_roof= texture_mill_roof;
	this->texture_mill_blade= texture_mill_blade;
	this->texture_tree_brown= texture_tree_brown;
	this->texture_tree_green= texture_tree_green;

	int house_in_row=length/5, house_in_colomn=(depth-6)/4;
	int mill_in_row=(length)/13;
	for (int i=0; i<house_in_row; i++)
	{
		for (int j=1; j<house_in_colomn; j++)
		{
				int x=rand()%4;
				h.push_back(*(new House(Point (5*i,0,4*j+6),4,3,1,3,texture_house_door,texture_house_wall,texture_house_window,texture_house_roof[x])));
		}
	}


	for (int i=0; i<mill_in_row; i++)
		{
			m.push_back(*( new Mill(Point (7+13*i,0,0),5,5,2,10,texture_mill_door,texture_mill_wall,texture_mill_window,texture_mill_roof,texture_mill_blade)));
		}
	int tree_in_col= min ((depth)/3,10);
	int dis=(depth)/tree_in_col;
	for (int i=0; i<tree_in_col;  i++)
	{
		t.push_back(*( new Tree(Point (-2,0,i*dis),1,1,2,2,texture_tree_brown,texture_tree_green)));
	}
	for (int i=0; i<tree_in_col;  i++)
	{
		t.push_back(*( new Tree(Point (length+2,0,i*dis),1,1,2,2,texture_tree_brown,texture_tree_green)));
	}
}


void Village::DrawVillage()
{
	glPushMatrix();
	glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);
	int house_in_row=length/5, house_in_colomn=(depth-6)/4;
	int mill_in_row=length/11;
	for (auto x:h)
		x.DrawHouse();
	for (int i=0; i<m.size(); i++)
		m[i].DrawMill();
	for (auto x:t)
		x.DrawTree();
	
	glPopMatrix();
}