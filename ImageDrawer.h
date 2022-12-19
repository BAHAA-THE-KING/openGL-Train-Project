#pragma once

void drawImageQuad(int image,Point LD,Point RD,Point RU,Point LU,Point stLD,Point stRD,Point stRU,Point stLU,float times=1){
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D,image);
   glBegin(GL_QUADS);

   glTexCoord2f(times*stLD.x,times*stLD.y);
   glVertex3f(LD.x,LD.y,LD.z);
   
   glTexCoord2f(times*stRD.x,times*stRD.y);
   glVertex3f(RD.x,RD.y,RD.z);
   
   glTexCoord2f(times*stRU.x,times*stRU.y);
   glVertex3f(RU.x,RU.y,RU.z);
   
   glTexCoord2f(times*stLU.x,times*stLU.y);
   glVertex3f(LU.x,LU.y,LU.z);
   
   glEnd();
   glDisable(GL_TEXTURE_2D);
}