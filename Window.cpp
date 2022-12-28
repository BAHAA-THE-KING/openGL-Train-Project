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

Window::Window(Point bottom_left_back, float length, float hight, float angle_y,  int texture_window, int texture_cover, int texture_box)
{
	this->bottom_left_back=bottom_left_back;
	this->hight=hight;
	this->is_open=0;
	this->is_move=0;
	this->length=length;
	this->max_length=length/2.0+0.1;
	this->min_length=length/10.0+0.1;
	this->curr_length=max_length;
	this->interactive_distance=4;
	this->angle_y=angle_y;
	this->cover_change=0;
	this->phase=2;
	this->texture_cover=texture_cover;
	this->texture_window=texture_window;
	this->texture_box= texture_box;

}
void Window::DrawWindowGlass( )
{
	glPushMatrix();
		glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);
	
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

void Window::DrawWindowCover( bool *keys, Point pos)
{
	OpenCover(keys,  pos);
	if (is_move) 	Move();
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
			premitives::DrawCupe(Point(0.1,0,0.1),3*X_max,X_max,length-0.2,-1,1,1,1,1,0,1);
			glPushMatrix();
				glTranslated(2*X_max,0,0);
				for (float z=0; z<=curr_length; z+=0.1)
					{
						glBindTexture(GL_TEXTURE_2D,texture_cover);
						glBegin(GL_QUADS);
							glTexCoord2f((z)/(curr_length),0);
							glVertex3f(X_max*sin(phase*z),0,z);
							glTexCoord2f((z+0.1)/(curr_length),0);		
							glVertex3f(X_max*sin(phase*(z+0.1)),0,z+0.1);
							glTexCoord2f((z+0.1)/(curr_length),1);
							glVertex3f(X_max*sin(phase*(z+0.1)),-hight,z+0.1);
							glTexCoord2f((z)/(curr_length),1);
							glVertex3f(X_max*sin(phase*z),-hight,z);
						glEnd();
					}
				for (float z=length; z>=length-curr_length; z-=0.1)
					{
						glBindTexture(GL_TEXTURE_2D,texture_cover);
						glBegin(GL_QUADS);
							glTexCoord2f((z)/(curr_length),0);
							glVertex3f(X_max*sin(phase*z),0,z);
							glTexCoord2f((z+0.1)/(curr_length),0);		
							glVertex3f(X_max*sin(phase*(z+0.1)),0,z+0.1);
							glTexCoord2f((z+0.1)/(curr_length),1);
							glVertex3f(X_max*sin(phase*(z+0.1)),-hight,z+0.1);
							glTexCoord2f((z)/(curr_length),1);
							glVertex3f(X_max*sin(phase*z),-hight,z);
						glEnd();
					}
			glPopMatrix();

		
	glPopMatrix();
}

/*Point bottom_left_back;
	float length, hight, phase, max_length, min_length, curr_length, cover_change;
	bool is_open, is_move;
	int texture_window, texture_cover, texture_box;
	*/
void Window::Move()
{
	if (cover_change!=0)
	{
		curr_length+=cover_change;
	}
	else
	{
		if (curr_length<=min_length)
			cover_change=0.1;
		else 
			cover_change=-0.1;
		curr_length+=cover_change;
	}
	if(curr_length<min_length)
	{
		is_move=0;
		is_open=1;
		cover_change=0;
		curr_length=min_length;
	}
	else if(curr_length>max_length)
	{
		is_move=0;
		is_open=1;
		cover_change=0;
		curr_length=max_length;
	}
}

void Window::OpenCover(bool *keys, Point pos)
{
	if (keys['O'])
	{
		float temp =1;
		if (angle_y!=180) 
		{
			if (abs(pos.x-bottom_left_back.x)<interactive_distance && pos.x>bottom_left_back.x)
			{
				this->is_move=1;
			}
		}
		else
		{
			if (abs(pos.x-bottom_left_back.x)<interactive_distance  && pos.x<bottom_left_back.x)
			{
				this->is_move=1;
			}
		}
	}
}