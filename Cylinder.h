#pragma once
class Cylinder{
     public:
           float r;
           int sectors;
           int height;
           int img;
           Cylinder(){};
           Cylinder(float r,int sectors,int height,int img){
                   this->r=r;
                   this->sectors=sectors;
                   this->height=height;
                   this->img=img;
                   init();
                   };
           void draw(){
               glEnable(GL_TEXTURE_2D);
               glBindTexture(GL_TEXTURE_2D,img);
               
               glBegin(GL_POLYGON);
               for (int i=0;i<sectors;i++)
                  glVertex3f(pts[i].x,0,pts[i].z);
               glEnd();
               
               glBegin(GL_QUADS);
               for (int i=0;i<sectors;i++){
                  Point left=pts[i];
                  Point right=pts[(i+1)%sectors];
                  
                  drawImageQuad(img,
                                Point(left.x,0,left.z),
                                Point(right.x,0,right.z),
                                Point(right.x,height,right.z),
                                Point(left.x,height,left.z),
                                Point(6.0*i/sectors,0),
                                Point(6.0*(i+1)/sectors,0),
                                Point(6.0*(i+1)/sectors,2),
                                Point(6.0*i/sectors,2)
                                );
                  }
               glEnd();
               
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