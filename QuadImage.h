#pragma once
void quadImageDraw(int img, Point LD, Point RD, Point RU, Point LU, Point sLD, Point sRD, Point sRU, Point sLU)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, img);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(LD.x, LD.y, LD.z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(RD.x, RD.y, RD.z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(RU.x, RU.y, RU.z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(LU.x, LU.y, LU.z);
	// Back Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(sLD.x, sLD.y, sLD.z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(sRD.x, sRD.y, sRD.z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(sRU.x, sRU.y, sRU.z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(sLU.x, sLU.y, sLU.z);
	// Top Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(LU.x, LU.y, LU.z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(RU.x, RU.y, RU.z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(sRU.x, sRU.y, sRU.z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(sLU.x, sLU.y, sLU.z);
	// Bottom Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(LD.x, LD.y, LD.z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(RD.x, RD.y, RD.z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(sRD.x, sRD.y, sRD.z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(sLD.x, sLD.y, sLD.z);
	// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(RD.x, RD.y, RD.z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(RU.x, RU.y, RU.z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(sRU.x, sRU.y, sRU.z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(sRD.x, sRD.y, sRD.z);
	// Left Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(LD.x, LD.y, LD.z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(LU.x, LU.y, LU.z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(sLU.x, sLU.y, sLU.z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(sLD.x, sLD.y, sLD.z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
