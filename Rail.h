#pragma once
class Rail{
     public:
           Point begin;
           int metalimg;
           int woodimg;
           float width;
           float sideWidth;
           float height;
           float length;
           float centerLength;
           Rail(){};
           Rail(Point begin,int metalimg,int woodimg,float width,float sideWidth,float height,float length,float centerLength){
               this->begin=begin;
               this->metalimg=metalimg;
               this->woodimg=woodimg;
               this->width=width;
               this->sideWidth=sideWidth;
               this->height=height;
               this->length=length;
               this->centerLength=centerLength;
               init();
               };
           void draw(){
               glPushMatrix();
               glTranslatef(begin.x-width/2,begin.y,begin.z);
               for (int i=0;i<4;i++){
                  drawImageQuad(metalimg,
                                side[(i+1)%4],
                                side[i],
                                Point(side[i].x,side[i].y,side[i].z+length),
                                Point(side[(i+1)%4].x,side[(i+1)%4].y,side[(i+1)%4].z+length),
                                Point(0,0),
                                Point(1,0),
                                Point(1,1),
                                Point(0,1)
                                );
                  }
               glPopMatrix();
               
               glPushMatrix();
               glTranslatef(begin.x+width/2,begin.y,begin.z);
               for (int i=0;i<4;i++){
                  drawImageQuad(metalimg,
                                side[(i+1)%4],
                                side[i],
                                Point(side[i].x,side[i].y,side[i].z+length),
                                Point(side[(i+1)%4].x,side[(i+1)%4].y,side[(i+1)%4].z+length),
                                Point(0,0),
                                Point(1,0),
                                Point(1,1),
                                Point(0,1)
                                );
                  }
               glPopMatrix();
               
               glPushMatrix();
               glTranslatef(begin.x,begin.y,begin.z+length/2-centerLength/2);
               for (int i=0;i<4;i++){
                  drawImageQuad(woodimg,
                                center[(i+1)%4],
                                center[i],
                                Point(center[i].x,center[i].y,center[i].z+centerLength),
                                Point(center[(i+1)%4].x,center[(i+1)%4].y,center[(i+1)%4].z+centerLength),
                                Point(0,0),
                                Point(1,0),
                                Point(1,1),
                                Point(0,1)
                                );
                  }
               glPopMatrix();

               };
     private:
            Point side[4];
            Point center[4];
            /*
             *            Y           
             *            |           
             *            |           
             *            |           
             *   -X-------Z-------X   
             *            |           
             *            |           
             *            |           
             *           -Y           
             *                        
             *                        
             *                        
             *            Y           
             *            |           
             *            |           
             *            |           
             *   -X-------Z-------X   
             *            |           
             *            |           
             *            |           
             *           -Y           
             * 
             * 
             */
            void init(){
                //0  0 +1  +1 0
                //1  1 -1  +1 0
                //2  1 -1  -1 1
                //3  2 +1  -1 1
                for (int i=0;i<4;i++){
                   side[i]=Point(pow(-1,(i+1)/2)*sideWidth,pow(-1,i/2)*height/2+height/2,0);
                   center[i]=Point(pow(-1,(i+1)/2)*width/2,pow(-1,i/2)*height/2+height/2,0);
                   }
                };
     };