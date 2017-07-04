#ifndef DIRECTX_H
#define DIRECTX_H

#include "Main.h"

#pragma once


struct directx_s
{
	IDirect3D9Ex * Object;
	IDirect3DDevice9Ex * Device;
	D3DPRESENT_PARAMETERS Param;
	ID3DXFont * iFont;
	ID3DXLine * iLine;

	LPDIRECT3DTEXTURE9 lTexture; 
	LPD3DXSPRITE lSprite;
	D3DXVECTOR3 vPos;

	void Initialize(HWND hWnd);
	void Paint();
};

#endif