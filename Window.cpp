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
			glTranslated(0,0,-length);
		}
		glPushMatrix();
				//cover
			float X_max=0.3;
			float phase=1;
			premitives::DrawCupe(Point(0.1,0,0.1),3*X_max,X_max,length-0.2,-1,1,1,1,1,0,1);
			glPushMatrix();
				glTranslated(2*X_max,0,0);
				for (float z=0; z<=length; z+=0.1)
					{
						glBindTexture(GL_TEXTURE_2D,texture_cover);
						glBegin(GL_QUADS);
							glTexCoord2f(0,0);
							glVertex3f(X_max*sin(phase*z),0,z);
							glTexCoord2f(1,0);		
							glVertex3f(X_max*sin(phase*(z+0.1)),0,z+0.1);
							glTexCoord2f(1,1);
							glVertex3f(X_max*sin(phase*(z+0.1)),-hight,z+0.1);
							glTexCoord2f(0,1);
							glVertex3f(X_max*sin(phase*z),-hight,z);
						glEnd();
					}
			glPopMatrix();

			//window
			glTranslated(0,-hight,0);
			glEnable(GL_BLEND);
				glColor4f(1,1,1,0.5);
				glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D,texture_window);
				glBegin(GL_QUADS);
					glTexCoord2d(0, 0);
					glVertex3f(0,0,0);
					glTexCoord2d(1, 0);
					glVertex3f(0,0,length);
					glTexCoord2d(1, 1);
					glVertex3f(0,hight,length);
					glTexCoord2d(0, 1);
					glVertex3f(0,hight,0);
				glEnd();
			glDisable(GL_BLEND);
			
	glPopMatrix();
}