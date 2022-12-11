#include "Point.h"
#include "ImageDrawer.h"
#include "SkyBox.h"
#include "Plane.h"
#include "Sphere.h"
#include "Cactus.h"
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0,10000);

class DesertScene{
     public:
           Point center;
           float width;
           float length;
           float height;
           float ang=0;
           int imgdune;
           int imgskybox;
           int imgcactus;
           Sphere dunes[20];
           Point dunesPts[20];
           SkyBox skybox;
           Cactus c[10];
           DesertScene(Point center,float width,float length,float height,int imgdune,int imgskybox,int imgcactus){
                      this->center=center;
                      this->width=width;
                      this->length=length;
                      this->height=height;
                      this->imgdune=imgdune;
                      this->imgskybox=imgskybox;
                      this->imgcactus=imgcactus;
                      
                      for (int i=0;i<20;i++){
                         float r=dis(gen)%10+1;
                         dunes[i]=Sphere(r,10,10,imgdune);
                         }
                      for (int i=0;i<10;i++){
                         float x=dis(gen)%((int)width)-(width/2);
                         float z=dis(gen)%((int)length)-(length/2);
                         dunesPts[i]=Point(x,0,z);
                         }
                      skybox=SkyBox(center,width,length,height,imgskybox);
                      for (int i=0;i<10;i++){
                         float x=dis(gen)%((int)width-20)-(width-20)/2;
                         float z=dis(gen)%((int)length-20)-(length-20)/2;
                         c[i]=Cactus(Point(x,0,z),imgcactus);
                         }
                      };
           void draw(){
               skybox.draw();
               
               for (int i=0;i<20;i++){
                  glPushMatrix();
                    glTranslated(dunesPts[i].x,0,dunesPts[i].z);
                    if (dunesPts[i].x<0)glRotated(180,0,1,0);
                      dunes[i].drawImage();
                  glPopMatrix();
                  }
               
               for (int i=0;i<10;i++)
                  c[i].draw();
               };
     };