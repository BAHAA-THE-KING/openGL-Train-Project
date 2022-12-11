#include "premitives.h"
#include "Point.h"

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include "texture.h"
#include "stdc++.h"
using namespace std;

premitives::premitives(void)
{
}


premitives::~premitives(void)
{
}

 void premitives::DrawBall(float rad, int texture)
{
	float lastcenter=rad*sin(3.14/2);
	float lastr=rad*cos(3.14/2);
	for (float vertical=3.14/2; vertical>=-3.14/2; vertical-=0.01)
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
				glTexCoord2d(0, 0);
				glVertex3f(a.x,a.y,a.z);
				glTexCoord2d(1, 0);
				glVertex3f(b.x,b.y,b.z);
				glTexCoord2d(1, 1);
				glVertex3f(d.x,d.y,d.z);
				glTexCoord2d(0, 1);
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
}