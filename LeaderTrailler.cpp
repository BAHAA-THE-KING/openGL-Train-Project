#include "LeaderTrailler.h"

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
#include "Trailler.h"
#include "Door.h"


using namespace std;

LeaderTrailler::LeaderTrailler(void)
{
}


LeaderTrailler::~LeaderTrailler(void)
{
}

	

LeaderTrailler::LeaderTrailler(Point bottom_left_back, float length, float hight_cube, float hight_dome, float depth_cube,
				float depth_face,  float depth_coal, float length_coal, 
				float Holocaust_length, float Holocaust_hight_cube, float Holocaust_depth, int Holocaust_fire_count,
				float door_length, float door_hight,
				float wheel_rad, float wheel_length,float wheel_width,
				int texture_body, int texture_glass, int texture_door,int texture_smoke , int texture_coal,
				int texture_holocaust_cube, int texture_holocaust_cylinder, int texture_holocaust_door, int texture_holocaust_fire[],
				int texture_wheel, int texture_wheel_stick, int texture_control_panel, int texture_iron)
{
	this->bottom_left_back=bottom_left_back;
	this->length=length;
	this->hight_cube=hight_cube;
	this->hight_dome=hight_dome;
	this->depth_cube=depth_cube;
	this->depth_face=depth_face;
	this->depth_coal=depth_coal;
	this->length_coal=length_coal;
	this->Holocaust_bottom_left_back=Point(length-Holocaust_length-length/20.0,0,depth_cube*0.8-Holocaust_depth);
	this->Holocaust_length=Holocaust_length;
	this->Holocaust_hight_cube=Holocaust_hight_cube;
	this->Holocaust_depth=Holocaust_depth;
	this->Holocaust_fire_count=Holocaust_fire_count;
	this->texture_body=texture_body;
	this->texture_glass=texture_glass;
	this->texture_holocaust_cube=texture_holocaust_cube;
	this->texture_holocaust_cylinder=texture_holocaust_cylinder;
	this->texture_holocaust_door=texture_holocaust_door;
	this->texture_holocaust_fire=texture_holocaust_fire;
	this->texture_smoke=texture_smoke;
	this->texture_coal=texture_coal;
	this->texture_control_panel=texture_control_panel;
	this->texture_iron=texture_iron;
	this->d=Door(Point(length,0,0),door_length,door_hight,texture_door,-90,1);
	this->d_holo=Door(Point (Holocaust_bottom_left_back.x,Holocaust_bottom_left_back.y+Holocaust_hight_cube/4.0,Holocaust_bottom_left_back.z+Holocaust_depth/4.0),
						Holocaust_depth/2.0,Holocaust_hight_cube/2.0,texture_holocaust_door,-90,-1);
	this->hight_face=hight_cube/3.0;
	this->Holocaust_fire_curr=0;
	this->length_way=length-length_coal;
	this->Holocaust_hight_cylinder=(hight_cube+hight_dome)*1.1-Holocaust_hight_cube;
	this->Holocaust_rad_cylinder=min(Holocaust_depth,Holocaust_length)/4.0;


	this->wheel.push_back ( *(new Wheel(Point(wheel_length/2,-wheel_rad,depth_cube/4.0),wheel_rad,wheel_length,wheel_width,texture_wheel, texture_wheel_stick,length/2,-depth_cube/2)));
	this->wheel.push_back ( *(new Wheel(Point(length-wheel_length/2,-wheel_rad,depth_cube/4.0),wheel_rad,wheel_length,wheel_width,texture_wheel, texture_wheel_stick,-length/2,-depth_cube/2)));
	this->wheel.push_back ( *(new Wheel(Point(length-wheel_length/2,-wheel_rad,3*depth_cube/4.0),wheel_rad,wheel_length,wheel_width,texture_wheel, texture_wheel_stick,-length/2,depth_cube/2)));
	this->wheel.push_back ( *(new Wheel(Point(wheel_length/2,-wheel_rad,3*depth_cube/4.0),wheel_rad,wheel_length,wheel_width,texture_wheel, texture_wheel_stick,length/2,depth_cube/2)));

	this->wheel.push_back ( *(new Wheel(Point(wheel_length/2,-wheel_rad,depth_cube+depth_coal/4.0),wheel_rad,wheel_length,wheel_width,texture_wheel, texture_wheel_stick,length/2,-depth_coal/2)));
	this->wheel.push_back ( *(new Wheel(Point(length-wheel_length/2,-wheel_rad,depth_cube+depth_coal/4.0),wheel_rad,wheel_length,wheel_width,texture_wheel, texture_wheel_stick,-length/2,-depth_coal/2)));
	this->wheel.push_back ( *(new Wheel(Point(length-wheel_length/2,-wheel_rad,depth_cube+3*depth_coal/4.0),wheel_rad,wheel_length,wheel_width,texture_wheel, texture_wheel_stick,-length/2,depth_coal/2)));
	this->wheel.push_back ( *(new Wheel(Point(wheel_length/2,-wheel_rad,depth_cube+3*depth_coal/4.0),wheel_rad,wheel_length,wheel_width,texture_wheel, texture_wheel_stick,length/2,depth_coal/2)));
	



	this->safety_distance = 0.4;
}
	


void LeaderTrailler::DrawBottom()
{
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D,texture_body);
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(1,0);
			glVertex3f(length,0,0);

			glTexCoord2d(1,depth_cube/length);
			glVertex3f(length,0,depth_cube);

			glTexCoord2d(0,depth_cube/length);
			glVertex3f(0,0,depth_cube);
		glEnd();
	glPopMatrix();;
}

void LeaderTrailler::DrawLeft()
{
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D,texture_body);
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(0,1);
			glVertex3f(0,hight_cube,0);

			glTexCoord2d(1,1);
			glVertex3f(0,hight_cube,depth_cube);

			glTexCoord2d(1,0);
			glVertex3f(0,0,depth_cube);
		glEnd();
	glPopMatrix();;
}

void LeaderTrailler::DrawRight(bool *keys, Point pos)
{
	glPushMatrix();
		d.DrawDoor( keys,  pos);
		float door_length=d.length;
		float door_hight=d.hight;
	
		glTranslated(length,0,0);

		glPushMatrix();
			//up door
			glBindTexture(GL_TEXTURE_2D,texture_body);
			glTranslated(0,door_hight,0);
			glBegin(GL_QUADS);
				glTexCoord2d(1,door_hight/hight_cube);
				glVertex3f(0,0,0);

				glTexCoord2d(1-door_length/length,door_hight/hight_cube);
				glVertex3f(0,0,door_length);

				glTexCoord2d(1-door_length/length,1);
				glVertex3f(0,hight_cube-door_hight,door_length);

				glTexCoord2d(1,1);
				glVertex3f(0,hight_cube-door_hight,0);
			glEnd();
		glPopMatrix();
		glTranslated(0,0,door_length);
		glBindTexture(GL_TEXTURE_2D,texture_body);
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex3f(0,0,0);

			glTexCoord2d(0,1);
			glVertex3f(0,hight_cube,0);

			glTexCoord2d(1,1);
			glVertex3f(0,hight_cube,depth_cube-door_length);
			
			glTexCoord2d(1,0);
			glVertex3f(0,0,depth_cube-door_length);
		glEnd();
	

	glPopMatrix();
}

void LeaderTrailler::DrawTop()
{
	glPushMatrix();


	glTranslated(0,hight_cube,0);
	float  x1=0.1, y1=hight_dome*sin(3.14/length*x1), x2=0, y2=hight_dome*sin(3.14/length*x2);
	while(x1 <=length+0.1)
	{

			Point a= Point (x1,y1,0);
			Point b= Point (x1,y1,depth_cube);
			Point c= Point (x2,y2,depth_cube);
			Point d= Point (x2,y2,0);
			
			glBindTexture(GL_TEXTURE_2D,texture_body);
			glBegin(GL_QUADS);

			glTexCoord2f(x1/length,0);
			glVertex3f(a.x,a.y,a.z);
			
			glTexCoord2f(x1/length,depth_cube/length);
			glVertex3f(b.x,b.y,b.z);
			
			glTexCoord2f(x2/length,depth_cube/length);
			glVertex3f(c.x,c.y,c.z);
			
			glTexCoord2f(x2/length,0);
			glVertex3f(d.x,d.y,d.z);

			glEnd();


			x2+=0.1;
			x1+=0.1;
			y1=hight_dome*sin(3.14/length*x1);
			y2=hight_dome*sin(3.14/length*x2);
	}

	 x1=0.1, y1=hight_dome*sin(3.14/length*x1);
	 glBindTexture(GL_TEXTURE_2D,texture_body);
	 glBegin(GL_POLYGON);
		while(x1 <=length+0.1)
		{

			Point a= Point (x1,y1,0);
			
			glTexCoord2f(a.x/length,a.y/hight_cube);
			glVertex3f(a.x,a.y,a.z);
			


			x1+=0.1;
			y1=hight_dome*sin(3.14/length*x1);
		}
	glEnd();



	glTranslated(0,0,depth_cube);
	x1=0.1, y1=hight_dome*sin(3.14/length*x1);
	 glBindTexture(GL_TEXTURE_2D,texture_body);
	 glBegin(GL_POLYGON);
		while(x1 <=length+0.1)
		{

			Point a= Point (x1,y1,0);
			
			glTexCoord2f(a.x/length,a.y/hight_cube);
			glVertex3f(a.x,a.y,a.z);
			


			x1+=0.1;
			y1=hight_dome*sin(3.14/length*x1);
		}
	glEnd();

	glPopMatrix();
}

void LeaderTrailler::DrawBack()
{
	glPushMatrix();
	float  x1=0.1, z1=-depth_face*sin(3.14/length*x1), x2=0, z2=-depth_face*sin(3.14/length*x2);
	while(x1 <=length+0.1)
	{

			Point a= Point (x1,0,z1);
			Point b= Point (x2,0,z2);
			Point c= Point (x2,hight_face,z2);
			Point d= Point (x1,hight_face,z1);
			Point e= Point (x2,hight_cube,z2);
			Point f= Point (x1,hight_cube,z1);

			
			glBindTexture(GL_TEXTURE_2D,texture_body);
			glBegin(GL_QUADS);

			glTexCoord2f(a.x/length,a.y/hight_cube);
			glVertex3f(a.x,a.y,a.z);
			
			glTexCoord2f(b.x/length,b.y/hight_cube);
			glVertex3f(b.x,b.y,b.z);
			
			glTexCoord2f(c.x/length,c.y/hight_cube);
			glVertex3f(c.x,c.y,c.z);
			
			glTexCoord2f(d.x/length,d.y/hight_cube);
			glVertex3f(d.x,d.y,d.z);

			glEnd();

			x2+=0.1;
			x1+=0.1;
			z1=-depth_face*sin(3.14/length*x1);
			z2=-depth_face*sin(3.14/length*x2);
	}


	 x1=0, z1=-depth_face*sin(3.14/length*x1);
	 glBindTexture(GL_TEXTURE_2D,texture_body);
	 glBegin(GL_POLYGON);
		while(x1 <=length+0.1)
		{

			Point a= Point (x1,0,z1);
			
			glTexCoord2f(a.x/length,a.z/(length));
			glVertex3f(a.x,a.y,a.z);
			


			x1+=0.1;
			z1=-depth_face*sin(3.14/length*x1);
		}
	glEnd();

	glEnable(GL_BLEND);
	glColor4f(1,1,1,0.5);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
			

		x1=0.1, z1=-depth_face*sin(3.14/length*x1), x2=0, z2=-depth_face*sin(3.14/length*x2);
		while(x1 <=length+0.1)
		{

			Point a= Point (x1,0,z1);
			Point b= Point (x2,0,z2);
			Point c= Point (x2,hight_face,z2);
			Point d= Point (x1,hight_face,z1);
			Point e= Point (x2,hight_cube,z2);
			Point f= Point (x1,hight_cube,z1);

			
			
		
			glBindTexture(GL_TEXTURE_2D,texture_glass);
			glBegin(GL_QUADS);

				glTexCoord2f(d.x/length,d.y/hight_cube);
				glVertex3f(d.x,d.y,d.z);
			
				glTexCoord2f(c.x/length,c.y/hight_cube);
				glVertex3f(c.x,c.y,c.z);
			
				glTexCoord2f(e.x/length,e.y/hight_cube);
				glVertex3f(e.x,e.y,e.z);
			
				glTexCoord2f(f.x/length,f.y/hight_cube);
				glVertex3f(f.x,f.y,f.z);
			glEnd();


			x2+=0.1;
			x1+=0.1;
			z1=-depth_face*sin(3.14/length*x1);
			z2=-depth_face*sin(3.14/length*x2);
		}
	glDisable(GL_BLEND);

	glBindTexture(GL_TEXTURE_2D, texture_body);
	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3d(0,0,0);

		glTexCoord2d(1,0);
		glVertex3d(length,0,0);

		glTexCoord2d(1,hight_face/hight_cube);
		glVertex3d(length,hight_face,0);

		glTexCoord2d(0,hight_face/hight_cube);
		glVertex3d(0,hight_face,0);
	glEnd();


	glTranslated(0,hight_face,0);

	 x1=0, z1=-depth_face*sin(3.14/length*x1);
	 glBindTexture(GL_TEXTURE_2D,texture_body);
	 glBegin(GL_POLYGON);
		while(x1 <=length+0.1)
		{

			Point a= Point (x1,0,z1);
			
			glTexCoord2f(a.x/length,a.z/(length));
			glVertex3f(a.x,a.y,a.z);
			


			x1+=0.1;
			z1=-depth_face*sin(3.14/length*x1);
		}
	glEnd();


	glDisable(GL_DEPTH_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D,texture_control_panel);
	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3d(length/4.0,0,0);

		glTexCoord2d(1,0);
		glVertex3d(3*length/4.0,0,0);

		glTexCoord2d(1,1);
		glVertex3d(3*length/4.0,0,-depth_face*sin(3.14/length*(3*length/4.0)));

		glTexCoord2d(0,1);
		glVertex3d(length/4.0,0,-depth_face*sin(3.14/length*(length/4.0)));
	glEnd();

	
	glEnable(GL_DEPTH_BUFFER_BIT);



	glTranslated(0,hight_cube-hight_face,0);
	 x1=0, z1=-depth_face*sin(3.14/length*x1);
	 glBindTexture(GL_TEXTURE_2D,texture_body);
	 glBegin(GL_POLYGON);
		while(x1 <=length+0.1)
		{

			Point a= Point (x1,0,z1);
			
			glTexCoord2f(a.x/length,a.z/(length));
			glVertex3f(a.x,a.y,a.z);
			


			x1+=0.1;
			z1=-depth_face*sin(3.14/length*x1);
		}
	glEnd();



	glTranslated(length/4.0,0,depth_cube/10);
	glRotated(-90,1,0,0);
	premitives::DrawCylinderBody(Point(0,0,hight_dome*sin(3.14/length*(length/4.0))), 0.2, 0.2, -3-hight_dome*sin(3.14/length*(length/4.0)), texture_iron);
	glRotated(90,1,0,0);
	glTranslated(0,-4,0);
	premitives::DrawRing(Point(0,0,0), 1,0.5,texture_iron);

	glPopMatrix();

}


void LeaderTrailler::DrawHolocaust(bool *keys, Point pos)
{
	glPushMatrix();
		d_holo.DrawDoor(keys,  pos);
		glTranslated(Holocaust_bottom_left_back.x,Holocaust_bottom_left_back.y,Holocaust_bottom_left_back.z);
		premitives::DrawCupe(Point (0,0,0),Holocaust_length,Holocaust_hight_cube,Holocaust_depth,texture_holocaust_cube,1,1,1,0,1,1);
		glBindTexture(GL_TEXTURE_2D,texture_holocaust_cube);
		float l=Holocaust_length, h=Holocaust_hight_cube, d=Holocaust_depth;
		glBegin(GL_QUADS);
			//bottom
			glTexCoord2f(0,0);
			glVertex3f(0,0,0);
		
			glTexCoord2f(1,0);
			glVertex3f(0,0,d);

			glTexCoord2f(1,0.25);
			glVertex3f(0,h/4.0,d);

			glTexCoord2f(0,0.25);
			glVertex3f(0,h/4.0,0);

		glEnd();
		glBegin(GL_QUADS);


		

			//up
			glTexCoord2f(0,0.75);
			glVertex3f(0,h*0.75,0);

			glTexCoord2f(1,0.75);
			glVertex3f(0,h*0.75,d);

			glTexCoord2f(1,1);
			glVertex3f(0,h,d);

			glTexCoord2f(0,1);
			glVertex3f(0,h,0);


		glEnd();
		glBegin(GL_QUADS);
		

			//left
			glTexCoord2f(0,0.25);
			glVertex3f(0,h*0.25,0);

			glTexCoord2f(0.25,0.25);
			glVertex3f(0,h*0.25,d*0.25);

			glTexCoord2f(0.25,0.75);
			glVertex3f(0,h*0.75,d*0.25);

			glTexCoord2f(0,0.75);
			glVertex3f(0,h*0.75,0);


		glEnd();
		glBegin(GL_QUADS);
		

			//right
			glTexCoord2f(0.75,0.25);
			glVertex3f(0,h*0.25,0.75*d);

			glTexCoord2f(1,0.25);
			glVertex3f(0,h*0.25,d);

			glTexCoord2f(1,0.75);
			glVertex3f(0,h*0.75,d);

			glTexCoord2f(0.75,0.75);
			glVertex3f(0,h*0.75,0.75*d);


		glEnd();



		if (d_holo.angle!=d_holo.angle_max)
		{
			Holocaust_fire_curr=Holocaust_fire_curr%(Holocaust_fire_count*5);
			glBindTexture(GL_TEXTURE_2D,texture_holocaust_fire[(Holocaust_fire_curr++)/5]);
			glBegin(GL_QUADS);
				glTexCoord2f(0,0);
				glVertex3f(0,h*0.25,d*0.25);
			
				glTexCoord2f(1,0);
				glVertex3f(0,h*0.25,d*0.75);

				glTexCoord2f(1,1);
				glVertex3f(0,h*0.75,d*0.75);

				glTexCoord2f(0,1);
				glVertex3f(0,h*0.75,d*0.25);
			glEnd();

		}

		glTranslated(l/2.0,h,d/2.0);
		glPushMatrix();
			glRotated(-90,1,0,0);
			premitives::DrawCylinderBody(Point (0,0,0), Holocaust_rad_cylinder,Holocaust_rad_cylinder,Holocaust_hight_cylinder,texture_holocaust_cylinder);
		glPopMatrix();
	
	glPopMatrix();
}

void LeaderTrailler::DrawCoalTrailler()
{
	glPushMatrix();
	glTranslated(0,0,depth_cube);
	glBindTexture(GL_TEXTURE_2D,texture_body);
	glBegin(GL_QUADS);
	//left
		glTexCoord2d(0,0);
		glVertex3f(0,0,0);

		glTexCoord2d(1,0);
		glVertex3f(0,0,depth_coal);

		glTexCoord2d(1,1);
		glVertex3f(0,hight_cube,depth_coal);

		glTexCoord2d(0,1);
		glVertex3f(0,hight_cube,0);

	//right
		glTexCoord2d(0,0);
		glVertex3f(length,0,0);

		glTexCoord2d(1,0);
		glVertex3f(length,0,depth_coal);

		glTexCoord2d(1,1);
		glVertex3f(length,hight_cube,depth_coal);

		glTexCoord2d(0,1);
		glVertex3f(length,hight_cube,0);



	//bottom
		glTexCoord2d(0,0);
		glVertex3f(0,0,0);

		glTexCoord2d(1,0);
		glVertex3f(length,0,0);

		glTexCoord2d(1,depth_coal/hight_cube);
		glVertex3f(length,0,depth_coal);

		glTexCoord2d(0,depth_coal/hight_cube);
		glVertex3f(0,0,depth_coal);


	//top
		glTexCoord2d(0,0);
		glVertex3f(0,hight_cube,0);

		glTexCoord2d(length_way/length,0);
		glVertex3f(length_way,hight_cube,0);

		glTexCoord2d(length_way/length,depth_coal/hight_cube);
		glVertex3f(length_way,hight_cube,depth_coal);

		glTexCoord2d(0,depth_coal/hight_cube);
		glVertex3f(0,hight_cube,depth_coal);


	//front
		glTexCoord2d(length_way/length,0);
		glVertex3f(length_way,0,depth_coal);

		glTexCoord2d(1,0);
		glVertex3f(length,0,depth_coal);
		
		glTexCoord2d(1,1);
		glVertex3f(length,hight_cube,depth_coal);
		
		glTexCoord2d(length_way/length,1);
		glVertex3f(length_way,hight_cube,depth_coal);

	//back
		glTexCoord2d(length_way/length,0);
		glVertex3f(length_way,0,0);

		glTexCoord2d(1,0);
		glVertex3f(length,0,0);
		
		glTexCoord2d(1,0.25);
		glVertex3f(length,hight_cube*0.25,0);
		
		glTexCoord2d(length_way/length,0.25);
		glVertex3f(length_way,hight_cube*0.25,0);

	//betwen
		glTexCoord2d(0,0);
		glVertex3f(length_way,0,0);

		glTexCoord2d(1,0);
		glVertex3f(length_way,0,depth_coal);

		glTexCoord2d(1,1);
		glVertex3f(length_way,hight_cube,depth_coal);

		glTexCoord2d(0,1);
		glVertex3f(length_way,hight_cube,0);

	glEnd();
	glTranslated(length_way,0,0);
	
	
	glBindTexture(GL_TEXTURE_2D,texture_coal);
	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(0,hight_cube/4.0,0);

		glTexCoord2d(1,0);
		glVertex3f(length_coal,hight_cube/4.0,0);
		
		glTexCoord2d(1,1);
		glVertex3f(length_coal,hight_cube,depth_coal);
		
		glTexCoord2d(0,1);
		glVertex3f(0,hight_cube,depth_coal);
	glEnd();
	


	glPopMatrix();
}




void LeaderTrailler::DrawLeaderTrailler(bool *keys, Point pos)
{
	glPushMatrix();
		glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);
		DrawBottom();
		DrawLeft();
		DrawRight(keys,  pos);
		DrawTop();
		DrawHolocaust(keys,  pos);
		DrawCoalTrailler();
		DrawBack();
		glDisable(GL_BLEND);
		for(int i=0; i<8; i++)
			wheel[i].DrawWheel();					
	glPopMatrix();
}






















/***********Collision**************/

bool LeaderTrailler::CollisionTop(Point pos){
	if (pos.x>0-safety_distance && pos.x<length+safety_distance 
		&& pos.y>hight_cube-safety_distance && pos.y<hight_cube+safety_distance 
		&& pos.z>0-depth_face-safety_distance && pos.z<depth_cube+depth_coal+safety_distance)
		return 0;
	return 1;
}
bool LeaderTrailler::CollisionBottom(Point pos){
	if (pos.x>-safety_distance && pos.x<length+safety_distance 
		&& pos.y>0-safety_distance && pos.y<0+safety_distance
		&& pos.z>0-depth_face-safety_distance && pos.z<depth_coal+depth_cube+safety_distance)
		return 0;
	return 1;
}
bool LeaderTrailler::CollisionLeft(Point pos){
	if (pos.x>0-safety_distance && pos.x<0+safety_distance 
		&& pos.y>0-safety_distance && pos.y<hight_cube+safety_distance 
		&& pos.z>0-safety_distance && pos.z<depth_cube+depth_coal+safety_distance)
		return 0;
	return 1;
}
bool LeaderTrailler::CollisionRight(Point pos){
	if (pos.x>length-safety_distance && pos.x<length+safety_distance 
		&& pos.y>0-safety_distance && pos.y<hight_cube+safety_distance 
		&& pos.z>0-safety_distance && pos.z<depth_cube+depth_coal+safety_distance)
	{
		if (pos.z<d.length && pos.z>0 && d.is_open)
			return 1;
		return 0;
	}
		
	return 1;
}
bool LeaderTrailler::CollisionBack(Point pos){
	if (pos.x>0-safety_distance && pos.x<length+safety_distance 
		&& pos.y>0-safety_distance && pos.y<hight_cube+safety_distance 
		&& pos.z>0-safety_distance && pos.z<0+safety_distance )
	{
		return 0;
	}

	return 1;
}
bool LeaderTrailler::CollisionFront(Point pos){
	if (pos.x>0+length_way-safety_distance && pos.x<length+safety_distance 
		&& pos.y>0-safety_distance && pos.y<hight_cube+safety_distance 
		&& pos.z>depth_cube-safety_distance && pos.z<depth_cube+safety_distance )
		{
			return 0;
		}
	if (pos.x>0+length_way-safety_distance && pos.x<length+safety_distance 
		&& pos.y>0-safety_distance && pos.y<hight_cube+safety_distance 
		&& pos.z>depth_cube+depth_coal-safety_distance && pos.z<depth_cube+depth_coal+safety_distance )
		{
			return 0;
		}
	return 1;
}

bool LeaderTrailler::CollisionBetweenWall(Point pos){
	if (pos.x>length_way-safety_distance && pos.x<length_way+safety_distance 
		&& pos.y>0-safety_distance && pos.y<hight_cube+safety_distance 
		&& pos.z>depth_cube-safety_distance && pos.z<depth_cube+depth_coal+safety_distance)
		return 0;
	return 1;
}

bool LeaderTrailler::CollisionHolocaust(Point pos)
{
	if (pos.x>Holocaust_bottom_left_back.x-safety_distance && pos.x<length+safety_distance 
		&& pos.y>0-safety_distance && pos.y<hight_cube+safety_distance 
		&& pos.z>Holocaust_bottom_left_back.z-safety_distance && pos.z<Holocaust_bottom_left_back.z+Holocaust_depth+safety_distance)
		return 0;
	return 1;
}


bool LeaderTrailler::CollisionTrailler(Point pos){
	Point new_pos = Point (pos.x-bottom_left_back.x,pos.y-bottom_left_back.y,pos.z-bottom_left_back.z);
	if (CollisionBack(new_pos) && CollisionFront(new_pos)
		&& CollisionTop(new_pos) && CollisionBottom(new_pos)
		&& CollisionLeft(new_pos) && CollisionRight(new_pos)
		&& CollisionBetweenWall(new_pos) && CollisionHolocaust(new_pos))
		
		return 1;
	
	
	return 0;
}
