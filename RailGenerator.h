#pragma once
#include "Rail.h"
#include <vector>
class RailGenerator{
     public:
           float length;
           int imgmetal;
           int imgwood;
           Point start;
           RailGenerator(){};
           RailGenerator(float length,int imgmetal,int imgwood,Point start){
                        this->length=length;
                        this->imgmetal=imgmetal;
                        this->imgwood=imgwood;
                        this->start=start;
                        init();
                        };
           void draw(){
               for (int i=0;i<rail.size();i++){
                  rail[i].draw();
                  }
               };
     private:
            std::vector<Rail> rail;
            float railLength=1.25;
            void init(){
                for (int i=0;i<length/railLength;i++){
                   this->rail.push_back(Rail(Point(start.x,start.y,start.z+i*railLength),imgmetal,imgwood,4,0.25,0.15,railLength,0.5));
                   }
                };
     };