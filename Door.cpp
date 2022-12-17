#include "Door.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include "texture.h"
#include "stdc++.h"
#include "Point.h"
#include "premitives.h"

Door::Door(void)
{
}


Door::~Door(void)
{
}


Door::Door(Point bottom_left, float length, float hight, int texture)
{
	this->bottom_left=bottom_left;
	this->hight=hight;
	this->length=length;
	this->texture=texture;
	this->angle=0;
	this->angle_change=0;
	this->is_open=0;
}

void Door::DrawDoor(){

	glPushMatrix();
		glTranslated(bottom_left.x,bottom_left.y,bottom_left.z);
		glRotated(angle,0,1,0);
		glBindTexture(GL_TEXTURE_2D,texture);
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