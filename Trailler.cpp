#include "Trailler.h"
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include "texture.h"
#include "stdc++.h"
#include "Point.h"
#include "premitives.h"
#include "Wheel.h"
#include "Window.h"
#include "Door.h"

Trailler::Trailler(void)
{
}


Trailler::~Trailler(void)
{
}



Trailler::Trailler(Point bottom_left_back, float length, float hight, float depth,
					float door_length, float door_hight, bool door_is_right,
					float window_hight, bool window_is_left, bool window_is_right,
					float way_length, float way_hight, 
					float wheel_rad, float wheel_length, float wheel_width,
					int texture_body, int texture_cover, int texture_cover_box, int texture_window,
					int texture_door, int texture_fence, int texture_way, int texture_wheel, int texture_wheel_stick)
{
	this->bottom_left_back=bottom_left_back;
	this->length=length;
	this->hight= hight;
	this->depth=depth;
	this->way_length=way_length;
	this->way_hight=way_hight;
	this->texture_body=texture_body;
	this->texture_fence=texture_fence;
	this->texture_way=texture_way;
	//back
	door[0]=Door(Point ((length-door_length)/2,0,0),door_length, door_hight, texture_door, 0);
	//front
	door[1]=Door(Point ((length-door_length)/2,0,depth),door_length, door_hight, texture_door, 0);
	//right
	door[2]=Door(Point (length,0,depth),door_length, door_hight, texture_door, 90);
	if (!door_is_right)
	{
		door[2].length=0;
		door[2].hight=0;
	}
	//left
	window[0]=  Window(Point(0,(hight-window_hight)*2/3.0+window_hight,0),depth,window_hight,texture_window,texture_cover,texture_cover_box);
	if (!window_is_left)
	{
		window[0].length=0;
		window[0].hight=0;
	}
	//right
	window[1]= Window(Point(length,(hight-window_hight)*2/3.0+window_hight,0),depth-door[2].length,window_hight,texture_window,texture_cover,texture_cover_box);
	if (!window_is_right)
	{
		window[1].length=0;
		window[1].hight=0;
	}

	this->wheel.push_back ( *(new Wheel(Point(wheel_length/2,-wheel_rad,depth/4.0),wheel_rad,wheel_length,wheel_width,texture_wheel, texture_wheel_stick,length/2,-depth/2)));
	this->wheel.push_back ( *(new Wheel(Point(length-wheel_length/2,-wheel_rad,depth/4.0),wheel_rad,wheel_length,wheel_width,texture_wheel, texture_wheel_stick,-length/2,-depth/2)));
	this->wheel.push_back ( *(new Wheel(Point(length-wheel_length/2,-wheel_rad,3*depth/4.0),wheel_rad,wheel_length,wheel_width,texture_wheel, texture_wheel_stick,-length/2,depth/2)));
	this->wheel.push_back ( *(new Wheel(Point(wheel_length/2,-wheel_rad,3*depth/4.0),wheel_rad,wheel_length,wheel_width,texture_wheel, texture_wheel_stick,length/2,depth/2)));
	
}

void Trailler::DrawTop()
{
	glPushMatrix();
		glTranslated(0,hight,0);
		glBindTexture(GL_TEXTURE_2D,texture_body);
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(1,0);
			glVertex3f(length,0,0);

			glTexCoord2d(1,depth/length);
			glVertex3f(length,0,depth);

			glTexCoord2d(0,depth/length);
			glVertex3f(0,0,depth);
		glEnd();
	glPopMatrix();
}


void Trailler::DrawBottom()
{
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D,texture_body);
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(1,0);
			glVertex3f(length,0,0);

			glTexCoord2d(1,depth/length);
			glVertex3f(length,0,depth);

			glTexCoord2d(0,depth/length);
			glVertex3f(0,0,depth);
		glEnd();
	glPopMatrix();
}

void Trailler::DrawFront()
{
	glPushMatrix();
		door[1].DrawDoor();
		float door_length=door[1].length;
		float door_hight=door[1].hight;
		glTranslated(0,0,depth);
		float sub_length_wall = (length-door_length)/2.0;
		float sub_hight_wall = hight - door_hight;
		//wall
		glBindTexture(GL_TEXTURE_2D,texture_body);
		//left
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(sub_length_wall/length,0);
			glVertex3f(sub_length_wall,0,0);

			glTexCoord2d(sub_length_wall/length,1);
			glVertex3f(sub_length_wall,hight,0);

			glTexCoord2d(0,1);
			glVertex3f(0,hight,0);
		glEnd();

		glTranslated(sub_length_wall+door_length,0,0);
		//right
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(sub_length_wall/length,0);
			glVertex3f(sub_length_wall,0,0);

			glTexCoord2d(sub_length_wall/length,1);
			glVertex3f(sub_length_wall,hight,0);

			glTexCoord2d(0,1);
			glVertex3f(0,hight,0);
		glEnd();

		glTranslated(-door_length,door_hight,0);
		//up
		glBegin(GL_QUADS);
			glTexCoord2d(0,door_hight/hight);
			glVertex3f(0,0,0);

			glTexCoord2d(door_length/length,door_hight/hight);
			glVertex3f(door_length,0,0);

			glTexCoord2d(door_length/length,1);
			glVertex3f(door_length,sub_hight_wall,0);

			glTexCoord2d(0,1);
			glVertex3f(0,sub_hight_wall,0);
		glEnd();


	glPopMatrix();
}



void Trailler::DrawBack()
{
	glPushMatrix();
		door[0].DrawDoor();
		float door_length=door[0].length;
		float door_hight=door[0].hight;
		float sub_length_wall = (length-door_length)/2.0;
		float sub_hight_wall = hight - door_hight;
		//wall
		glBindTexture(GL_TEXTURE_2D,texture_body);
		//left
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(sub_length_wall/length,0);
			glVertex3f(sub_length_wall,0,0);

			glTexCoord2d(sub_length_wall/length,1);
			glVertex3f(sub_length_wall,hight,0);

			glTexCoord2d(0,1);
			glVertex3f(0,hight,0);
		glEnd();

		glTranslated(sub_length_wall+door_length,0,0);
		//right
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(sub_length_wall/length,0);
			glVertex3f(sub_length_wall,0,0);

			glTexCoord2d(sub_length_wall/length,1);
			glVertex3f(sub_length_wall,hight,0);

			glTexCoord2d(0,1);
			glVertex3f(0,hight,0);
		glEnd();

		glTranslated(-door_length,door_hight,0);
		//up
		glBegin(GL_QUADS);
			glTexCoord2d(0,door_hight/hight);
			glVertex3f(0,0,0);

			glTexCoord2d(door_length/length,door_hight/hight);
			glVertex3f(door_length,0,0);

			glTexCoord2d(door_length/length,1);
			glVertex3f(door_length,sub_hight_wall,0);

			glTexCoord2d(0,1);
			glVertex3f(0,sub_hight_wall,0);
		glEnd();

	glPopMatrix();
}

void Trailler::DrawLeft()
{
	glPushMatrix();
	window[0].DrawWindow(0);
	float window_hight=window[0].hight;
		float hight_down=(hight-window_hight)*2/3.0;
		float hight_up=hight-window_hight-hight_down;
		
		//down
		glBindTexture(GL_TEXTURE_2D,texture_body);
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(1,0);
			glVertex3f(0,0,depth);

			glTexCoord2d(1,hight_down/hight);
			glVertex3f(0,hight_down,depth);

			glTexCoord2d(0,hight_down/hight);
			glVertex3f(0,hight_down,0);
		glEnd();

		//up
		glTranslated(0,hight_down+window_hight,0);
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(1,0);
			glVertex3f(0,0,depth);

			glTexCoord2d(1,hight_up/hight);
			glVertex3f(0,hight_up,depth);

			glTexCoord2d(0,hight_up/hight);
			glVertex3f(0,hight_up,0);
		glEnd();


	glPopMatrix();
}

void Trailler::DrawRight()
{
	glPushMatrix();
	door[2].DrawDoor();
	float door_length=door[2].length;
	float door_hight=door[2].hight;
	
	window[1].DrawWindow(180);
	float window_hight=window[1].hight;
	glTranslated(length,0,0);

	glPushMatrix();
		//up door
		glBindTexture(GL_TEXTURE_2D,texture_body);
		glTranslated(0,door_hight,depth);
		glBegin(GL_QUADS);
			glTexCoord2d(1,door_hight/hight);
			glVertex3f(0,0,0);

			glTexCoord2d(1-door_length/length,door_hight/hight);
			glVertex3f(0,0,-door_length);

			glTexCoord2d(1-door_length/length,1);
			glVertex3f(0,hight-door_hight,-door_length);

			glTexCoord2d(1,1);
			glVertex3f(0,hight-door_hight,0);
		glEnd();
	glPopMatrix();

	float hight_down=(hight-window_hight)*2/3.0;
	float hight_up=hight-window_hight-hight_down;
	float old_depth=depth;
	depth=depth-door_length;
	//down
	glBindTexture(GL_TEXTURE_2D,texture_body);
	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(0,0,0);

		glTexCoord2d(1,0);
		glVertex3f(0,0,depth);

		glTexCoord2d(1,hight_down/hight);
		glVertex3f(0,hight_down,depth);

		glTexCoord2d(0,hight_down/hight);
		glVertex3f(0,hight_down,0);
	glEnd();

	//up
	glTranslated(0,hight_down+window_hight,0);
	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(0,0,0);

		glTexCoord2d(1,0);
		glVertex3f(0,0,depth);

		glTexCoord2d(1,hight_up/hight);
		glVertex3f(0,hight_up,depth);

		glTexCoord2d(0,hight_up/hight);
		glVertex3f(0,hight_up,0);
	glEnd();

	depth=old_depth;
	glPopMatrix();
}

void Trailler::DrawWay()
{
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D,texture_way);
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(1,0);
			glVertex3f(length,0,0);

			glTexCoord2d(1,way_length/length);
			glVertex3f(length,0,-way_length);

			glTexCoord2d(0,way_length/length);
			glVertex3f(0,0,-way_length);
		glEnd();

		glBindTexture(GL_TEXTURE_2D,texture_fence);
		//left
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(1,0);
			glVertex3f(0,0,-way_length);

			glTexCoord2d(1,1);
			glVertex3f(0,way_hight,-way_length);

			glTexCoord2d(0,1);
			glVertex3f(0,way_hight,0);
		glEnd();

		//right
		glPushMatrix();
			glTranslated(length,0,0);
			glBegin(GL_QUADS);
				glTexCoord2d(0,0);
				glVertex3f(0,0,0);

				glTexCoord2d(1,0);
				glVertex3f(0,0,-way_length);

				glTexCoord2d(1,1);
				glVertex3f(0,way_hight,-way_length);

				glTexCoord2d(0,1);
				glVertex3f(0,way_hight,0);
			glEnd();
		glPopMatrix();
		glTranslated(0,0,depth+way_length);
		glBindTexture(GL_TEXTURE_2D,texture_way);
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(1,0);
			glVertex3f(length,0,0);

			glTexCoord2d(1,way_length/length);
			glVertex3f(length,0,-way_length);

			glTexCoord2d(0,way_length/length);
			glVertex3f(0,0,-way_length);
		glEnd();

		glBindTexture(GL_TEXTURE_2D,texture_fence);
		//left
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(1,0);
			glVertex3f(0,0,-way_length);

			glTexCoord2d(1,1);
			glVertex3f(0,way_hight,-way_length);

			glTexCoord2d(0,1);
			glVertex3f(0,way_hight,0);
		glEnd();

		//right
		glTranslated(length,0,0);
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(1,0);
			glVertex3f(0,0,-way_length);

			glTexCoord2d(1,1);
			glVertex3f(0,way_hight,-way_length);

			glTexCoord2d(0,1);
			glVertex3f(0,way_hight,0);
		glEnd();
	glPopMatrix();
}



void Trailler::DrawTrailler()
{
	glPushMatrix();
		glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);
		DrawTop();
		DrawBottom();
		DrawFront();
		DrawBack();
		DrawLeft();
		DrawRight();
		DrawWay();
		for (int i=0; i<4; i++)
		{
			wheel[i].DrawWheel();
		}
	glPopMatrix();
}


