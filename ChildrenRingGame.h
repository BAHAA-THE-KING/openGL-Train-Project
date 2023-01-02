#pragma once
class ChildrenRingGame
{
public:
	Point center;
	float rad, hight, safety_distance;
	int texture_base, texture_cylinder;
	ChildrenRingGame(void){};
	~ChildrenRingGame(void){};

ChildrenRingGame(Point center, float rad, float hight, int texture_base, int texture_cylinder)
{
	this->center=center;
	this->hight=hight;
	this->rad=rad;
	this->texture_base=texture_base;
	this->texture_cylinder=texture_cylinder;
	this->safety_distance=0.5;
};

void DrawChildrenRingGame()
{
	float step = max(0.1,(rad-1)/7.0);
	glPushMatrix();
	glTranslated(center.x,center.y,center.z);


	glRotated(-90,1,0,0);
	premitives::DrawCylinderBody(Point(0,0,0),rad,rad,step,texture_base);
	premitives::DrawRing(Point (0,0,0), 0,rad,texture_base);
	glTranslated(0,0,step);
	premitives::DrawRing(Point (0,0,0), 0,rad,texture_base);
	premitives::DrawCylinderBody(Point(0,0,0),step,step,hight,texture_cylinder);
	premitives::DrawRing(Point (0,0,hight), 0,step,texture_cylinder);

	
	for (int i=1; i<=7; i++)
	{
		glColor3f(i&1, (i&2)/2, (i&4)/4);
		premitives::DrawRing(Point(0,0,0),rad-i*step-step-0.1,rad-i*step,-1);
		premitives::DrawCylinderBody(Point(0,0,0),rad-i*step,rad-i*step,step,-1);
		premitives::DrawCylinderBody(Point(0,0,0),rad-i*step-step-0.1,rad-i*step-step-0.1,step,-1);
		glTranslated(0,0,step);
		premitives::DrawRing(Point(0,0,0),rad-i*step-step-0.1,rad-i*step,-1);
	}

	glPopMatrix();

};


bool CollisionChildrenRingGame(Point pos)
{
	if (Point::distance(pos,center)<= rad+safety_distance)
		return 0;
	return 1;
};
};

