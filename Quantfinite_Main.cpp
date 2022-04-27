#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"


class QuantFinite : public olc::PixelGameEngine
{
public:
	QuantFinite()
	{
		sAppName = "QuantFinite";
	}

public:
	bool OnUserCreate() override
	{
		
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		
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