#ifndef READ_H
#define READ_H

#include "Main.h"

#pragma once

class Vec3
{
public:
	float x, y, z;
	Vec3(){}

	Vec3(float x, float y, float z)
	{
		this->x;
		this->y;
		this->z;
	}
};

class Vec2
{
public:
	float x, y;
	Vec2(){}

	Vec2(float x, float y)
	{
		this->x;
		this->y;
	}
};

struct read_s
{
	HANDLE Handle;
	DWORD ProcessID;

	DWORD Client;
	DWORD Server;
	DWORD Engine;

	DWORD ClientRef;
	DWORD RadarRef;
	DWORD EntityRef;

	int ClientNum;
	int Bomb;

	void AccessProcess();
	void GetMemory(LPVOID offset, LPVOID buffer, DWORD size);
	DWORD GetModule(char * module);
	void GetBasePlayer();
	void GetRadarBase(int i);
	void ReadMemory();
};


struct CBasePlayer_s
{
	char _0x0000[148];
	__int32 Health; //0x0094 
	char _0x0098[4];
	__int32 Team; //0x009C 
	char _0x00A0[448];
	Vec3 Origin; //0x0260 
	char _0x026C[96];
	Vec2 Viewaxis; //0x02CC 
	char _0x02D4[124];
	__int32 Flags; //0x0350 
	char _0x0354[3848];
	char ZoneName[16]; //0x125C 
	char _0x126C[644];
	__int32 CrossID; //0x14F0 
};//Size=0x14D8

struct RadarArray_s
{
	char _0x0000[40];
	__int32 clientNum; //0x0028 
	char _0x002C[12];
	char Name[32]; //0x0038 
	__int32 Team; //0x0058 
	__int32 Health; //0x005C 
	Vec3 Origin; //0x0060 
	Vec2 Viewangles; //0x006C 
	char _0x0074[4];
	Vec2 oldOrigin_0; //0x0078 
	Vec2 oldOrigin_1; //0x0080 
	Vec2 oldOrigin_2; //0x0088 
	Vec2 oldOrigin_3; //0x0090 
	char _0x0098[208];

};//Size=0x0168

#endif