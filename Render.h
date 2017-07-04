#ifndef RENDER_H
#define RENDER_H

#include "Main.h"

#pragma once

struct render_s
{
	float currentTick, oldTick;
	int Frames;
	char Frames_Char[125], waterMark_char[125];

	int Time, Allow, Mode;

	void Init();
	void ChangeMode();
	void Drawings();
	void WaterMark();
};

#endif