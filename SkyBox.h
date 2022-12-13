#pragma once
class SkyBox{
     public:
           Point center;
           float width;
           float length;
           float height;
           int img;
           SkyBox(){};
           SkyBox(Point center,float width,float length,float height,int img){
                 this->center=center;
                 this->width=width;
                 this->length=length;
                 this->height=height;
                 this->img=img;
                 this->LBD=Point(center.x-width/2,center.y,center.z+length/2);
                 this->LFD=Point(center.x-width/2,center.y,center.z-length/2);
                 this->LFU=Point(center.x-width/2,center.y+height,center.z-length/2);
                 this->LBU=Point(center.x-width/2,center.y+height,center.z+length/2);
                 this->RBD=Point(center.x+width/2,center.y,center.z+length/2);
                 this->RFD=Point(center.x+width/2,center.y,center.z-length/2);
                 this->RFU=Point(center.x+width/2,center.y+height,center.z-length/2);
                 this->RBU=Point(center.x+width/2,center.y+height,center.z+length/2);

                 };
           void draw(){
               LBD.y-=height/2;
               LFD.y-=height/2;
               LFU.y-=height/2;
               LBU.y-=height/2;
               RBD.y-=height/2;
               RFD.y-=height/2;
               RFU.y-=height/2;
               RBU.y-=height/2;
               
               //Left
               drawImageQuad(img,
                             LBD,LFD,LFU,LBU,
                             Point(0,1/3.0),Point(0.25,1/3.0),Point(0.25,2/3.0),Point(0,2/3.0));
               //Front
               drawImageQuad(img,
                             LFD,RFD,RFU,LFU,
                             Point(0.25,1/3.0),Point(0.5,1/3.0),Point(0.5,2/3.0),Point(0.25,2/3.0));
               //Right
               drawImageQuad(img,
                             RFD,RBD,RBU,RFU,
                             Point(0.5,1/3.0),Point(0.75,1/3.0),Point(0.75,2/3.0),Point(0.5,2/3.0));
               //Back
               drawImageQuad(img,
                             RBD,LBD,LBU,RBU,
                             Point(0.75,1/3.0),Point(1,1/3.0),Point(1,2/3.0),Point(0.75,2/3.0));
               //Top
               drawImageQuad(img,
                             LFU,RFU,RBU,LBU,
                             Point(0.25,2/3.0),Point(0.5,2/3.0),Point(0.5,1),Point(0.25,1));
               
               LBD.y+=height/2;
               LFD.y+=height/2;
               LFU.y+=height/2;
               LBU.y+=height/2;
               RBD.y+=height/2;
               RFD.y+=height/2;
               RFU.y+=height/2;
               RBU.y+=height/2;
               
               //Down
               drawImageQuad(img,
                             LBD,RBD,RFD,LFD,
                             Point(0.25,0),Point(0.5,0),Point(0.5,1/3.0),Point(0.25,1/3.0));
               };
     private:
            Point LBD;
            Point LFD;
            Point LFU;
            Point LBU;
            Point RBD;
            Point RFD;
            Point RFU;
            Point RBU;
     };