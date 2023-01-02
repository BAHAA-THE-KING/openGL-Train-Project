#pragma once
class ChildrenFootBall
{
public:
	Point goal_bottom_left_back, ball_center;
	float ball_rad, goal_length, goal_depth, goal_hight, safety_distance, interaction_distance, ball_change_x, ball_change_z, direction_z,direction_x;
	int texture_goal, texture_ball;
	ChildrenFootBall(void){};
	~ChildrenFootBall(void){};

	ChildrenFootBall(Point goal_bottom_left_back, Point ball_center,
		float ball_rad, float goal_length, float goal_depth, float goal_hight,
		int texture_goal, int texture_ball)
	{
		this->ball_center=ball_center;
		this->ball_rad=ball_rad;
		this->goal_bottom_left_back=goal_bottom_left_back;
		this->goal_depth=goal_depth;
		this->goal_hight=goal_hight;
		this->goal_length=goal_length;
		this->texture_ball=texture_ball;
		this->texture_goal=texture_goal;
		this->safety_distance=0.5;
		this->interaction_distance=30;
		this->ball_change_x=0;
		this->ball_change_z=0;
		this->direction_x=0;
		this->direction_z=0;
	};
	void DrawChildrenFootBall(bool *keys, Point pos, Point direction)
	{
		InteractionChildrenFootBall(keys,pos,direction);
		glTranslated(goal_bottom_left_back.x,goal_bottom_left_back.y,goal_bottom_left_back.z);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(1,1,1,0.5);
		premitives::DrawCupe(Point(0,0,0),goal_length,goal_hight,goal_depth,texture_goal,1,1,0,1,0,1);
		glDisable(GL_BLEND);
		glColor3f(1,1,1);
		glTranslated(goal_length,goal_hight,0);
		premitives::DrawCylinderBody(Point(0,0,0),0.3,0.3,goal_depth,-1);
		glRotated(90,1,0,0);
		premitives::DrawCylinderBody(Point(0,0,0),0.3,0.3,goal_hight,-1);
		glRotated(-90,1,0,0);
		glTranslated(0,0,goal_depth);
		glRotated(90,1,0,0);
		premitives::DrawCylinderBody(Point(0,0,0),0.3,0.3,goal_hight,-1);
		glRotated(-90,1,0,0);
		glTranslated(-goal_length,-goal_hight,-goal_depth);
		glTranslated(-goal_bottom_left_back.x,-goal_bottom_left_back.y,-goal_bottom_left_back.z);

		premitives::DrawBall(ball_rad,texture_ball,ball_center);
		ball_center.x+=direction_x*ball_change_x;
		ball_center.z+=direction_z*ball_change_z;
		if (ball_change_x>0)
		{
			ball_change_x-=0.2;
		}
		else
			ball_change_x=0;
		if (ball_change_z>0)
		{
			ball_change_z-=0.2;
		}
		else
			ball_change_z=0;
	};
	bool CollisionChildrenFootBall(Point pos)
	{
		float length=goal_length, depth=goal_depth;
		if (pos.x>goal_bottom_left_back.x-safety_distance && pos.x<goal_bottom_left_back.x+length+safety_distance 
			&& pos.z>goal_bottom_left_back.z-safety_distance && pos.z<goal_bottom_left_back.z+depth+safety_distance)
			return 0;
		return 1;
	};


	void InteractionChildrenFootBall(bool *keys, Point pos, Point direction)
	{
		if (abs(pos.x-ball_center.x)<=ball_rad+interaction_distance && abs(pos.z-ball_center.z)<=ball_rad+interaction_distance && keys[VK_SPACE])
		{

			if (ball_center.x<pos.x) 
				direction_x=-1;
			else
				direction_x=1;

			if (ball_center.z<pos.z) 
				direction_z=-1;
			else
				direction_z=1;
			ball_change_x=((int)abs(direction.x)%10)/10.0;
			ball_change_z=((int)abs(direction.z)%10)/10.0;
		}
	};

};

