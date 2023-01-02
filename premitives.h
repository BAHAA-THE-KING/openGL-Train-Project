#pragma once
class premitives
{
public:
	premitives(void){};
	~premitives(void){};
	
 static void DrawBall( float rad, int texture=-1, Point center=Point(0,0,0))
{
	glTranslated(center.x,center.y,center.z);
	float lastcenter=rad*sin(3.14/2);
	float lastr=rad*cos(3.14/2);
	for (float vertical=3.14/2.0; vertical>=-3.14/2.0; vertical-=0.1)
	{

		float centeri=rad*sin(vertical);
		float ri=rad*cos(vertical);
		int col = 0;
		for (float horizin=0; horizin<=2*3.14+0.1; horizin+=0.1)
		{
			Point a= Point (  ri*cos(horizin) , centeri , ri*sin(horizin));
			Point b= Point (  ri*cos(horizin+0.1) , centeri , ri*sin(horizin+0.1));
			Point c= Point (  lastr*cos(horizin) , lastcenter , lastr*sin(horizin));
			Point d= Point (  lastr*cos(horizin+0.1) , lastcenter , lastr*sin(horizin+0.1));
			if (texture!=-1)
			{
				glBindTexture(GL_TEXTURE_2D, texture);
				glBegin(GL_QUADS);
				glTexCoord2d(1-(horizin)/(2*3.14), 0.5+sin(vertical-0.1)/2.0);
				glVertex3f(a.x,a.y,a.z);
				glTexCoord2d(1-(horizin+0.1)/(2*3.14), 0.5+sin(vertical-0.1)/2.0);
				glVertex3f(b.x,b.y,b.z);
				glTexCoord2d(1-(horizin+0.1)/(2*3.14), 0.5+sin(vertical)/2.0);
				glVertex3f(d.x,d.y,d.z);
				glTexCoord2d(1-(horizin)/(2*3.14), 0.5+sin(vertical)/2.0);
				glVertex3f(c.x,c.y,c.z);
				glEnd();
			}
			else
			{
				glBegin(GL_QUADS);
				glVertex3f(a.x,a.y,a.z);
				glVertex3f(b.x,b.y,b.z);
				glVertex3f(d.x,d.y,d.z);
				glVertex3f(c.x,c.y,c.z);
				glEnd();
			}
		}
		lastr=ri;
		lastcenter=centeri;
	}
	glTranslated(-center.x,-center.y,-center.z);

};


 static  void DrawCylinderBody(Point Base_center1, float Base_rad1, float Base_rad2, float height, int texture)
{
		glTranslated(Base_center1.x,Base_center1.y, Base_center1.z);
		Base_center1=Point(0,0,0);
		Point Base_center2=Point (0,0,height);
		if (texture!=-1)
				glColor3f(1,1,1);
		float angle=0, x1=Base_rad1, y1=0, x2=Base_rad2, y2=0;
		for (angle=0; angle <=2*3.14+0.1; angle+=0.1)
		{
			Point a= Point (x1,y1,Base_center1.z);
			Point b= Point (x2,y2,Base_center2.z);
			x1=Base_rad1*cos(angle);
			y1=Base_rad1*sin(angle);
			x2=Base_rad2*cos(angle);
			y2=Base_rad2*sin(angle);
			Point c= Point (x2,y2,Base_center2.z);
			Point d= Point (x1,y1,Base_center1.z);
			glBindTexture(GL_TEXTURE_2D,texture);
			glBegin(GL_QUADS);

				glTexCoord2f(angle/(2*3.14),a.z/height);
				glVertex3f(a.x,a.y,a.z);
			
				glTexCoord2f(angle/(2*3.14),b.z/height);
				glVertex3f(b.x,b.y,b.z);
			
				glTexCoord2f((angle+0.1)/(2*3.14),c.z/height);
				glVertex3f(c.x,c.y,c.z);
			
				glTexCoord2f((angle+0.1)/(2*3.14),d.z/height);
				glVertex3f(d.x,d.y,d.z);

			glEnd();
	}
	glTranslated(-Base_center1.x,-Base_center1.y, -Base_center1.z);

};

  
static void DrawRing(Point center, float radin, float radout, int texture)
{
	glPushMatrix( );
		glTranslated(center.x,center.y, center.z);
		if (texture!=-1)
				glColor3f(1,1,1);
		for (float angle = 0; angle<=2*3.14+1; angle+=0.1)
		{
			glBindTexture(GL_TEXTURE_2D,texture);
			glBegin(GL_QUADS);
				glTexCoord2f(radin*(0.5+cos(angle)),radin*(0.5+sin(angle)));
				glVertex3f(radin*cos(angle),radin*sin(angle),0);
				glTexCoord2f(radin*(0.5+cos(angle+0.1)),radin*(0.5+sin(angle+0.1)));
				glVertex3f(radin*cos(angle+0.1),radin*sin(angle+0.1),0);
				glTexCoord2f(radout*(0.5+cos(angle+0.1)),radout*(0.5+sin(angle+0.1)));
				glVertex3f(radout*cos(angle+0.1),radout*sin(angle+0.1),0);
				glTexCoord2f(radout*(0.5+cos(angle)),radout*(0.5+sin(angle)));
				glVertex3f(radout*cos(angle),radout*sin(angle),0);
			glEnd();
		}
	glPopMatrix( );
};


static void DrawCupe(Point bottom_left_back, float length, float hight, float depth, int texture)
{
	glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);
		glColor3f(1,1,1);
		glBindTexture(GL_TEXTURE_2D,texture);

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
		
	glTranslated(-bottom_left_back.x,-bottom_left_back.y,-bottom_left_back.z);
};



static void DrawCupe(Point bottom_left_back, float length, float hight, float depth, int texture, 
						  bool is_exist_front, bool is_exist_back, bool is_exist_right,
						  bool is_exist_left, bool is_exist_bottom, bool is_exist_top)
{
	glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);
		glBindTexture(GL_TEXTURE_2D,texture);

		if (is_exist_back){
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
		}

		if (is_exist_front){
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
		}

		if (is_exist_left){
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
		}

		if (is_exist_right){
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
		}

		if (is_exist_top){
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
		}

		if (is_exist_bottom){

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
		}

	glTranslated(-bottom_left_back.x,-bottom_left_back.y,-bottom_left_back.z);
};

static void DrawQuad(Point bottom_left,Point bottom_right,Point up_right,Point up_left, int texture)
{
	glBindTexture(GL_TEXTURE_2D,texture);
	glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(bottom_left.x,bottom_left.y,bottom_left.z);
		glTexCoord2f(1,0);
		glVertex3f(bottom_right.x,bottom_right.y,bottom_right.z);
		glTexCoord2f(1,1);
		glVertex3f(up_right.x,up_right.y,up_right.z);
		glTexCoord2f(0,1);
		glVertex3f(up_left.x,up_left.y,up_left.z);

	glEnd();
};



};

