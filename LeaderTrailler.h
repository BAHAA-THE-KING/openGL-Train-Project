#pragma once
#include "Point.h"
#include "Door.h"
#include "Wheel.h"
class LeaderTrailler
{
public:


	Point bottom_left_back; float length; float hight_cube; float hight_dome; float depth_cube;
	float depth_face;  float depth_coal; float length_coal; 
	Point Holocaust_bottom_left_back ;float Holocaust_length; float Holocaust_hight_cube; float Holocaust_depth; int Holocaust_fire_count;
	float door_length; float door_hight;
	float length_way;
	float  hight_face;
	float  Holocaust_hight_cylinder, Holocaust_rad_cylinder;
	int Holocaust_fire_curr; 
	Door d ;
	Door d_holo;
	vector <Wheel> wheel;
	int texture_body, texture_glass, texture_holocaust_cube, texture_holocaust_cylinder, texture_holocaust_door, *texture_holocaust_fire, texture_smoke,texture_coal, texture_control_panel, texture_iron;
	float 	safety_distance;

	LeaderTrailler(void);
	~LeaderTrailler(void);
	LeaderTrailler(Point bottom_left_back, float length, float hight_cube, float hight_dome, float depth_cube,
				float depth_face,  float depth_coal, float length_coal, 
				float Holocaust_length, float Holocaust_hight_cube, float Holocaust_depth, int Holocaust_fire_count,
				float door_length, float door_hight,
				float wheel_rad, float wheel_length,float wheel_width,
				int texture_body, int texture_glass, int texture_door,int texture_smoke , int texture_coal,
				int texture_holocaust_cube, int texture_holocaust_cylinder, int texture_holocaust_door, int texture_holocaust_fire[],
				int texture_wheel, int texture_wheel_stick, int texture_control_panel, int texture_iron);
	void DrawLeaderTrailler(bool *keys, Point pos);
	bool CollisionTrailler(Point pos);



private:
	void DrawBottom();
	void DrawTop();
	void DrawLeft();
	void DrawRight(bool *keys, Point pos);
	void DrawBack();
	void DrawHolocaust(bool *keys, Point pos);
	void DrawCoalTrailler();



	
	bool CollisionTop(Point pos);
	bool CollisionBottom(Point pos);
	bool CollisionBack(Point pos);
	bool CollisionLeft(Point pos);
	bool CollisionRight(Point pos);
	bool CollisionFront(Point pos);
	bool CollisionBetweenWall(Point pos);
	bool CollisionHolocaust(Point pos);

};

