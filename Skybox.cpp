#include "Skybox.h"
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


Skybox::Skybox(void)
{
}


Skybox::~Skybox(void)
{
}

Skybox::Skybox(Point bottom_left_back, float length, float depth, float hight, int texture)
{
	this->bottom_left_back=bottom_left_back;
	this->depth=depth;
	this->hight=hight;
	this->length=length;
	this->texture=texture;
}

void Skybox::DrawSkybox()
{
	glPushMatrix();
		glTranslated(bottom_left_back.x, bottom_left_back.y, bottom_left_back.z);
		glColor3f(1,1,1);
		glBindTexture(GL_TEXTURE_2D, texture);

		//back
		glBegin(GL_QUADS);
		glTexCoord2d(0.25, 0.33);
		glVertex3d(0, 0, 0);
		glTexCoord2d(0.5, 0.33);
		glVertex3d(length, 0, 0);
		glTexCoord2d(0.5, 0.67);
		glVertex3d(length, hight, 0);
		glTexCoord2d(0.25, 0.67);
		glVertex3d(0, hight, 0);
		glEnd();


		//front
		glBegin(GL_QUADS);
		glTexCoord2d(1, 0.33);
		glVertex3d(0, 0, depth);
		glTexCoord2d(0.75, 0.33);
		glVertex3d(length, 0, depth);
		glTexCoord2d(0.75, 0.67);
		glVertex3d(length, hight, depth);
		glTexCoord2d(1, 0.67);
		glVertex3d(0, hight, depth);
		glEnd();

		//left
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0.33);
		glVertex3d(0, 0, depth);
		glTexCoord2d(0.25, 0.33);
		glVertex3d(0, 0, 0);
		glTexCoord2d(0.25, 0.67);
		glVertex3d(0, hight, 0);
		glTexCoord2d(0, 0.67);
		glVertex3d(0, hight, depth);
		glEnd();

		//right
		glBegin(GL_QUADS);
		glTexCoord2d(0.75, 0.33);
		glVertex3d(length, 0, depth);
		glTexCoord2d(0.5, 0.33);
		glVertex3d(length, 0, 0);
		glTexCoord2d(0.5, 0.67);
		glVertex3d(length, hight, 0);
		glTexCoord2d(0.75, 0.67);
		glVertex3d(length, hight, depth);
		glEnd();


		//top
		glBegin(GL_QUADS);
		glTexCoord2d(0.25 , 0.67);
		glVertex3d(0, hight, 0);
		glTexCoord2d(0.5, 0.67);
		glVertex3d(length, hight, 0);
		glTexCoord2d(0.5, 1);
		glVertex3d(length, hight, depth);
		glTexCoord2d(0.25, 1);
		glVertex3d(0, hight, depth);
		glEnd();


		//bottom
		glBegin(GL_QUADS);
		glTexCoord2d(0.25, 0.33);
		glVertex3d(0, 0, 0);
		glTexCoord2d(0.5, 0.33);
		glVertex3d(length, 0, 0);
		glTexCoord2d(0.5,0);
		glVertex3d(length, 0, depth);
		glTexCoord2d(0.25, 0);
		glVertex3d(0, 0, depth);
		glEnd();
	glPopMatrix();
}