#include "Window.h"
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
#include "Wheel.h"


Window::Window(void)
{
}


Window::~Window(void)
{
}

Window::Window(Point bottom_left_back, float length, float hight,   int texture_window, int texture_cover, int texture_box)
{
	this->bottom_left_back=bottom_left_back;
	this->hight=hight;
	this->is_cover_open=0;
	this->length=length;
	this->max_phase=2;
	this->min_phase=0.5;
	this->phase=max_phase;
	this->texture_cover=texture_cover;
	this->texture_window=texture_window;
	this->texture_box= texture_box;

}
void Window::DrawWindow(float angle_y)
{
	glPushMatrix();
		glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);
		if (angle_y==180)
		{
			glRotated(angle_y,0,1,0);
			glTranslated(-length,0,0);
		}
		glPushMatrix();
			float X_max=0.5;
			glTranslated(0,0,X_max);
			for (float x=0; x<=length; x+=0.1)
			{
				glBindTexture(GL_TEXTURE_2D,texture_cover);
				glBegin(GL_QUADS);
					glTexCoord2f(0,0);
					glVertex3f(x,0,-X_max*sin(phase*x));
					glTexCoord2f(1,0);		
					glVertex3f(x+0.1,0,-X_max*sin(phase*(x+0.1)));
					glTexCoord2f(1,1);
					glVertex3f(x+0.1,hight,-X_max*sin(phase*(x+0.1)));
					glTexCoord2f(0,1);
					glVertex3f(x,hight,-X_max*sin(phase*x));
				glEnd();
			}
			glTranslated(0,hight-X_max/2,0);
			premitives::DrawCupe(Point(0,0,0),length,X_max,2*X_max,texture_box,1,1,1,1,0,1);
		glPopMatrix();
		glEnable(GL_BLEND);
			glColor4f(1,1,1,0.5);
			glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D,texture_window);
			glBegin(GL_QUADS);
				glTexCoord2d(0, 0);
				glVertex3f(0,0,0);
				glTexCoord2d(1, 0);
				glVertex3f(length,0,0);
				glTexCoord2d(1, 1);
				glVertex3f(length,hight,0);
				glTexCoord2d(0, 1);
				glVertex3f(0,hight,0);
			glEnd();
		glDisable(GL_BLEND);
	glPopMatrix();
}