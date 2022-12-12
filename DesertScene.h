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
           int imgdune1;
           int imgdune2;
           int imgskybox;
           int imgcactus;
           Sphere dunes[20];
           Point dunesPts[20];
           SkyBox skybox;
           Cactus c[20];
           DesertScene(Point center,float width,float length,float height,int imgdune1,int imgdune2,int imgskybox,int imgcactus){
                      this->center=center;
                      this->width=width;
                      this->length=length;
                      this->height=height;
                      this->imgdune1=imgdune1;
                      this->imgdune2=imgdune2;
                      this->imgskybox=imgskybox;
                      this->imgcactus=imgcactus;
                      
                      for (int i=0;i<20;i++){
                         float r=dis(gen)%10+1;
                         int img=imgdune2;
                         if (5000/dis(gen)<0.5)img=imgdune1;
                         dunes[i]=Sphere(r,10,10,img);
                         }
                      for (int i=0;i<20;i++){
                         float x=pow(-1,dis(gen)%2)*(dis(gen)%((int)width/3)+(width/6));
                         float z=dis(gen)%((int)length)-(length/2);
                         dunesPts[i]=Point(x,0,z);
                         }
                      skybox=SkyBox(center,width,length,height,imgskybox);
                      for (int i=0;i<20;i++){
                         float x=pow(-1,dis(gen)%2)*(dis(gen)%((int)width/3)+(width/6));
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
               
               for (int i=0;i<20;i++)
                  c[i].draw();
               };
     };