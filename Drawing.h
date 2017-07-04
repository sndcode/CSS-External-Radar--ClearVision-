#ifndef DRAWING_H
#define DRAWING_H



#include "Main.h"

#pragma once
#pragma warning(disable : 4244)

struct draws_s
{
	RECT Position;
	D3DXVECTOR2 Cordinate[2];
	D3DXVECTOR2 BoxCorner[7];
	
	void Text(char * string, float x, float y, int r, int g, int b);
	void ShadowText(char * string, float x, float y, int r, int g, int b, int a);
	int GetCenterPos(char * string);
	void Line(float x, float y, float x2, float y2, int r, int g, int b, int a);
	void Box(float x, float y, float width, float height, int r, int g, int b, int a);
	void GradientBox(float x, float y, float width, float height, int r, int g, int b, int r1, int g1, int b1, int a);
	void FilledBox(float x, float y, float width, float height, int r, int g, int b, int a);
	void BorderFilledBox(float x, float y, float width, float height, int r, int g, int b, int r1, int g1, int b1, int a);
	void ShadowBox(float x, float y, float width, float height, int r, int g, int b);
};

#endif 