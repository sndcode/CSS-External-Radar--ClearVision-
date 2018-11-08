#include "Main.h"

window_s Window;
target_s Target;
extern directx_s DirectX;
extern read_s Read;
extern render_s Render;

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hInstancePrev, LPSTR lCmd, INT iCmd)
{
	Window.OpenConsole();

	sprintf_s(Window.Name, "Skype");

	Window.Class.cbClsExtra = 0;
	Window.Class.cbSize = sizeof(WNDCLASSEX);
	Window.Class.cbWndExtra = 0;
	Window.Class.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
	Window.Class.hCursor = LoadCursor(0, IDC_ARROW);
	Window.Class.hIcon = LoadIcon(0, IDI_APPLICATION);
	Window.Class.hInstance = hInstance;
	Window.Class.lpfnWndProc = WinProcedure;
	Window.Class.lpszClassName = Window.Name;
	Window.Class.lpszMenuName = Window.Name;
	Window.Class.style = CS_VREDRAW | CS_HREDRAW;

	if (RegisterClassEx(&Window.Class))
	{
		Target.GetTarget("Valve001");

		Window.Window = CreateWindowEx(WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW, Window.Name, Window.Name, WS_POPUP, 1, 1, Target.Size[0], Target.Size[1], 0, 0, 0, 0);

		DirectX.Initialize(Window.Window);
		Read.AccessProcess();
		Render.Init();

		if (!Window.Window)
			exit(1);

		SetLayeredWindowAttributes(Window.Window, RGB(0, 0, 0), 255, LWA_COLORKEY | LWA_ALPHA);
		DwmExtendFrameIntoClientArea(Window.Window, &Target.Margin);
		ShowWindow(Window.Window, SW_SHOW);
		UpdateWindow(Window.Window);

		while (GetMessage(&Window.Message, 0, 0, 0))
		{
			TranslateMessage(&Window.Message);
			DispatchMessage(&Window.Message);
			Target.GetTarget("Valve001");
			Read.ReadMemory();
			Sleep(1);
		}
	}
	else
	{
		MessageBox(0, "Cannot init window class!", "Error!", MB_OK | MB_ICONERROR);
		exit(1);
	}

	return Window.Message.wParam;
}

LRESULT CALLBACK WinProcedure(HWND Window, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_PAINT:
		DirectX.Paint();
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(Window, uMsg, wParam, lParam);
	}

	return 0;
}

void target_s::GetTarget(char * name)
{
	if (hWindow = FindWindow(name, 0))
	{
		GetWindowRect(hWindow, &Rect);
		Size[0] = Rect.right - Rect.left;
		Size[1] = Rect.bottom - Rect.top;

		if (DWORD Flag = GetWindowLong(Target.hWindow, GWL_STYLE) & WS_BORDER)
		{
			Rect.top += 23;
			Target.Size[1] -= 23;
		}

		MoveWindow(Window.Window, Rect.left, Rect.top, Size[0], Size[1], true);
		SetWindowPos(Window.Window, HWND_TOPMOST, Rect.left, Rect.top, Size[0], Size[1], 0);
		Margin = { 0, 0, Size[0], Size[1] };
	}
	else
	{
		exit(1);
	}

} 

void window_s::OpenConsole()
{
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	//printf_s("Console is enabled!\n\n");
	printf_s("CSS RADAR LAUNCHED!\n");
	
}
