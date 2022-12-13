#pragma once
#include "Point.h"

#include <vector>
#include "ImageDrawer.h"
#include "Plane.h"
#include "SkyBox.h"
#include "Cylinder.h"
#include "QuadImage.h"
#include "lightSource.h"


class tunnel {



public:
    Point center;
    float radius;
    float tunnelLength;
    float tunnelHeight;
    float cubeOperator;
    int imgTunnel;
    int imgGround;
    float h ;
    int imgWall;
    int imgLight;
    float y ;
   
    SkyBox skybox;

    tunnel(Point center, float radius, float tunnelLength, float tunnelHeight,float cubeOperator , int imgTunnel, int imgGround, int imgWall, int imgLight) {
        this->center = center;
        this->radius = radius;
        this->tunnelLength = tunnelLength;
        this->tunnelHeight = tunnelHeight;
        this->cubeOperator = cubeOperator;
        this->imgTunnel = imgTunnel;
        this->imgGround = imgGround;
        this->imgWall = imgWall;
        this->imgLight = imgLight;
        this->h = (tunnelHeight + 2) - radius;
        this->y = center.y ;
    };
    void DrawAxis()
    {
        glColor3f(1.0, 0.0, 0.0); // red x

        glBegin(GL_LINES);
        // x aix

        glVertex3f(-4.0, 0.0f, 0.0f);
        glVertex3f(4.0, 0.0f, 0.0f);

        // arrow
        glVertex3f(4.0, 0.0f, 0.0f);
        glVertex3f(3.0, 1.0f, 0.0f);

        glVertex3f(4.0, 0.0f, 0.0f);
        glVertex3f(3.0, -1.0f, 0.0f);
        glEnd();
        glFlush();



        // y 
        glColor3f(0.0, 1.0, 0.0); // green y
        glBegin(GL_LINES);
        glVertex3f(0.0, -4.0f, 0.0f);
        glVertex3f(0.0, 4.0f, 0.0f);

        // arrow
        glVertex3f(0.0, 4.0f, 0.0f);
        glVertex3f(1.0, 3.0f, 0.0f);

        glVertex3f(0.0, 4.0f, 0.0f);
        glVertex3f(-1.0, 3.0f, 0.0f);
        glEnd();
        glFlush();

        // z 
        glColor3f(0.0, 0.0, 1.0); // blue z
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0f, -4.0f);
        glVertex3f(0.0, 0.0f, 4.0f);

        // arrow
        glVertex3f(0.0, 0.0f, 4.0f);
        glVertex3f(0.0, 1.0f, 3.0f);

        glVertex3f(0.0, 0.0f, 4.0f);
        glVertex3f(0.0, -1.0f, 3.0f);
        glEnd();
        glFlush();
    };
    void draw() {
      
      
      

        glPushMatrix();
        glTranslated(0, h, 0);
      glTranslatef(center.x,y, center.z);
     Cylinder c(radius, radius, tunnelLength, 39, 20, true);
  
       glEnable(GL_TEXTURE_2D);
       glBindTexture(GL_TEXTURE_2D, imgTunnel);
        c.drawSide();
        glDisable(GL_TEXTURE_2D);
        float x = radius * 1.4 / 10;
        float l = tunnelLength / 4.0f;
        float r = radius / 10.0f;
        //radius - r
        Point LD = Point{ center.x + radius - r, center.y  - r ,center.z - tunnelLength / 2.0f };
        Point RD = Point{ center.x - radius + r, center.y  - r ,center.z - tunnelLength / 2.0f };
        Point LU = Point{ center.x + radius - r, center.y + radius - r+ cubeOperator,center.z - tunnelLength / 2.0f };
        Point RU = Point{ center.x - radius + r, center.y + radius - r+ cubeOperator ,center.z - tunnelLength / 2.0f };
        Point sLD = Point{LD.x,LD.y,center.z + tunnelLength/2.0f };
        Point sRD = Point{RD.x,RD.y,center.z + tunnelLength / 2.0f };
        Point sLU = Point{LU.x,LU.y,center.z + tunnelLength / 2.0f };
        Point sRU = Point{RU.x,RU.y,center.z + tunnelLength / 2.0f };
        Point L1 = Point{ center.x , center.y + radius,center.z - tunnelLength / 2.0f +1.5f};
        Point L2 = Point{ center.x , center.y + radius,L1.z + l };
        Point L3 = Point{ center.x , center.y + radius,L1.z + 2 * l };
        Point L4 = Point{ center.x , center.y + radius,L1.z + 3 * l };
        Point L5 = Point{ center.x , center.y + radius,L1.z + 4 * l -3.5f };

       
        Cylinder l1(1, 2, 3, 39, 20, true);
        //light1
        drawLightSource(imgLight, L1, r + 1.2 ,l1);
        //light2
        drawLightSource(imgLight, L2, r + 1.2, l1);
        //light3
        drawLightSource(imgLight, L3, r + 1.2, l1);
        //light4
        drawLightSource(imgLight, L4, r + 1.2, l1);
        //light5
        drawLightSource(imgLight, L5, r+1.3, l1);

        glPushMatrix();
        glTranslated(-2*radius+r+x,-x, 0);
        quadImageDraw(imgWall, LD, RD, RU, LU, sLD, sRD, sRU, sLU);
        glPopMatrix();

        glPushMatrix();
        glTranslated(2 * radius - r - x, -x, 0);
        quadImageDraw(imgWall, LD, RD, RU, LU, sLD, sRD, sRU, sLU);
        glPopMatrix();

        //glPushMatrix();
        //glTranslated(-2 * radius + r + x, -x+radius, 0);
        //quadImageDraw(imgWall, LD, RD, RU, LU, sLD, sRD, sRU, sLU);
        //glPopMatrix();


        //glPushMatrix();
        //glTranslated(2 * radius - r - x, -x+radius, 0);
        //quadImageDraw(imgWall, LD, RD, RU, LU, sLD, sRD, sRU, sLU);
        //glPopMatrix();

       /* glPushMatrix();
        glTranslated(0,  radius+x+4.5, 0);
        quadImageDraw(imgWall, LD, RD, Point(RU.x,RU.y-5.0f,RU.z), Point(LU.x, LU.y - 5.0f, LU.z), sLD, sRD, Point(sRU.x, sRU.y - 5.0f, sRU.z), Point(sLU.x, sLU.y - 5.0f, sLU.z));
        glPopMatrix();*/

        glPopMatrix();

    };

 
    
};