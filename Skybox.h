#pragma once
class Skybox
{
public:
	Point bottom_left_back;
	float length, depth, hight;
	int texture;
	Skybox(void){};
	~Skybox(void){};

	Skybox(Point bottom_left_back, float length, float depth, float hight, int texture)
	{
		this->bottom_left_back=bottom_left_back;
		this->depth=depth;
		this->hight=hight;
		this->length=length;
		this->texture=texture;
	};

	void DrawSkybox()
	{
		glPushMatrix();
		premitives::DrawCupe(bottom_left_back,length,hight,depth,texture);
		glPopMatrix();
	};
};

