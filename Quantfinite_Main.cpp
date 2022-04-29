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


//	Main game Class
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
	struct Quant {
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
	};


//	Functions 
public: 
	bool PointVsHitbox(const olc::vf2d& p, const hitbox& hb) {
		return (p.x >= hb.pos.x 
			&& p.y >= hb.pos.y 
			&& p.x < hb.pos.x + hb.size.x 
			&& p.y < hb.pos.y + hb.size.y);	
	};

	bool HitboxVsHitbox(const hitbox& hb1, const hitbox& hb2) {
		return (hb1.pos.x < hb2.pos.x + hb2.size.x && hb1.pos.x + hb1.size.x > hb2.pos.x &&
				hb1.pos.y < hb2.pos.y + hb2.size.y && hb1.pos.y + hb1.size.y > hb2.pos.y);
	};

	bool RayVsHitbox(const olc::vf2d& ray_origin, const olc::vf2d& ray_dir, const hitbox& target,
			olc::vf2d& contact_point, olc::vf2d& contact_normal, float& t_hit_near) 

	{
		//	TODO: Create a normal clollision.
		olc::vf2d t_near = (target.pos - ray_origin) / ray_dir;
		olc::vf2d t_far = (target.pos + target.size - ray_origin) / ray_dir;
		
		if (t_near.x > t_far.x) std::swap(t_near.x, t_far.x);
		if (t_near.y > t_far.y) std::swap(t_near.x, t_far.y);
		

		if (t_near.x > t_far.y || t_near.y > t_far.x) return false;

		t_hit_near = std::max(t_near.x, t_near.y);
		float t_hit_far = std::min(t_far.x, t_far.y);

		if (t_hit_far < 0) return false;


		contact_point = ray_origin + t_hit_near * ray_dir;

		if (t_near.x > t_near.y)
			if (ray_dir.x < 0)
				contact_normal = {1,0};
			else
				contact_normal = {-1, 0};
		else if (t_near.x < t_near.y)
			if (ray_dir.y < 0)
				contact_normal = {0, 1};
			else
				contact_normal = {0, -1};

		return true; 
	};


//	Engine functions
public:
	bool OnUserCreate() override
	{	
		Quant game_char_shell = {
			//	TODO: Add character settings.
		};
		
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		olc::vf2d pMouse = {float(GetMouseX()), float(GetMouseY())};

		hitbox hb = {{100.0f, 100.0f}, {50.0f, 50.0f}};

		olc::vf2d ray_point = {200.0f, 200.0f};
		olc::vf2d ray_direction = pMouse - ray_point;
		
		Clear(olc::DARK_BLUE);
		
		DrawLine(ray_point, pMouse, olc::GREEN); 

		olc::vf2d cp, cn;
		float t;

		if (RayVsHitbox(ray_point, ray_direction, hb, cp, cn, t) && t <= 1.0f) {
			DrawRect(hb.pos, hb.size, olc::YELLOW);
			FillCircle(cp, 3, olc::RED);
			DrawLine(cp, cp + cn * 10);
		}

		else {
			DrawRect(hb.pos, hb.size, olc::WHITE);
		}
		
		/*DrawRect(hb2.pos, hb2.size, olc::GREEN);

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
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
}