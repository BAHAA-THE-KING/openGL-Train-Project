#include "Trailer.h"
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

Trailer::Trailer(void)
{
}


Trailer::~Trailer(void)
{
}


Trailer::Trailer(Point bottom_left_back, float length, float depth, float hight,
				float door_length, float door_hight, bool door_is_on_side,
				float window_hight, bool window_is_on_left, bool window_is_on_right,
				float wheel_rad, float wheel_width, float wheel_depth,
				int texture_wheel, int texture_window, int texture_door, int texture_body, int texture_cover, int texture_cover_box)
{
	this->bottom_left_back=bottom_left_back;
	this->depth=depth;
	this->door_hight=door_hight;
	this->door_length=door_length;
	this->hight=hight;
	this->length=length;
	this->texture_body=texture_body;
	this->texture_cover=texture_cover;
	this->texture_cover_box= texture_cover_box;
	this->texture_door=texture_door;
	this->texture_wheel=texture_wheel;
	this->texture_window=texture_window;
	this->window_hight=window_hight;
	this->window_is_on_left=window_is_on_left;
	this->window_is_on_right=window_is_on_right;
	this->wheel[0]= Wheel(Point(length/4.0,-wheel_rad,wheel_depth/2.0),wheel_rad,wheel_depth,wheel_width,texture_wheel);
	this->wheel[1]= Wheel(Point(3*length/4.0,-wheel_rad,wheel_depth/2.0),wheel_rad,wheel_depth,wheel_width,texture_wheel);
	this->wheel[2]= Wheel(Point(length/4.0,-wheel_rad,depth-wheel_depth/2.0),wheel_rad,wheel_depth,wheel_width,texture_wheel);
	this->wheel[3]= Wheel(Point(length/4.0,-wheel_rad,wheel_depth/2.0),wheel_rad,wheel_depth,wheel_width,texture_wheel);
	this->d[0]=Door(Point((length-door_length)/2,0,0),door_length,door_hight,texture_door);
	this->d[1]=Door(Point((length-door_length)/2,0,depth),door_length,door_hight,texture_door);
	if (door_is_on_side)
	{
		this->d[2]=Door(Point(length,0,0),door_length,door_hight,texture_door);
		d[2].angle=-90;
	}
	else
	{
		this->d[2]=Door(Point(length,0,0),0,0,-1);
		d[2].angle=-90;
	}
}
void Trailer::DrawTrailer()
{
	glPushMatrix();
		glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);
		
		//top
		glBindTexture(GL_TEXTURE_2D,texture_body);
		glColor3f(1,1,1);
		glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex3f(0,hight,0);
		
			glTexCoord2f(1,0);
			glVertex3f(length,hight,0);
		
			glTexCoord2f(1,length/hight);
			glVertex3f(length,hight,depth);
		
			glTexCoord2f(0,length/hight);
			glVertex3f(0,hight,depth);
		glEnd();


		//bottom
		glBindTexture(GL_TEXTURE_2D,texture_body);
		glColor3f(1,1,1);
		glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex3f(0,0,0);
		
			glTexCoord2f(1,0);
			glVertex3f(length,0,0);
		
			glTexCoord2f(1,length/hight);
			glVertex3f(length,0,depth);
		
			glTexCoord2f(0,length/hight);
			glVertex3f(0,0,depth);
		glEnd();



		//front
		d[0].DrawDoor();
		glBindTexture(GL_TEXTURE_2D,texture_body);
		glColor3f(1,1,1);
		//left
		glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex3f(0,0,0);
		
			glTexCoord2f((length-door_length)/length,0);
			glVertex3f((length-door_length)/2,0,0);
		
			glTexCoord2f((length-door_length)/length,1);
			glVertex3f((length-door_length)/2,hight,0);
		
			glTexCoord2f(0,1);
			glVertex3f(0,hight,0);
		glEnd();

		//right
		glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex3f(length-(length-door_length)/2,0,0);
		
			glTexCoord2f((length-door_length)/length,0);
			glVertex3f(length,0,0);
		
			glTexCoord2f((length-door_length)/length,1);
			glVertex3f(length,hight,0);
		
			glTexCoord2f(0,1);
			glVertex3f(length-(length-door_length)/2,hight,0);
		glEnd();

		//up
		glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex3f((length-door_length)/2,0,0);
		
			glTexCoord2f((door_length)/length,0);
			glVertex3f(length-(length-door_length)/2,0,0);
		
			glTexCoord2f((door_length)/length,(door_hight)/hight);
			glVertex3f(length-(length-door_length)/2,door_hight,0);
		
			glTexCoord2f(0,(door_hight)/hight);
			glVertex3f((length-door_length)/2,door_hight,0);
		glEnd();



		//back
		d[1].DrawDoor();
		glPushMatrix();
			glTranslated(0,0,depth);
			glBindTexture(GL_TEXTURE_2D,texture_body);
			glColor3f(1,1,1);

			//left
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);
				glVertex3f(0,0,0);
		
				glTexCoord2f((length-door_length)/length,0);
				glVertex3f((length-door_length)/2,0,0);
		
				glTexCoord2f((length-door_length)/length,1);
				glVertex3f((length-door_length)/2,hight,0);
		
				glTexCoord2f(0,1);
				glVertex3f(0,hight,0);
			glEnd();

			//right
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);
				glVertex3f(length-(length-door_length)/2,0,0);
		
				glTexCoord2f((length-door_length)/length,0);
				glVertex3f(length,0,0);
		
				glTexCoord2f((length-door_length)/length,1);
				glVertex3f(length,hight,0);
		
				glTexCoord2f(0,1);
				glVertex3f(length-(length-door_length)/2,hight,0);
			glEnd();

			//up
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);
				glVertex3f((length-door_length)/2,0,0);
		
				glTexCoord2f((door_length)/length,0);
				glVertex3f(length-(length-door_length)/2,0,0);
		
				glTexCoord2f((door_length)/length,(door_hight)/hight);
				glVertex3f(length-(length-door_length)/2,door_hight,0);
		
				glTexCoord2f(0,(door_hight)/hight);
				glVertex3f((length-door_length)/2,door_hight,0);
			glEnd();
		glPopMatrix();


		//left
		if (!window_is_on_left)
		{
			glBindTexture(GL_TEXTURE_2D,texture_body);
			glColor3f(1,1,1);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);
				glVertex3f(0,0,0);
		
				glTexCoord2f(1,0);
				glVertex3f(0,0,depth);
		
				glTexCoord2f(1,1);
				glVertex3f(0,hight,depth);
		
				glTexCoord2f(0,1);
				glVertex3f(0,hight,0);
			glEnd();
		}
		else
		{
			float hight_down=(hight-window_hight)*2/3.0;
			float hight_up=hight-window_hight-hight_down;
			//down
			glBindTexture(GL_TEXTURE_2D,texture_body);
			glColor3f(1,1,1);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);
				glVertex3f(0,0,0);
		
				glTexCoord2f(1,0);
				glVertex3f(0,0,depth);
		
				glTexCoord2f(1,hight_down/hight);
				glVertex3f(0,hight_down,depth);
		
				glTexCoord2f(0,hight_down/hight);
				glVertex3f(0,hight_down,0);
			glEnd();


			//window
			glTranslated(0,hight_down,0);
			Window::Window(Point (0,0,0),length,window_hight,texture_window,texture_cover,texture_cover_box);
			/*
			glEnable(GL_BLEND);
			glColor4f(1,1,1,0.5);
			glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D,texture_window);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);
				glVertex3f(0,0,0);
		
				glTexCoord2f(1,0);
				glVertex3f(0,0,depth);
		
				glTexCoord2f(1,1);
				glVertex3f(0,window_hight,depth);
		
				glTexCoord2f(0,1);
				glVertex3f(0,window_hight,0);
			glEnd();
			glDisable(GL_BLEND);*/


			//up
			glTranslated(0,window_hight,0);
			glBindTexture(GL_TEXTURE_2D,texture_body);
			glColor3f(1,1,1);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);
				glVertex3f(0,0,0);
		
				glTexCoord2f(1,0);
				glVertex3f(0,0,depth);
		
				glTexCoord2f(1,hight_up/hight);
				glVertex3f(0,hight_up,depth);
		
				glTexCoord2f(0,hight_up/hight);
				glVertex3f(0,hight_up,0);
			glEnd();

		}



		//right
		d[2].DrawDoor();
		glTranslated(d[2].bottom_left.x,d[2].bottom_left.y,d[2].bottom_left.z);
		//up
		glBegin(GL_QUADS);
			glTexCoord2f(0,0);
			glVertex3f(0,door_hight,0);
		
			glTexCoord2f((door_length)/length,0);
			glVertex3f(0,door_hight,-door_length);
		
			glTexCoord2f((door_length)/length,(door_hight)/hight);
			glVertex3f(0,hight,-door_length);
		
			glTexCoord2f(0,(door_hight)/hight);
			glVertex3f(0,hight,0);
		glEnd();
		float old_depth=depth;
		depth-=door_length;
		glTranslated(0,0,-door_length);
		if (!window_is_on_left)
		{
			glBindTexture(GL_TEXTURE_2D,texture_body);
			glColor3f(1,1,1);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);
				glVertex3f(0,0,0);
		
				glTexCoord2f(1,0);
				glVertex3f(0,0,depth);
		
				glTexCoord2f(1,1);
				glVertex3f(0,hight,depth);
		
				glTexCoord2f(0,1);
				glVertex3f(0,hight,0);
			glEnd();
		}
		else
		{
			float hight_down=(hight-window_hight)*2/3.0;
			float hight_up=hight-window_hight-hight_down;
			//down
			glBindTexture(GL_TEXTURE_2D,texture_body);
			glColor3f(1,1,1);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);
				glVertex3f(0,0,0);
		
				glTexCoord2f(1,0);
				glVertex3f(0,0,depth);
		
				glTexCoord2f(1,hight_down/hight);
				glVertex3f(0,hight_down,depth);
		
				glTexCoord2f(0,hight_down/hight);
				glVertex3f(0,hight_down,0);
			glEnd();


			//window
			glTranslated(0,hight_down,0);
			Window::Window(Point (0,0,0),length,window_hight,texture_window,texture_cover,texture_cover_box);
			/*
			glEnable(GL_BLEND);
			glColor4f(1,1,1,0.5);
			glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
			glBindTexture(GL_TEXTURE_2D,texture_window);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);
				glVertex3f(0,0,0);
		
				glTexCoord2f(1,0);
				glVertex3f(0,0,depth);
		
				glTexCoord2f(1,1);
				glVertex3f(0,window_hight,depth);
		
				glTexCoord2f(0,1);
				glVertex3f(0,window_hight,0);
			glEnd();
			glDisable(GL_BLEND);*/


			//up
			glTranslated(0,window_hight,0);
			glBindTexture(GL_TEXTURE_2D,texture_body);
			glColor3f(1,1,1);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);
				glVertex3f(0,0,0);
		
				glTexCoord2f(1,0);
				glVertex3f(0,0,depth);
		
				glTexCoord2f(1,hight_up/hight);
				glVertex3f(0,hight_up,depth);
		
				glTexCoord2f(0,hight_up/hight);
				glVertex3f(0,hight_up,0);
			glEnd();

		}
		depth=old_depth;

	glPopMatrix();
}