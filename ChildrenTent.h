#pragma once
class ChildrenTent
{
public:
	Point bottom_left_back;
	float depth,length, hight, safety_distance;
	int texture_around, texture_front;
	ChildrenTent(void){};
	~ChildrenTent(void){};

	ChildrenTent::ChildrenTent(Point bottom_left_back, float depth, float length, float hight, int texture_around, int texture_front)
	{
		this->bottom_left_back=bottom_left_back;
		this->depth=depth;
		this->hight=hight;
		this->length=length;
		this->texture_around=texture_around;
		this->texture_front=texture_front;
		this->safety_distance=0.5;
	};
	void DrawChildrenTent()
	{
		glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);

		glBindTexture( GL_TEXTURE_2D ,texture_around);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0,0);
		glVertex3f(0,0,0);

		glTexCoord2f(1,0);
		glVertex3f(length,0,0);

		glTexCoord2f(0,1);
		glVertex3f(length/2.0,hight,depth/2);


		glTexCoord2f(0,0);
		glVertex3f(0,0,0);

		glTexCoord2f(1,0);
		glVertex3f(0,0,depth);

		glTexCoord2f(0,1);
		glVertex3f(length/2.0,hight,depth/2.0);



		glTexCoord2f(0,0);
		glVertex3f(length,0,0);

		glTexCoord2f(1,0);
		glVertex3f(length,0,depth);

		glTexCoord2f(0,1);
		glVertex3f(length/2.0,hight,depth/2.0);
		glEnd();


		glBindTexture( GL_TEXTURE_2D ,texture_front);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(0,0);
		glVertex3f(0,0,depth);

		glTexCoord2f(1,0);
		glVertex3f(length,0,depth);

		glTexCoord2f(0.5,1);
		glVertex3f(length/2.0,hight,depth/2);
		glEnd();
		glTranslated(-bottom_left_back.x,-bottom_left_back.y,-bottom_left_back.z);

	};
	bool CollisionChildrenTent( Point pos)
	{
		if (pos.x>bottom_left_back.x-safety_distance && pos.x<bottom_left_back.x+length+safety_distance 
			&& pos.z>bottom_left_back.z-safety_distance && pos.z<bottom_left_back.z+depth+safety_distance)
			return 0;
		return 1;
	};
};

