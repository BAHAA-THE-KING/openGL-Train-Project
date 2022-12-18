#include "Wheel.h"

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include "texture.h"
#include "House.h"
#include "Mill.h"
#include "stdc++.h"
#include "Tree.h"
#include "Village.h"
#include "Skybox.h"
#include "Point.h"
#include "premitives.h"


Wheel::Wheel(void)
{
}


Wheel::~Wheel(void)
{
}


Wheel::Wheel(Point center, float rad, float length, float width, int texture_wheel, int texture_stick, float stick_length_another_side, float stick_length_same_side)
{
	this->center=center;
	this->length=length;
	this->rad=rad;
	this->width=width;
	this->texture_wheel= texture_wheel;
	this->texture_stick= texture_stick;
	this->stick_length_another_side=stick_length_another_side;
	this->stick_length_same_side=stick_length_same_side;
	this->angle=0;
}

void Wheel::DrawWheel()
{
	glPushMatrix();
		glTranslated(center.x,center.y, center.z);
		glRotated(90,0,1,0);
		glRotated(angle,0,0,1);
		premitives::DrawRing(Point(0,0,length/2),rad-width,rad,texture_wheel);
		premitives::DrawRing(Point(0,0,-length/2),rad-width,rad, texture_wheel);
		premitives::DrawCylinderBody(Point(0,0,-length/2),rad,rad,length, texture_wheel);
		premitives::DrawCylinderBody(Point(0,0,-length/2),rad-width,rad-width,length, texture_wheel);
		premitives::DrawCylinderBody(Point(0,0,0),width,width,stick_length_another_side,texture_stick);
		int in_out=1;
		if (stick_length_another_side>0)
			in_out=-1;
		glPushMatrix();
			glTranslated(-width/4,-(rad-width)/2,-length/4);
			glRotated(-angle,0,0,1);
			premitives::DrawCupe(Point(0,0,0),stick_length_same_side,width,in_out*width, texture_stick);
		glPopMatrix();
		premitives::DrawCupe(Point(-width/2,-(rad-width),-length/2),width,2*(rad-width),length, texture_wheel);
		glRotated(60,0,0,1);
		premitives::DrawCupe(Point(-width/2,-(rad-width),-length/2),width,2*(rad-width),length, texture_wheel);
		glRotated(60,0,0,1);
		premitives::DrawCupe(Point(-width/2,-(rad-width),-length/2),width,2*(rad-width),length, texture_wheel);
		glRotated(60,0,0,1);
		premitives::DrawCupe(Point(-width/2,-(rad-width),-length/2),width,2*(rad-width),length, texture_wheel);
		glRotated(60,0,0,1);
		premitives::DrawCupe(Point(-width/2,-(rad-width),-length/2),width,2*(rad-width),length, texture_wheel);
		glRotated(60,0,0,1);
		premitives::DrawCupe(Point(-width/2,-(rad-width),-length/2),width,2*(rad-width),length, texture_wheel);
	glPopMatrix();
	angle++;
}