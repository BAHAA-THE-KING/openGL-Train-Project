#pragma once
class ChildrenWheelGame
{
public:
	Point center_wheel, left_back_carpet;
	float wheel_rad, wheel_hight_cylinder, carpet_length, carpet_depth,safety_distance, interaction_distance;
	int wheel_angle, timer;
	int texture_wheel, texture_cylinder, texture_carpet;
	ChildrenWheelGame(void){};
	~ChildrenWheelGame(void){};

	ChildrenWheelGame(Point center_wheel, Point left_back_carpet,
		float wheel_rad, float wheel_hight_cylinder, float carpet_length, float carpet_depth,
		int texture_wheel, int texture_cylinder, int texture_carpet)
	{
		this->center_wheel=center_wheel;
		this->carpet_depth=carpet_depth;
		this->carpet_length=carpet_length;
		this->left_back_carpet=left_back_carpet;
		this->texture_carpet=texture_carpet;
		this->texture_cylinder=texture_cylinder;
		this->texture_wheel=texture_wheel;
		this->wheel_hight_cylinder=wheel_hight_cylinder;
		this->wheel_rad=wheel_rad;
		this->safety_distance=0.5;
		this->interaction_distance=300;
		this->wheel_angle=-90;
		this->timer=0;

	};
	void DrawChildrenWheelGame(bool *keys, Point pos)
	{
		InteractionChildrenWheelGame(keys,pos);
		glPushMatrix();
		glTranslated(center_wheel.x,center_wheel.y,center_wheel.z);
		glRotated(-90,1,0,0);
		premitives::DrawCylinderBody(Point(0,0,0),0.3,0.3,wheel_hight_cylinder,texture_cylinder);
		glRotated(90,1,0,0);
		glTranslated(0,wheel_hight_cylinder,0);
		premitives::DrawCylinderBody(Point(0,0,0),0.3,0.3,1,texture_cylinder);
		glBindTexture(GL_TEXTURE_2D,texture_wheel);
		glBegin(GL_POLYGON);
		for(float angle=0; angle<=2*3.14; angle+=(2*3.14)/20)
		{
			glTexCoord2f(0.5+cos(angle)/2.0,0.5+sin(angle)/2.0);
			glVertex3f(wheel_rad*cos(angle),wheel_rad*sin(angle),1);
		}	
		glEnd();
		glBindTexture(GL_TEXTURE_2D,texture_cylinder);
		glRotated(wheel_angle,0,0,1);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0,0);
		glVertex3f(-0.1*wheel_rad,-0.1*wheel_rad,1.2);
		glTexCoord2f(1,0);
		glVertex3f(0.8*wheel_rad,0,1.1);
		glTexCoord2f(0.5,1);
		glVertex3f(-0.1*wheel_rad,0.1*wheel_rad,1.2);
		glEnd();
		glPopMatrix();
		glTranslated(left_back_carpet.x,left_back_carpet.y,left_back_carpet.z);
		premitives::DrawQuad(Point (0,0.2,carpet_depth),Point (carpet_length,0,carpet_depth),Point (carpet_length,0,0),Point (0,0,0),texture_carpet);
		glTranslated(-left_back_carpet.x,-left_back_carpet.y,-left_back_carpet.z);
		if (timer>0) 
		{
			timer--;
			wheel_angle+=timer;
			wheel_angle%=360;
		}
	};
	bool CollisionChildrenWheelGame(Point pos)
	{
		if (abs(pos.x-center_wheel.x)<=wheel_rad+safety_distance && abs(pos.z-center_wheel.z)<=wheel_rad+safety_distance)
			return 0;
		return 1;
	};

	void InteractionChildrenWheelGame(bool *keys, Point pos)
	{
		if (Point::distance(pos,center_wheel)<=wheel_rad+interaction_distance && timer<=0 && keys['P'])
		{
			timer=rand()%50+20;
		}
	};
};

