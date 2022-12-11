#pragma once

class Cactus{
     public:
           Point down;
           int img;
           Cactus(){};
           Cactus(Point down,int img){
                 this->down=down;
                 this->img=img;
                 };
           void draw(){
               glTranslated(down.x,2+down.y,down.z);
               Sphere(2.5,7,7,img).drawImage(3);
               glTranslated(-down.x,-2-down.y,-down.z);
               };
     };