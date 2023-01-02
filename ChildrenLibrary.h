#pragma once
class ChildrenLibrary
{
public:
	Point bottom_left_back;
	float length, depth, hight, hight_book,safety_distance;
	int texture_library, book_count, *texture_book;
	
	
	ChildrenLibrary(void){};
	~ChildrenLibrary(void){};
	
ChildrenLibrary(Point bottom_left_back,
					float length, float depth, float hight, float hight_book, int book_count,
					int texture_library, int texture_book[])
{
	this->bottom_left_back=bottom_left_back;
	this->depth=depth;
	this->hight=hight;
	this->hight_book=hight_book;
	this->length=length;
	this->texture_book=texture_book;
	this->texture_library=texture_library;
	this->book_count=book_count;
	this->safety_distance=0.5;
};

void DrawChildrenLibrary()
{
	glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);

		float temp=min(length,depth)/20.0;
		premitives::DrawCupe(Point(0,0,0),length,hight,depth,texture_library,0,0,1,1,1,1);
		premitives::DrawCupe(Point(temp,temp,temp),length-temp*2,hight-temp*2,depth-temp*2,texture_library,0,1,1,1,1,1);
		premitives::DrawQuad(Point(0,0,depth),Point(temp,temp,depth-temp),Point(temp,hight-temp,depth-temp),Point(0,hight,depth),texture_library);
		premitives::DrawQuad(Point(0,hight,depth),Point(temp,hight-temp,depth-temp),Point(length-temp,hight-temp,depth-temp),Point(length,hight,depth),texture_library);
		premitives::DrawQuad(Point(length,hight,depth),Point(length-temp,hight-temp,depth-temp),Point(length-temp,temp,depth-temp),Point(length,0,depth),texture_library);
		premitives::DrawQuad(Point(length,0,depth),Point(length-temp,temp,depth-temp),Point(temp,temp,depth-temp),Point(0,0,depth),texture_library);


		int n = hight/hight_book;
		float step=hight/n;
		glPushMatrix();
			
			for (int i=0; i<n; i++)
			{
				premitives::DrawCupe(Point(temp,i*step,temp),length-2*temp,temp,depth-temp,texture_library);
				for (int j=0; j+1<2*(length-2*temp);j++)
				{
					int k=((i*j+i+j)*1345)%book_count;
					premitives::DrawCupe(Point(temp+j/2.0,i*step,temp*2),0.5,hight_book,depth-temp*2,texture_book[k]);
				}
			}

		glPopMatrix();


	glTranslated(-bottom_left_back.x,-bottom_left_back.y,-bottom_left_back.z);

};
bool CollisionChildrenLibrary(Point pos)
{
	if (pos.x>bottom_left_back.x-safety_distance && pos.x<bottom_left_back.x+length+safety_distance 
		&& pos.z>bottom_left_back.z-safety_distance && pos.z<bottom_left_back.z+depth+safety_distance)
		return 0;
	return 1;
};
};

