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


Wheel::Wheel(Point center, float rad, float depth, float width, int texture)
{
	this->center=center;
	this->depth=depth;
	this->rad=rad;
	this->width=width;
	this->texture= texture;
}

void Wheel::DrawWheel()
{
	glPushMatrix();
		glTranslated(center.x,center.y, center.z);
		premitives::DrawRing(Point(0,0,depth/2),rad-width,rad,texture);
		premitives::DrawRing(Point(0,0,-depth/2),rad-width,rad, texture);
		premitives::DrawCylinderBody(Point(0,0,-depth/2),rad,rad,depth, texture);
		premitives::DrawCylinderBody(Point(0,0,-depth/2),rad-width,rad-width,depth, texture);
		premitives::DrawCupe(Point(-width/2,-(rad-width),-depth/2),width,2*(rad-width),depth, texture);
		glRotated(60,0,0,1);
		premitives::DrawCupe(Point(-width/2,-(rad-width),-depth/2),width,2*(rad-width),depth, texture);
		glRotated(60,0,0,1);
		premitives::DrawCupe(Point(-width/2,-(rad-width),-depth/2),width,2*(rad-width),depth, texture);
		glRotated(60,0,0,1);
		premitives::DrawCupe(Point(-width/2,-(rad-width),-depth/2),width,2*(rad-width),depth, texture);
		glRotated(60,0,0,1);
		premitives::DrawCupe(Point(-width/2,-(rad-width),-depth/2),width,2*(rad-width),depth, texture);
		glRotated(60,0,0,1);
		premitives::DrawCupe(Point(-width/2,-(rad-width),-depth/2),width,2*(rad-width),depth, texture);
	glPopMatrix();
}