#pragma once
class ChildrenTableWithChair
{
public:
	Point bottom_left_back;
	float table_length, table_depth, table_hight_leg, table_hight_body,safety_distance;
	float chair_length, chair_hight_leg, chair_hight_body;
	int texture_table, texture_chair;
	ChildrenTableWithChair(void){};
	~ChildrenTableWithChair(void){};
	
ChildrenTableWithChair(	Point bottom_left_back,
						float table_length, float table_depth, float table_hight_leg, float table_hight_body,
						float chair_length, float chair_hight_leg, float chair_hight_body,
						int texture_table, int texture_chair)
{
	this->bottom_left_back=bottom_left_back;
	this->chair_hight_body=chair_hight_body;
	this->chair_hight_leg=chair_hight_leg;
	this->chair_length=chair_length;
	this->table_depth=table_depth;
	this->table_hight_body=table_hight_body;
	this->table_hight_leg=table_hight_leg;
	this->table_length=table_length;
	this->texture_table=texture_table;
	this->texture_chair=texture_chair;
	this->safety_distance=0.5;
};


void DrawChildrenTableWithChair()
{
	glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);
		
		glPushMatrix();
			glTranslated(chair_length*1.5,0,chair_length*1.5);
			ChildrenTable temptable = ChildrenTable(Point (0,0,0), table_length,table_depth,table_hight_leg,table_hight_body,texture_table);
			temptable.DrawChildrenTable();
		glPopMatrix();
		

		glPushMatrix();
				glTranslated(chair_length*2,0,0);
				for (float i=0; i<table_length-chair_length/2.0; i+=chair_length*1.5)
				{
					ChildrenTable tempchair = ChildrenTable(Point (i,0,0), chair_length,chair_length,chair_hight_leg,chair_hight_body,texture_chair);
					tempchair.DrawChildrenTable();
					premitives::DrawCupe(Point(i,chair_hight_leg/2.0,0),chair_length,chair_hight_leg/5.0,chair_length,texture_chair,1,1,1,1,0,0);
				}
		glPopMatrix();


		glPushMatrix();
			glTranslated(chair_length*2,0,table_depth+chair_length*2);
				for (float i=0; i<table_length-chair_length/2.0; i+=chair_length*1.5)
				{
					ChildrenTable tempchair = ChildrenTable(Point (i,0,0), chair_length,chair_length,chair_hight_leg,chair_hight_body,texture_chair);
					tempchair.DrawChildrenTable();
					premitives::DrawCupe(Point(i,chair_hight_leg/2.0,0),chair_length,chair_hight_leg/5.0,chair_length,texture_chair,1,1,1,1,0,0);
				}
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(0,0,chair_length*2);
				for (float i=0; i<table_depth-chair_length/2.0; i+=chair_length*1.5)
				{
					ChildrenTable tempchair = ChildrenTable(Point (0,0,i), chair_length,chair_length,chair_hight_leg,chair_hight_body,texture_chair);
					tempchair.DrawChildrenTable();
					premitives::DrawCupe(Point(0,chair_hight_leg/2.0,i),chair_length,chair_hight_leg/5.0,chair_length,texture_chair,1,1,1,1,0,0);
				}
		glPopMatrix();


		glPushMatrix();
			glTranslated(table_length+chair_length*2,0,chair_length*2);
				for (float i=0; i<table_depth-chair_length/2.0; i+=chair_length*1.5)
				{
					ChildrenTable tempchair = ChildrenTable(Point (0,0,i), chair_length,chair_length,chair_hight_leg,chair_hight_body,texture_chair);
					tempchair.DrawChildrenTable();
					premitives::DrawCupe(Point(0,chair_hight_leg/2.0,i),chair_length,chair_hight_leg/5.0,chair_length,texture_chair,1,1,1,1,0,0);
				}
		glPopMatrix();
	glTranslated(-bottom_left_back.x,-bottom_left_back.y,-bottom_left_back.z);

};


bool CollisionChildrenTableWithChair(Point pos)
{
	float length=table_length+3*chair_length, depth=table_depth+3*chair_length;
	if (pos.x>bottom_left_back.x-safety_distance && pos.x<bottom_left_back.x+length+safety_distance 
		&& pos.z>bottom_left_back.z-safety_distance && pos.z<bottom_left_back.z+depth+safety_distance)
		return 0;
	return 1;
};
};

