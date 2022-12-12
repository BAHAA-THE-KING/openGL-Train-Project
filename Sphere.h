#pragma once
#include <vector>
#include <random>
#define PI 3.14159265358979323846
std::random_device rrdd;
std::mt19937 ggeenn(rrdd());
std::uniform_int_distribution<> ddiiss(0,3);

class Sphere{
     public:
           float r;
           int stacks;
           int sectors;
           int img;
           int imgScale;
           Sphere(){};
           Sphere(float r,int stacks,int sectors,int img,int imgScale=1,float sx=ddiiss(ggeenn)+0.5,float sy=ddiiss(ggeenn)%2+0.5,float sz=ddiiss(ggeenn)+0.5){
                 this->r=r;
                 this->stacks=stacks;
                 this->sectors=sectors;
                 this->img=img;
                 this->imgScale=imgScale;
                 this->sx=sx;
                 this->sy=sy;
                 this->sz=sz;
                 init();
                 }
           void draw(){
               for (int i=0;i<(stacks)-1;i++){
                  for (int j=0;j<(sectors)-1;j++){
                     Point p1=pts[i*(stacks)+(j)];
                     Point p2=pts[i*(stacks)+(j)+1];
                     Point p3=pts[(i+1)*(stacks)+(j)+1];
                     Point p4=pts[(i+1)*(stacks)+(j)];
                     glBegin(GL_QUADS);
                        glVertex3f(p1.x,p1.y,p1.z);
                        glVertex3f(p2.x,p2.y,p2.z);
                        glVertex3f(p3.x,p3.y,p3.z);
                        glVertex3f(p4.x,p4.y,p4.z);
                     glEnd();
                     }
                  }
               };
           void drawImage(){
               glPushMatrix();
               glScaled(sx,sy,sz);
               for (float i=0;i<(stacks)-1;i++){
                  for (float j=0;j<(sectors)-1;j++){
                     Point p1=pts[i*(stacks)+(j)];
                     Point p2=pts[i*(stacks)+(j)+1];
                     Point p3=pts[(i+1)*(stacks)+(j)+1];
                     Point p4=pts[(i+1)*(stacks)+(j)];
                     
                     Point ip1(j/(sectors-1.0),i/(stacks-1.0));
                     Point ip2((j+1.0)/(sectors-1.0),i/(stacks-1.0));
                     Point ip3((j+1.0)/(sectors-1.0),(i+1)/(stacks-1.0));
                     Point ip4(j/(sectors-1.0),(i+1.0)/(stacks-1.0));;
                     
                     drawImageQuad(img,p1,p2,p3,p4,ip1,ip2,ip3,ip4,imgScale);
                     }
                  }
               glPopMatrix();
               };
           private:
                  std::vector<Point> pts;
                  float sx=1;
                  float sy=1;
                  float sz=1;
                  void init(){
                      for (float i=0;i<=stacks-1;i++){
                         float rr=r*sin(PI*(i/(stacks-1)));
                         for (float j=0;j<=sectors-1;j++){
                            float x=rr*cos(2*PI*(j/(sectors-1)));
                            float y=-r*cos(PI*(i/(stacks-1)));
                            float z=rr*sin(2*PI*(j/(sectors-1)));
                            if (abs(x)<1e-10)x=0;
                            if (abs(y)<1e-10)y=0;
                            if (abs(z)<1e-10)z=0;
                            pts.push_back(Point(x,y,z));
                            }
                         }
                      }
     };