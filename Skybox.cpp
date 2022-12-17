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
#include "premitives.h"
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
		premitives::DrawCupe(bottom_left_back,length,hight,depth,texture);
	glPopMatrix();
}