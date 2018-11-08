#include "Render.h"

render_s Render;
extern directx_s DirectX;
extern draws_s Draw;
extern target_s Target;
extern radar_s Radar;
extern read_s Read;

void render_s::Init()
{
	Radar.Init();
}

struct text_s
{
	int Value;
	int Trigger;

	void Flash(char * string, int x, int y, int r, int g, int b, int times)
	{
		switch (Value)
		{
		case 0:
			Value = 255;
			Trigger++;
			break;
		default:
			Value -= 5;
			break;
		}
		if (Trigger <= times)
		{
			Draw.ShadowText(string, x, y, r, g, b, Value);
		}
	}
};
text_s String[32];


void render_s::ChangeMode()
{
	Time++;

	if (GetAsyncKeyState(VK_F1) & 1)
	{
		Time = 0;
		Allow = true;
		Mode = !Mode;
		
		for (int i = 0; i < 32; i++)
		{
			String[i].Trigger = 0;
			String[i].Value = 0;
		}
	}

	if (Time = 30)
	{
		Allow = false;
	}

	if (Read.Bomb)
	{
		String[2].Flash("Bomb is planted!", Target.Size[0] / 2 - Draw.GetCenterPos("Bomb is planted!") / 2, 225, 255, 0, 0, 10);
	}
}

void render_s::Drawings()
{
	ChangeMode();
	/*switch (Mode)
	{
	case 0:
		String[0].Flash("- 0", Target.Size[0] / 2 - Draw.GetCenterPos("- 0") / 2, Target.Size[1] - 150, 50, 200, 50, 1);
		break;
	case 1:
		String[1].Flash("- 1", Target.Size[0] / 2 - Draw.GetCenterPos("- 1") / 2, Target.Size[1] - 150, 50, 200, 50, 1);
		break;
	case 2:
		String[1].Flash("- 2", Target.Size[0] / 2 - Draw.GetCenterPos("- 2") / 2, Target.Size[1] - 150, 50, 200, 50, 1);
		break;
	case 3:
		String[1].Flash("- 3", Target.Size[0] / 2 - Draw.GetCenterPos("- 3") / 2, Target.Size[1] - 150, 50, 200, 50, 1);
		break;
	}*/

	Radar.Show();
	WaterMark();
	Draw.Text("+", Target.Size[0] / 2 - 3, Target.Size[1] / 2 - 8, 255, 0, 0);
}

void render_s::WaterMark()
{
	currentTick = clock() * 0.001f;
	Frames++;

	if (currentTick - oldTick > 1.0f)
	{
		oldTick = currentTick;
		sprintf_s(Frames_Char, "[FPS: %i]", Frames);
		Frames = 0;
	}

	sprintf_s(waterMark_char, "Clear Vision - MOD", Frames_Char);
	Draw.ShadowText(waterMark_char, 10 , 10 , 255, 255, 255, 255);
}





