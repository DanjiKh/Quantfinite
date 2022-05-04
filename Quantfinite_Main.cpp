/*      
            -=< QuantFinite >=-

    Project with using olcPixelGameEngine

    Now without license
 
    More information coming soon...
*/

//	Game engine includes
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

//	Standard includes
#include <iostream>


//	Game Class
class QuantFinite : public olc::PixelGameEngine
{
private:
	uint64_t m_char_layer = 0;


public:
	QuantFinite()
	{
		sAppName = "QuantFinite";
	};


//	Structures for game objects
public:

	struct AABB 		//Axis Aligned Bounding Box
	{
		olc::vf2d min;
		olc::vf2d max;
	};

	struct Circle
	{
		float r;
		olc::vf2d pos;
	};

	/*struct Quant {
		uint64_t layer;
		olc::vf2d pos;
		olc::vf2d size;
		olc::vf2d scale;

		//	TODO: Finish structure for game character.
	};

	struct hitbox {
		olc::vf2d pos;
		olc::vf2d size;

		//	TODO: Create settings for hitbox.
	};*/


//	Functions 
public:

	bool AABBvsAABB( const AABB& a, const AABB& b )
	{
  		if( ( a.max.x < b.min.x ) || ( a.min.x > b.max.x ) ) return false;
  		if( ( a.max.y < b.min.y ) || ( a.min.y > b.max.y ) ) return false;
		
  		return true;
	};

	bool CirclevsCircle( const Cirlce& a, const Circle& b )
	{
		float r2 = a.r + b.r;
  		r2 *= r2;
  		return r < (a.x + b.x)^2 + (a.y + b.y)^2;
	};
	
	/*bool PointVsHitbox(const olc::vf2d& p, const hitbox& hb) {
		return (p.x >= hb.pos.x 
			&& p.y >= hb.pos.y 
			&& p.x < hb.pos.x + hb.size.x 
			&& p.y < hb.pos.y + hb.size.y);	
	};

	bool HitboxVsHitbox(const hitbox& hb1, const hitbox& hb2) {
		return (hb1.pos.x < hb2.pos.x + hb2.size.x && hb1.pos.x + hb1.size.x > hb2.pos.x &&
				hb1.pos.y < hb2.pos.y + hb2.size.y && hb1.pos.y + hb1.size.y > hb2.pos.y);
	};

	bool RayVsHitbox() 
	{
		//	TODO: Create a normal clollision.
		

		return true; 
	};*/


//	Engine functions
public:
	bool OnUserCreate() override
	{	
		Quant game_char_shell = 
		{
			//	TODO: Add character settings.
		};
		
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{



		/*olc::vf2d pMouse = {float(GetMouseX()), float(GetMouseY())};

		hitbox hb = {{100.0f, 100.0f}, {50.0f, 50.0f}};

		olc::vf2d ray_point = {200.0f, 200.0f};
		olc::vf2d ray_direction = pMouse - ray_point;
		
		Clear(olc::DARK_BLUE);
		
		DrawLine(ray_point, pMouse, olc::GREEN); 

		
		
		DrawRect(hb2.pos, hb2.size, olc::GREEN);

		if(HitboxVsHitbox(hb2, hb))
			DrawRect(hb.pos, hb.size, olc::YELLOW);
		else
			DrawRect(hb.pos, hb.size, olc::WHITE);
		*/

		return true;
	}	
};

int main()
{
	QuantFinite demo;
	if ( demo.Construct( 256, 240, 4, 4 ) )
		demo.Start();
	return 0;
}