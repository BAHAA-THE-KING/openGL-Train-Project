#pragma once

class Plane{
     public:
           Point LD;
           Point RD;
           Point RU;
           Point LU;
           int img;
           Plane(){};
           Plane(Point LD,Point RD,Point RU,Point LU,int img=-1){
                this->LD=LD;
                this->RD=RD;
                this->RU=RU;
                this->LU=LU;
                this->img=img;
                };
           void draw(){
               if (img==-1)return drawGray();
               return drawTex();
               };
           private:
                  void drawTex(){
                      drawImageQuad(img,LD,RD,RU,LU,Point(0,0),Point(1,0),Point(1,1),Point(0,1));
                      };
                  void drawGray(){
                      glBegin(GL_QUADS);
                      glVertex3f(LD.x,LD.y,LD.z);
                      glVertex3f(RD.x,RD.y,RD.z);
                      glVertex3f(RU.x,RU.y,RU.z);
                      glVertex3f(LU.x,LU.y,LU.z);
                      glEnd();
                      };
    };