#pragma once
class Cylinder{
     public:
           float r;
           int sectors;
           int height;
           int img;
           int repeat;
           Cylinder(){};
           Cylinder(float r,int sectors,int height,int img,int repeat=6){
                   this->r=r;
                   this->sectors=sectors;
                   this->height=height;
                   this->img=img;
                   this->repeat=repeat;
                   init();
                   };
           void draw(){
               glEnable(GL_TEXTURE_2D);
               glBindTexture(GL_TEXTURE_2D,img);
               
               glBegin(GL_POLYGON);
               for (int i=0;i<sectors;i++)
                  glVertex3f(pts[i].x,0,pts[i].z);
               glEnd();
               
               for (int i=0;i<sectors;i++){
                  Point left=pts[i];
                  Point right=pts[(i+1)%sectors];
                  
                  drawImageQuad(img,
                                Point(left.x,0,left.z),
                                Point(right.x,0,right.z),
                                Point(right.x,height,right.z),
                                Point(left.x,height,left.z),
                                Point(1.0*repeat*i/sectors,0),
                                Point(1.0*repeat*(i+1)/sectors,0),
                                Point(1.0*repeat*(i+1)/sectors,2),
                                Point(1.0*repeat*i/sectors,2)
                                );
                  }
               
               glBegin(GL_POLYGON);
               for (int i=0;i<sectors;i++)
                  glVertex3f(pts[i].x,height,pts[i].z);
               glEnd();
               
               glDisable(GL_TEXTURE_2D);
               };
     private:
            std::vector<Point> pts;
            void init(){
                for (int i=0;i<sectors;i++){
                   float angle=i*2*PI/(sectors-1);
                   float x=r*cos(angle);
                   float z=r*sin(angle);
                   pts.push_back(Point(x,0,z));
                   }
                };
     };