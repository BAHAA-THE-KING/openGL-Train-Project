#pragma once
class House 
{

public:
	Point bottom_left_back;
	float length, depth, hight_haram, hight_cube;
	int texture_door, texture_wall, texture_window, texture_roof;
	House(void){};
	~House(void){};

	House(Point bottom_left_back,float length, float depth,
	float hight_haram, float hight_cube,
		int texture_door,int texture_wall,
		int texture_window,int texture_roof)
	{
		this->bottom_left_back=bottom_left_back;
		this->length=length;
		this->depth=depth;
		this->hight_haram=hight_haram;
		this->hight_cube=hight_cube;
		this->texture_door=texture_door;
		this->texture_wall=texture_wall;
		this->texture_window=texture_window;
		this->texture_roof=texture_roof;
	};


	void DrawHouse()
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
		// if the door in the middle and the door length is the house length/4, and the hight is house 0.7*hight
		glTranslated(length/2-length/8,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube*0.7,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube*0.7,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();


		//Draw windows
		glBindTexture(GL_TEXTURE_2D, texture_window);
		//front
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(d.x,d.y,d.z);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/20,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glTranslated(13*length/20,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();

		//back
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(a.x,a.y,a.z);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(length/4-length/8,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glTranslated(length/2,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(length/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(length/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();


		//left
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(a.x,a.y,a.z);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glTranslated(depth/2,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();


		//right
		glPushMatrix();
		glDisable(GL_DEPTH_BUFFER_BIT);
		glTranslated(b.x,b.y,b.z);
		glRotated(-90,0,1,0);
		// if the window in the middle of the right part of door and the window length is the house length/4, and the hight is house hight/2.5
		glTranslated(depth/4-depth/8,hight_cube/4,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glTranslated(depth/2,0,0);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(0,0,0);
		glTexCoord2d(1, 0);
		glVertex3f(depth/4,0,0);
		glTexCoord2d(1, 1);
		glVertex3f(depth/4,hight_cube/2.5,0);
		glTexCoord2d(0, 1);
		glVertex3f(0,hight_cube/2.5,0);
		glEnd();
		glEnable(GL_DEPTH_BUFFER_BIT);
		glPopMatrix();


		// Draw roof
		glBindTexture(GL_TEXTURE_2D, texture_roof);
		glPushMatrix();
		Point top_left = Point (e.x,e.y+hight_haram,e.z+depth/2);
		Point top_right= Point (f.x,f.y+hight_haram,f.z+depth/2);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(e.x,e.y,e.z);
		glTexCoord2d(0, 1);
		glVertex3f(top_left.x,top_left.y,top_left.z);
		glTexCoord2d(1, 1);
		glVertex3f(top_right.x,top_right.y,top_right.z);
		glTexCoord2d(1, 0);
		glVertex3f(f.x,f.y,f.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3f(h.x,h.y,h.z);
		glTexCoord2d(0, 1);
		glVertex3f(top_left.x,top_left.y,top_left.z);
		glTexCoord2d(1, 1);
		glVertex3f(top_right.x,top_right.y,top_right.z);
		glTexCoord2d(1, 0);
		glVertex3f(g.x,g.y,g.z);
		glEnd();

		glBegin(GL_TRIANGLES);
		glTexCoord2d(0, 0);
		glVertex3f(e.x,e.y,e.z);
		glTexCoord2d(1, 0);
		glVertex3f(h.x,h.y,h.z);
		glTexCoord2d(0.5, 1);
		glVertex3f(top_left.x,top_left.y,top_left.z);
		glEnd();
		glBegin(GL_TRIANGLES);
		glTexCoord2d(0, 0);
		glVertex3f(f.x,f.y,f.z);
		glTexCoord2d(1, 0);
		glVertex3f(g.x,g.y,g.z);
		glTexCoord2d(0.5, 1);
		glVertex3f(top_right.x,top_right.y,top_right.z);
		glEnd();

		glPopMatrix();

	};
};

