#pragma once
class ChildrenTrailler :
	public Trailler
{
public:
	ChildrenFootBall football;
	ChildrenLibrary library;
	ChildrenRingGame ringgame;
	ChildrenTableWithChair table;
	ChildrenTent tent;
	ChildrenWheelGame wheelgame;
	ChildrenTrailler(void){};
	~ChildrenTrailler(void){};
	ChildrenTrailler(Point bottom_left_back, float length, float hight, float depth,
		float door_length, float door_hight, bool door_is_right,
		float window_hight, bool window_is_left, bool window_is_right,
		float way_length, float way_hight, 
		float wheel_rad, float wheel_length, float wheel_width,
		int texture_in_front,int texture_in_back,int texture_in_left,int texture_in_right,int texture_in_top,int texture_in_bottom,
		int texture_out_front,int texture_out_back,int texture_out_left,int texture_out_right,int texture_out_top,int texture_out_bottom,
		int texture_cover, int texture_cover_box, int texture_window,
		int texture_door, int texture_fence, int texture_way, int texture_wheel, int texture_wheel_stick,
		int book_count, int texture_library, int texture_book[],
		int texture_table, int texture_chair,
		int texture_ring_base, int texture_ring_cylinder,
		int texture_around, int texture_front,
		int texture_game_wheel, int texture_game_cylinder, int texture_game_carpet,
		int texture_goal, int texture_ball) : Trailler( bottom_left_back,  length,  hight,  depth,
		door_length,  door_hight,  door_is_right,
		window_hight,  window_is_left,  window_is_right,
		way_length,  way_hight, 
		wheel_rad,  wheel_length,  wheel_width,
		texture_in_front, texture_in_back, texture_in_left, texture_in_right, texture_in_top, texture_in_bottom,
		texture_out_front, texture_out_back, texture_out_left, texture_out_right, texture_out_top, texture_out_bottom,
		texture_cover,  texture_cover_box,  texture_window,
		texture_door,  texture_fence,  texture_way,  texture_wheel,  texture_wheel_stick)
	{
		float sub_wall = (length-door_length)/2.0;
		this->library=ChildrenLibrary(Point(length-sub_wall+1,0,0), sub_wall-2,depth/20.0,hight/3.0,hight/10.0,book_count,texture_library,texture_book);
		this->table = ChildrenTableWithChair(Point(length-sub_wall+1,0,depth/20.0+depth/13.0),sub_wall/3.0,depth/3.0, hight/9.0,hight/40.0,sub_wall/9.0,hight/15,hight/40.0,texture_table,texture_chair);
		this->ringgame = ChildrenRingGame(Point(length-sub_wall/5.0,0,2*depth/3.0),sub_wall/10.0,hight/9.0,texture_ring_base,texture_ring_cylinder);
		this->tent = ChildrenTent(Point (sub_wall/8.0,0,depth/13.0) , 6*sub_wall/8.0,6*sub_wall/8.0,hight/2.0,texture_around,texture_front);
		this->wheelgame = ChildrenWheelGame(Point (sub_wall/4.0+sub_wall/5.0,0,depth/3.0),Point (sub_wall/4.0,0.2,depth/3.0+depth/10.0),sub_wall/10.0,sub_wall/6.0,0.6*sub_wall,depth/5.0,texture_game_wheel,texture_game_cylinder,texture_game_carpet);
		this->football = ChildrenFootBall(Point(sub_wall/10.0,0,depth-depth/4.0), Point(sub_wall/2.0,sub_wall/20.0,depth-depth/4.0), sub_wall/20.0,sub_wall/10.0,depth/8.0,hight/5.0,texture_goal,texture_ball);


		Trailler::window[0].bottom_left_back.y+=1;
		Trailler::window[0].bottom_left_back.z+=1;
		Trailler::window[1].bottom_left_back.x+=2;
		Trailler::window[1].bottom_left_back.y+=1;
		Trailler::window[1].bottom_left_back.z+=1;




		Trailler::door[2].bottom_left.x+=1;



	};



	void DrawChildrenTrailler(bool *keys, Point old_pos, Point direction)
	{
		Trailler::DrawTraillerIn(keys,old_pos);

		glTranslated(bottom_left_back.x,bottom_left_back.y,bottom_left_back.z);



		float sub_wall = (length-Trailler::door[0].length)/2;
		premitives::DrawCupe(Point(sub_wall,0,-1),door[0].length,door[0].hight-1,1,texture_in_back,0,0,1,1,0,1);
		premitives::DrawQuad(Point(sub_wall,door[0].hight-1,0),Point(sub_wall+door[0].length,door[0].hight-1,0),Point(sub_wall+door[0].length,door[0].hight,0),Point(sub_wall,door[0].hight,0),texture_in_back);
		premitives::DrawCupe(Point(sub_wall,0,depth),door[0].length,door[0].hight-1,1,texture_in_front,0,0,1,1,0,1);
		premitives::DrawQuad(Point(sub_wall,door[0].hight-1,depth),Point(sub_wall+door[0].length,door[0].hight-1,depth),Point(sub_wall+door[0].length,door[0].hight,depth),Point(sub_wall,door[0].hight,depth),texture_in_front);
		sub_wall=(depth-Trailler::door[2].length)/2;
		premitives::DrawCupe(Point(length,0,depth-door[2].length+1),1,door[2].hight-1,door[2].length-1,texture_in_right,1,1,0,0,1,1);
		premitives::DrawQuad(Point(length,door[2].hight-1,depth-door[2].length+1),
			Point(length,door[2].hight-1,depth),
			Point(length,door[2].hight,depth),
			Point(length,door[2].hight,depth-door[2].length+1),texture_in_right);

		premitives::DrawCupe(Point(Trailler::window[0].bottom_left_back.x-1,Trailler::window[0].bottom_left_back.y-Trailler::window[0].hight-1,Trailler::window[0].bottom_left_back.z-1),
			1,Trailler::window[0].hight,Trailler::window[0].length,texture_in_left,1,1,0,0,1,1);
		premitives::DrawCupe(Point(Trailler::window[1].bottom_left_back.x-2,Trailler::window[1].bottom_left_back.y-Trailler::window[1].hight-1,Trailler::window[1].bottom_left_back.z-1),
			1,Trailler::window[1].hight,Trailler::window[1].length,texture_in_right,1,1,0,0,1,1);

		premitives::DrawQuad(Point(length+0.6,-1,depth-door[2].length+1),
			Point(length+0.6,-1,depth),
			Point(length+0.6,0,depth),
			Point(length+0.6,0,depth-door[2].length+1),texture_out_right);

		premitives::DrawQuad(Point(length+0.6,-1,depth+1),
			Point(length+0.6,-1,depth),
			Point(length+0.6,hight+1,depth),
			Point(length+0.6,hight+1,depth+1),texture_out_right);


		premitives::DrawQuad(Point(length+1,0,depth-door[2].length+1),
			Point(length+1,0,depth-door[2].length),
			Point(length+1,hight,depth-door[2].length),
			Point(length+1,hight,depth-door[2].length+1),texture_out_right);


		premitives::DrawQuad(Point(length,0,depth-door[2].length+1),
			Point(length,0,depth-door[2].length),
			Point(length,hight,depth-door[2].length),
			Point(length,hight,depth-door[2].length+1),texture_in_right);



		Point pos = Point (old_pos.x-bottom_left_back.x,old_pos.y-bottom_left_back.y,old_pos.z-bottom_left_back.z);
		library.DrawChildrenLibrary();
		table.DrawChildrenTableWithChair();
		ringgame.DrawChildrenRingGame();
		tent.DrawChildrenTent();
		wheelgame.DrawChildrenWheelGame(keys,pos);
		football.DrawChildrenFootBall(keys,pos,direction);
		glTranslated(-bottom_left_back.x,-bottom_left_back.y,-bottom_left_back.z);




		Trailler::bottom_left_back.x-=1;
		Trailler::bottom_left_back.y-=1;
		Trailler::bottom_left_back.z-=1;
		Trailler::length+=2;
		Trailler::hight+=2;
		Trailler::depth+=2;

		Trailler::DrawTrailler(keys,old_pos);

		Trailler::bottom_left_back.x+=1;
		Trailler::bottom_left_back.y+=1;
		Trailler::bottom_left_back.z+=1;
		Trailler::length-=2;
		Trailler::hight-=2;
		Trailler::depth-=2;
	};

	bool CollisionChildrenTrailler(Point pos)
	{
		Point new_pos = Point (pos.x-bottom_left_back.x,pos.y-bottom_left_back.y,pos.z-bottom_left_back.z);
		if (CollisionTrailler(pos) && library.CollisionChildrenLibrary(new_pos) && table.CollisionChildrenTableWithChair(new_pos) && ringgame.CollisionChildrenRingGame(new_pos) && tent.CollisionChildrenTent(new_pos) && wheelgame.CollisionChildrenWheelGame(new_pos) && football.CollisionChildrenFootBall(new_pos))
			return 1;
		return 0;
	};
};

