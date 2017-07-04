#ifndef MAIN_H
#define MAIN_H

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <dwmapi.h>
#include <time.h>
#include <d3dx9.h>
#include <d3d9.h>
#include <TlHelp32.h>

/* Includes */
#include "Read.h"
#include "DirectX.h"
#include "Drawing.h"
#include "Render.h"
#include "Radar.h"

#pragma once
#pragma comment(lib, "dwmapi.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3d9.lib")

struct window_s
{
	WNDCLASSEX Class;
	char Name[125];
	HWND Window;
	MSG Message;

	void OpenConsole();
};

struct target_s
{
	char Name[125];
	HWND hWindow;
	RECT Rect;
	int Size[2];
	MARGINS Margin;

	void GetTarget(char * name);
}; 

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hInstancePrev, LPSTR lCmd, INT iCmd);
LRESULT CALLBACK WinProcedure(HWND Window, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif