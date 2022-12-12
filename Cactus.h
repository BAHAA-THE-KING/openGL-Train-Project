#pragma once
#include "Cylinder.h"
std::random_device ard;
std::mt19937 agen(ard());
std::uniform_int_distribution<> adis(0,360);
class Cactus{
     public:
           Point down;
           Cylinder center;
           Sphere cape;
           Cylinder left;
           Sphere leftCape;
           Cylinder right;
           Sphere rightCape;
           int ang;
           int img;
           Cactus(){};
           Cactus(Point down,int img){
                 this->down=down;
                 this->img=img;
                 this->center=Cylinder(0.5,20,8,img);
                 this->cape=Sphere(0.5,15,15,img,6,1,1,1);
                 this->left=Cylinder(0.5,15,2,img);
                 this->leftCape=Sphere(0.5,15,15,img,6,1,0.75,1);
                 this->right=Cylinder(0.5,15,2,img);
                 this->rightCape=Sphere(0.5,15,15,img,6,1,0.75,1);
                 this->ang=adis(agen);
                 };
           void draw(){
               glPushMatrix();
               glTranslated(down.x,down.y,down.z);
               glRotated(ang,0,1,0);
               
               glPushMatrix();
                 center.draw();
                 glTranslated(0,8,0);
                 cape.drawImage();
               glPopMatrix();
               
               glPushMatrix();
                glTranslated(0,4.5,0);
                glRotated(90,0,0,1);
                left.draw();
                glTranslated(0,2,0);
                leftCape.drawImage();
                glRotated(-90,0,0,1);
                glScaled(0.75,1,0.75);
                left.draw();
                glTranslated(0,2,0);
                leftCape.drawImage();
               glPopMatrix();
               
               glPushMatrix();
               glTranslated(0,5.5,0);
               glRotated(-90,0,0,1);
               right.draw();
               glTranslated(0,2,0);
               rightCape.drawImage();
               glRotated(90,0,0,1);
               glScaled(0.75,1,0.75);
               right.draw();
               glTranslated(0,2,0);
               rightCape.drawImage();
               glPopMatrix();
               
               glPopMatrix();
               };
     };