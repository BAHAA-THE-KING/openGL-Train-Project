#pragma once
class ChildrenTable
{
public:
	Point bottom_left_back;
	float length, depth, hight_leg, hight_body, length_leg;
	int texture;
	ChildrenTable(void){};
	~ChildrenTable(void){};

	ChildrenTable(Point bottom_left_back, float length, float depth, float hight_leg, float hight_body, int texture)
	{
		this->bottom_left_back=bottom_left_back;
		this->depth=depth;
		this->hight_body=hight_body;
		this->hight_leg=hight_leg;
		this->length=length;
		this->texture=texture;
		this->length_leg=min(length,depth)/10.0;
	};

	void DrawChildrenTable()
	{
		glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);

		glPushMatrix();
		glTranslated(length/10.0,0,depth/10.0);
		premitives::DrawCupe(Point(0,0,0),length_leg,hight_leg,length_leg,texture);

		glTranslated(8*length/10.0,0,0);
		premitives::DrawCupe(Point(0,0,0),length_leg,hight_leg,length_leg,texture);

		glTranslated(0,0,8*depth/10.0);
		premitives::DrawCupe(Point(0,0,0),length_leg,hight_leg,length_leg,texture);

		glTranslated(-8*length/10.0,0,0);
		premitives::DrawCupe(Point(0,0,0),length_leg,hight_leg,length_leg,texture);
		glPopMatrix();

		glPushMatrix();	
		glTranslated(0,hight_leg,0);
		premitives::DrawCupe(Point(0,0,0),length,hight_body, depth,texture);
		glPopMatrix();

		glTranslated(-bottom_left_back.x,-bottom_left_back.y,-bottom_left_back.z);
	};


};

