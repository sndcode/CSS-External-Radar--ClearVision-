#ifndef RADAR_H
#define RADAR_H

#include "Main.h"

#pragma once

struct radar_s
{
	
	int ColorR, ColorG, ColorB;

	int Size;

	char radarText[125];

	void Init();
	void Show();
	void Main();
};

#endif