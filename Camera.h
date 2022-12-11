#pragma once
class Camera{
     public:
           Point cE;
           Point cC;
           Point cU;
           Point cPos;
           float cHAngle;
           float cVAngle;
           float cSpeed;
           float i;
           bool* keys;
           Camera(bool* keys){
                 cE=Point(0,0,0);
                 cC=Point(0,0,1);
                 cU=Point(0,1,0);
                 cPos=Point(0,2,0);
                 cHAngle=0;
                 cVAngle=0;
                 cSpeed=0.5;
                 i=0;
                 this->keys=keys;
                 };
           void kb(){
               if (keys[VK_SHIFT])cSpeed=1;
               else cSpeed=0.5;
               if (keys['W']){cPos.z-=-cos(cHAngle)*cSpeed;cPos.x+=sin(cHAngle)*cSpeed;cPos.y+=0.05*sin(2*i);}
               if (keys['S']){cPos.z+=-cos(cHAngle)*cSpeed;cPos.x-=sin(cHAngle)*cSpeed;cPos.y+=0.05*sin(2*i);}
               if (keys['A']){cPos.x+=cos(cHAngle)*cSpeed;cPos.z+=-sin(cHAngle)*cSpeed;cPos.y+=0.05*sin(2*i);}
               if (keys['D']){cPos.x-=cos(cHAngle)*cSpeed;cPos.z-=-sin(cHAngle)*cSpeed;cPos.y+=0.05*sin(2*i);}
               if (keys['Q']){cPos.y+=cSpeed;}
               if (keys['E']){cPos.y-=cSpeed;}
               if (keys[VK_LEFT])cHAngle+=cSpeed/10;
               if (keys[VK_RIGHT])cHAngle-=cSpeed/10;
               if (keys[VK_UP] && cVAngle<=PI/4)cVAngle+=0.05;
               if (keys[VK_DOWN] && cVAngle>=-PI/4)cVAngle-=0.05;
               cE.x=cPos.x;
               cE.y=cPos.y;
               cE.z=cPos.z;
               cC.x=cPos.x+sin(cHAngle);
               cC.y=cPos.y+sin(cVAngle);
               cC.z=cPos.z+cos(cHAngle);
               cU.x=/*cPos.x*/0;
               cU.y=/*cPos.ycos(cVAngle)*/1;
               cU.z=/*cPos.zsin(cVAngle)*/0;
               i+=0.1;
               }
           void move(){
               kb();
               gluLookAt(cE.x,cE.y,cE.z,
                        cC.x,cC.y,cC.z,
                         cU.x,cU.y,cU.z);
               };
     };