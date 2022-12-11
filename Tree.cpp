#include "Tree.h"
#include "Point.h"

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include "texture.h"
#include "stdc++.h"
using namespace std;


Tree::Tree(void)
{
}


Tree::~Tree(void)
{
}

Tree::Tree(Point bottom_left_back, float length, float depth, float hight_haram, float hight_cube, int texture_brown, int texture_green)
{
	this->bottom_left_back=bottom_left_back;
	this->depth=depth;
	this->hight_cube=hight_cube;
	this->hight_haram=hight_haram;
	this->length=length;
	this->texture_brown=texture_brown;
	this->texture_green=texture_green;
}

void Tree::DrawTree()
{
	glPushMatrix();
	Point a= bottom_left_back;
	glTranslated(a.x+length/2,a.y,a.z+depth/2);
	a=Point(-length/2,0,-depth/2);
	Point b= Point (a.x+length,a.y,a.z);
	Point c= Point (a.x+length,a.y,a.z+depth);
	Point d= Point (a.x,a.y,a.z+depth);
	Point e= Point (a.x,a.y+hight_cube,a.z);
	Point f= Point (a.x+length,a.y+hight_cube,a.z);
	Point g= Point (a.x+length,a.y+hight_cube,a.z+depth);
	Point h= Point (a.x,a.y+hight_cube,a.z+depth);
	

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D, texture_brown);

	//ABCD
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(a.x,a.y,a.z);
	glTexCoord2d(1, 0);
	glVertex3f(b.x,b.y,b.z);
	glTexCoord2d(1, 1);
	glVertex3f(c.x,c.y,c.z);
	glTexCoord2d(0, 1);
	glVertex3f(d.x,d.y,d.z);
	glEnd();


	//EFGH
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(e.x,e.y,e.z);
	glTexCoord2d(1, 0);
	glVertex3f(f.x,f.y,f.z);
	glTexCoord2d(1, 1);
	glVertex3f(g.x,g.y,g.z);
	glTexCoord2d(0, 1);
	glVertex3f(h.x,h.y,h.z);
	glEnd();

	//ABFE
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(a.x,a.y,a.z);
	glTexCoord2d(1, 0);
	glVertex3f(b.x,b.y,b.z);
	glTexCoord2d(1, 1);
	glVertex3f(f.x,f.y,f.z);
	glTexCoord2d(0, 1);
	glVertex3f(e.x,e.y,e.z);
	glEnd();

	//ADHE
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(a.x,a.y,a.z);
	glTexCoord2d(1, 0);
	glVertex3f(d.x,d.y,d.z);
	glTexCoord2d(1, 1);
	glVertex3f(h.x,h.y,h.z);
	glTexCoord2d(0, 1);
	glVertex3f(e.x,e.y,e.z);
	glEnd();

	//CBFG
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(c.x,c.y,c.z);
	glTexCoord2d(1, 0);
	glVertex3f(b.x,b.y,b.z);
	glTexCoord2d(1, 1);
	glVertex3f(f.x,f.y,f.z);
	glTexCoord2d(0, 1);
	glVertex3f(g.x,g.y,g.z);
	glEnd();

	//DCGH
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(d.x,d.y,d.z);
	glTexCoord2d(1, 0);
	glVertex3f(c.x,c.y,c.z);
	glTexCoord2d(1, 1);
	glVertex3f(g.x,g.y,g.z);
	glTexCoord2d(0, 1);
	glVertex3f(h.x,h.y,h.z);
	glEnd();



	e=Point(e.x-length,e.y,e.z-depth);
	f=Point(f.x+length,f.y,f.z-depth);
	g=Point(g.x+length,g.y,g.z+depth);
	h=Point(h.x-length,h.y,h.z+depth);
	glBindTexture(GL_TEXTURE_2D, texture_green);
	Point top=Point (0, e.y+hight_haram, 0);
		glBegin(GL_TRIANGLES);
			glTexCoord2d(0, 0);
			glVertex3f(e.x,e.y,e.z);
			glTexCoord2d(1, 0);
			glVertex3f(h.x,h.y,h.z);
			glTexCoord2d(0.5, 1);
			glVertex3f(top.x,top.y,top.z);
		glEnd();
		glBegin(GL_TRIANGLES);
			glTexCoord2d(0, 0);
			glVertex3f(e.x,e.y,e.z);
			glTexCoord2d(1, 0);
			glVertex3f(f.x,f.y,f.z);
			glTexCoord2d(0.5, 1);
			glVertex3f(top.x,top.y,top.z);
		glEnd();
		glBegin(GL_TRIANGLES);
			glTexCoord2d(0, 0);
			glVertex3f(g.x,g.y,g.z);
			glTexCoord2d(1, 0);
			glVertex3f(h.x,h.y,h.z);
			glTexCoord2d(0.5, 1);
			glVertex3f(top.x,top.y,top.z);
		glEnd();
		glBegin(GL_TRIANGLES);
			glTexCoord2d(0, 0);
			glVertex3f(f.x,f.y,f.z);
			glTexCoord2d(1, 0);
			glVertex3f(g.x,g.y,g.z);
			glTexCoord2d(0.5, 1);
			glVertex3f(top.x,top.y,top.z);
		glEnd();

		glTranslated(0,hight_haram/2,0);
		glScaled(0.7,1,0.7);
		glBegin(GL_TRIANGLES);
			glTexCoord2d(0, 0);
			glVertex3f(e.x,e.y,e.z);
			glTexCoord2d(1, 0);
			glVertex3f(h.x,h.y,h.z);
			glTexCoord2d(0.5, 1);
			glVertex3f(top.x,top.y,top.z);
		glEnd();
		glBegin(GL_TRIANGLES);
			glTexCoord2d(0, 0);
			glVertex3f(e.x,e.y,e.z);
			glTexCoord2d(1, 0);
			glVertex3f(f.x,f.y,f.z);
			glTexCoord2d(0.5, 1);
			glVertex3f(top.x,top.y,top.z);
		glEnd();
		glBegin(GL_TRIANGLES);
			glTexCoord2d(0, 0);
			glVertex3f(g.x,g.y,g.z);
			glTexCoord2d(1, 0);
			glVertex3f(h.x,h.y,h.z);
			glTexCoord2d(0.5, 1);
			glVertex3f(top.x,top.y,top.z);
		glEnd();
		glBegin(GL_TRIANGLES);
			glTexCoord2d(0, 0);
			glVertex3f(f.x,f.y,f.z);
			glTexCoord2d(1, 0);
			glVertex3f(g.x,g.y,g.z);
			glTexCoord2d(0.5, 1);
			glVertex3f(top.x,top.y,top.z);
		glEnd();

		glTranslated(0,hight_haram/2,0);
		glScaled(0.8,1,0.8);
		glBegin(GL_TRIANGLES);
			glTexCoord2d(0, 0);
			glVertex3f(e.x,e.y,e.z);
			glTexCoord2d(1, 0);
			glVertex3f(h.x,h.y,h.z);
			glTexCoord2d(0.5, 1);
			glVertex3f(top.x,top.y,top.z);
		glEnd();
		glBegin(GL_TRIANGLES);
			glTexCoord2d(0, 0);
			glVertex3f(e.x,e.y,e.z);
			glTexCoord2d(1, 0);
			glVertex3f(f.x,f.y,f.z);
			glTexCoord2d(0.5, 1);
			glVertex3f(top.x,top.y,top.z);
		glEnd();
		glBegin(GL_TRIANGLES);
			glTexCoord2d(0, 0);
			glVertex3f(g.x,g.y,g.z);
			glTexCoord2d(1, 0);
			glVertex3f(h.x,h.y,h.z);
			glTexCoord2d(0.5, 1);
			glVertex3f(top.x,top.y,top.z);
		glEnd();
		glBegin(GL_TRIANGLES);
			glTexCoord2d(0, 0);
			glVertex3f(f.x,f.y,f.z);
			glTexCoord2d(1, 0);
			glVertex3f(g.x,g.y,g.z);
			glTexCoord2d(0.5, 1);
			glVertex3f(top.x,top.y,top.z);
		glEnd();
		glPopMatrix();
}