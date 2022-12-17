#include "Point.h"
#include "ImageDrawer.h"
#include "SkyBox.h"
#include "Plane.h"
#include "Sphere.h"
#include "Cactus.h"
#include "Rail.h"
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
           int imgmetal;
           int imgwood;
           Sphere dunes[20];
           Point dunesPts[20];
           SkyBox skybox;
           Cactus c[20];
           Rail rail[800];
           DesertScene(Point center,float width,float length,float height,int imgdune1,int imgdune2,int imgskybox,int imgcactus,int imgmetal,int imgwood){
                      this->center=center;
                      this->width=width;
                      this->length=length;
                      this->height=height;
                      this->imgdune1=imgdune1;
                      this->imgdune2=imgdune2;
                      this->imgskybox=imgskybox;
                      this->imgcactus=imgcactus;
                      this->imgmetal=imgmetal;
                      this->imgwood=imgwood;
                      
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
                      
                      skybox=SkyBox(center,width,length,height,imgskybox,true);
                      
                      for (int i=0;i<20;i++){
                         float x=pow(-1,dis(gen)%2)*(dis(gen)%((int)width/3)+(width/6));
                         float z=dis(gen)%((int)length-20)-(length-20)/2;
                         c[i]=Cactus(Point(x,0,z),imgcactus);
                         }
                      
                      for (int i=0;i<800;i++){this->rail[i]=Rail(Point(0,0,i*1.25-length/2),imgmetal,imgwood,4,0.25,0.15,1.25,0.5);}
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
               
               for (int i=0;i<800;i++){this->rail[i].draw();}
               };
     };