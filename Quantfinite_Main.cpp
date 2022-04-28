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

//	Structures for game objects
struct Quant {
	uint64_t layer;
	olc::vf2d pos;
	olc::vf2d size;
	olc::vf2d scale;
};

//	Main game Class
class QuantFinite : public olc::PixelGameEngine
{
private:
	std::vector<Quant> m_char;
	uint64_t m_char_layer = 0;

public:
	QuantFinite()
	{
		sAppName = "QuantFinite";
	};

	struct hitbox {
		olc::vf2d pos;
		olc::vf2d size;
	};

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

public:
	bool OnUserCreate() override
	{
		
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		olc::vf2d pMouse = {float(GetMouseX()), float(GetMouseY())};
		hitbox hb = {{100.0f, 100.0f}, {50.0f, 50.0f}};

		hitbox hb2 = {pMouse, {10.0f, 40.0f}};

		Clear(olc::DARK_BLUE);

		DrawRect(hb2.pos, hb2.size, olc::GREEN);

		if(HitboxVsHitbox(hb2, hb))
			DrawRect(hb.pos, hb.size, olc::YELLOW);
		else
			DrawRect(hb.pos, hb.size, olc::WHITE);

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