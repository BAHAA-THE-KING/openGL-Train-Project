#pragma once



void drawLightSource(int img, Point l,float r, Cylinder l1)
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, img);
    glTranslatef(l.x, l.y + r, l.z);
    glRotated(90, 1, 0, 0);
    glTranslated(0, 0, 0);
    l1.drawSide();
    //DrawAxis();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}