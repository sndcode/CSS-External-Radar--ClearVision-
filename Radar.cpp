#include "Radar.h"

extern draws_s Draw;
extern target_s Target;
extern read_s Read;
extern render_s Render;
extern CBasePlayer_s CBasePlayer;
extern RadarArray_s RadarArray[32];
radar_s Radar;

Vec2 Center;
Vec2 RadarCenter;

//struct player 
//{
//	BYTE hp;
//	char name[32];
//	BYTE team;
//	float x;
//	float y;
//	float z;
//	float pitch;
//	float yaw;
//	float roll;
//} players[32] = { 0 };


void radar_s::Init()
{
	Size = 160;
	Center.x = Target.Size[0] / 2;
	Center.y = Target.Size[1] / 2;

	RadarCenter.x = Center.x;
	RadarCenter.y = 50 + Radar.Size / 2;
}

void radar_s::Show()
{
	Draw.BorderFilledBox(Center.x - Radar.Size / 2, 50, Radar.Size, Radar.Size, 50, 50, 50, 180, 180, 180, 200);

	Draw.Line(Center.x - Radar.Size / 2, 50 + Radar.Size / 2, Center.x + Radar.Size / 2, 50 + Radar.Size / 2, 80, 80, 80, 255);
	Draw.Line(Center.x, 50, Center.x, 50 + Radar.Size, 80, 80, 80, 255);
	Draw.FilledBox(Center.x - 1, (50 + Radar.Size / 2) - 1, 2, 2, 50, 50, 50, 255);
	//
	//sprintf_s(radarText, "%s", CBasePlayer.ZoneName);//Zone Name
	//Draw.ShadowText(radarText, Center.x - Draw.GetCenterPos(radarText) / 2, 50 + Radar.Size, 50, 200, 50, 255);

	if (GetAsyncKeyState(VK_F2))
		exit(1);

	Main();
}

void radar_s::Main()
{

	for (int i = 0; i < 32; i++)
	{
		Read.GetBasePlayer();
		Read.GetRadarBase(i);
		int RadarX, RadarY;

		RadarX = CBasePlayer.Origin.x - RadarArray[i].Origin.x;
		RadarY = CBasePlayer.Origin.y - RadarArray[i].Origin.y;

		char Tempo[256];
		//sprintf_s(Tempo, "HP = %i", CBasePlayer.Health);//Health Player
		//Draw.ShadowText(Tempo, 50, 50, 255, 0, 0, 255);

		float Angle = CBasePlayer.Viewaxis.y /* .x *// 180 * 3.141;

		float RotateX = RadarY * cos(Angle) - RadarX * sin(Angle);
		float RotateY = RadarX * cos(Angle) + RadarY * sin(Angle);

		float FinalX = RadarCenter.x + RotateX / 10;
		float FinalY = RadarCenter.y + RotateY / 10;

		if (FinalX < Center.x - Radar.Size / 2) FinalX = (Center.x - Radar.Size / 2) + 2;
		if (FinalY < RadarCenter.y - Radar.Size / 2) FinalY = (RadarCenter.y - Radar.Size / 2) + 2;

		if (FinalX > Center.x + Radar.Size / 2) FinalX = (Center.x + Radar.Size / 2) - 2;
		if (FinalY > RadarCenter.y + Radar.Size / 2) FinalY = (RadarCenter.y + Radar.Size / 2) - 2;

		if (RadarArray[i].Health >= 1 && RadarArray[i].Origin.x != 0 && RadarArray[i].Origin.y != 0 && Read.ClientNum != RadarArray[i].clientNum)
		{
			if (Render.Mode == 0 && RadarArray[i].Team != CBasePlayer.Team)
			{
				ColorR = 255;
				ColorG = 0;
				ColorB = 0;

				Draw.BorderFilledBox(FinalX - 2, FinalY - 2, 4, 4, 0, 0, 0, ColorR, ColorG, ColorB, 255);
				Draw.BorderFilledBox(FinalX - 5, FinalY + 4, RadarArray[i].Health * 10 / 100, 4, 0, 0, 0, 0, 255, 0, 255);
			}
			else if (Render.Mode == 1)
			{
				if (RadarArray[i].Team != CBasePlayer.Team)
				{
					ColorR = 255;
					ColorG = 0;
					ColorB = 0;

					Draw.BorderFilledBox(FinalX - 2, FinalY - 2, 4, 4, 0, 0, 0, ColorR, ColorG, ColorB, 255);
					Draw.BorderFilledBox(FinalX - 5, FinalY + 4, RadarArray[i].Health * 10 / 100, 4, 0, 0, 0, 0, 255, 0, 255);
				}
				else
				{
					ColorR = 0;
					ColorG = 0;
					ColorB = 255;

					Draw.BorderFilledBox(FinalX - 2, FinalY - 2, 4, 4, 0, 0, 0, ColorR, ColorG, ColorB, 255);
					Draw.BorderFilledBox(FinalX - 4, FinalY + 4, RadarArray[i].Health * 8 / 100, 2, 0, 0, 0, 0, 255, 0, 255);
				}
			}
		}
	}
}