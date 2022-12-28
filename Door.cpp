#include "Door.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include "texture.h"
#include "stdc++.h"
#include "Point.h"
#include "premitives.h"
#include "Object.h"
using namespace std;
Door::Door(void)
{
}


Door::~Door(void)
{
}


Door::Door(Point bottom_left, float length, float hight, int texture, float angle, float angle_open_direction)
{
	this->bottom_left=bottom_left;
	this->hight=hight;
	this->length=length;
	this->texture=texture;
	this->angle_change=0;
	this->is_open=0;
	this->is_move=0;
	this->angle=angle;
	this->angle_open_direction=angle_open_direction;
	float x=angle, y=angle+angle_open_direction*90;
	this->angle_min=min(x,y);
	this->angle_max=max(x,y);
	this->safety_distance= 0.5;
}

void Door::DrawDoor(bool *keys, Point pos){

	OpenDoors( keys,  pos);
	glPushMatrix();
		if(is_move)
			this->Move();
		glTranslated(bottom_left.x,bottom_left.y,bottom_left.z);
		glBindTexture(GL_TEXTURE_2D,texture);
		glRotated(angle,0,1,0);
		glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex3f(0,0,0);

			glTexCoord2f(1,0);
			glVertex3f(length,0,0);
			
			glTexCoord2f(1,1);
			glVertex3f(length,hight,0);
			
			glTexCoord2f(0,1);
			glVertex3f(0,hight,0);
		glEnd();
	glPopMatrix();

}

void Door::Move()
{
	
	if (angle_change!=0)
		angle+=angle_change;
	else
	{
		if (angle<=angle_min)
			angle_change=1;
		else
			angle_change=-1;
		angle+=angle_change;
	}
	if (angle<=angle_min)
	{
		angle_change=0;
		is_open= (!is_open);
		angle=angle_min;
		is_move=0;
		return;
	}
	if (angle>=angle_max)
	{
		angle_change=0;
		is_open= (!is_open);
		angle=angle_max;
		is_move=0;
		return;
	}
}

void Door::OpenDoors(bool *keys, Point pos)
{
	if (keys['O'])
	{
		if (Point::distance(this->bottom_left,pos)<this->length+10)
		{
			this->is_move=1;
		}
	}
}


bool Door::CollisionDoor (Point a)
{
	Point pos = Point (a.x-bottom_left.x,a.y-bottom_left.y,a.z-bottom_left.z);
	float x = length * cos (angle);
	float z = length * sin (angle);
	if (pos.x>0-safety_distance && pos.x<x+safety_distance && pos.y>0-safety_distance && pos.y<hight+safety_distance && pos.z>0-safety_distance && pos.z<z+safety_distance )
		return 0;
	return 1;
}
