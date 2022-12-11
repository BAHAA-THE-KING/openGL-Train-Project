#include "Mill.h"
#include "Point.h"

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include "texture.h"
#include "premitives.h"
Mill::Mill(void)
{
}


Mill::~Mill(void)
{
}

Mill::Mill( Point bottom_left_back,
			float length,float depth,float hight_haram,float hight_cube,
			
			int texture_door, int texture_wall, int texture_window, int texture_roof, int texture_blades)
{
	this->bottom_left_back= bottom_left_back;
	this->length= length;
	this->depth= depth;
	this->hight_haram = hight_haram;
	this->hight_cube= hight_cube;
	this->blades_length= hight_cube/2; 
	this->blades_width= this->blades_length/2;
	this->texture_door= texture_door;
	this->texture_wall= texture_wall;
	this->texture_window= texture_window; 
	this->texture_roof= texture_roof;
	this->texture_blades= texture_blades;
	this->angle=0;
}

void Mill::DrawMill()
{
	Point a= bottom_left_back;
	Point b= Point (a.x+length,a.y,a.z);
	Point c= Point (a.x+length,a.y,a.z+depth);
	Point d= Point (a.x,a.y,a.z+depth);
	Point e= Point (a.x,a.y+hight_cube,a.z);
	Point f= Point (a.x+length,a.y+hight_cube,a.z);
	Point g= Point (a.x+length,a.y+hight_cube,a.z+depth);
	Point h= Point (a.x,a.y+hight_cube,a.z+depth);
	
	//draw wall
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D, texture_wall);

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



	
	//draw door
	glBindTexture(GL_TEXTURE_2D, texture_door);
	glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(d.x,d.y,d.z);
		// if the door in the middle and the door length is the house length/4, and the hight is house hight/4
		glTranslated(length/2-length/8,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube/4,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/4,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
	glPopMatrix();


	//window in the left side
	glBindTexture(GL_TEXTURE_2D, texture_window);
	glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(a.x,a.y,a.z);
		glRotated(-90,0,1,0);
		// if the window in the middle and the window length is the mill length/4, and the hight is mill hight/7
		glTranslated(depth/2-depth/8,hight_cube/2-hight_cube/14,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/4,hight_cube/7,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/7,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
	glPopMatrix();
	
	//Draw roof
	glBindTexture(GL_TEXTURE_2D, texture_roof);

	glPushMatrix();
		Point top=Point (e.x+length/2, e.y+hight_haram, e.z+depth/2);
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
	

	//blade
	angle++;
	glPushMatrix();
		glTranslated(d.x,d.y,d.z);
		glTranslated(length/2,hight_cube/4+blades_length+hight_cube/20,0);
		premitives::DrawBall(1,texture_wall);
		glBindTexture(GL_TEXTURE_2D, texture_blades);
		glTranslated(0,0,1);
		glLineWidth(5);
		glRotated(angle++,0,0,1);
		glPushMatrix();
			glBegin(GL_LINES);
				glVertex3f(0,0,0);
				glVertex3f(blades_length,0,0);
			glEnd();
			glTranslated(blades_length/6,0,0);
			glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(0,0,0);
			glTexCoord2d(1, 0);
			glVertex3d(5*blades_length/6,0,0);
			glTexCoord2d(1, 1);
			glVertex3d(5*blades_length/6,blades_width,0);
			glTexCoord2d(0, 1);
			glVertex3d(0,blades_width,0);
			glEnd();
		glPopMatrix();
		glRotated(90,0,0,1);
		glPushMatrix();
			glBegin(GL_LINES);
				glVertex3f(0,0,0);
				glVertex3f(blades_length,0,0);
			glEnd();
			glTranslated(blades_length/6,0,0);
			glBindTexture(GL_TEXTURE_2D, texture_blades);
			glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(0,0,0);
			glTexCoord2d(1, 0);
			glVertex3d(5*blades_length/6,0,0);
			glTexCoord2d(1, 1);
			glVertex3d(5*blades_length/6,blades_width,0);
			glTexCoord2d(0, 1);
			glVertex3d(0,blades_width,0);
			glEnd();
		glPopMatrix();
		glRotated(90,0,0,1);
		glPushMatrix();
			glBegin(GL_LINES);
				glVertex3f(0,0,0);
				glVertex3f(blades_length,0,0);
			glEnd();
			glTranslated(blades_length/6,0,0);
			glBindTexture(GL_TEXTURE_2D, texture_blades);
			glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(0,0,0);
			glTexCoord2d(1, 0);
			glVertex3d(5*blades_length/6,0,0);
			glTexCoord2d(1, 1);
			glVertex3d(5*blades_length/6,blades_width,0);
			glTexCoord2d(0, 1);
			glVertex3d(0,blades_width,0);
			glEnd();
		glPopMatrix();
		glRotated(90,0,0,1);
		glPushMatrix();
			glBegin(GL_LINES);
				glVertex3f(0,0,0);
				glVertex3f(blades_length,0,0);
			glEnd();
			glTranslated(blades_length/6,0,0);
			glBindTexture(GL_TEXTURE_2D, texture_blades);
			glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(0,0,0);
			glTexCoord2d(1, 0);
			glVertex3d(5*blades_length/6,0,0);
			glTexCoord2d(1, 1);
			glVertex3d(5*blades_length/6,blades_width,0);
			glTexCoord2d(0, 1);
			glVertex3d(0,blades_width,0);
			glEnd();
		glPopMatrix();
	glPopMatrix();
}