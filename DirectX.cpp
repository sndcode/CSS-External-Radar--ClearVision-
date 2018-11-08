#include "DirectX.h"

directx_s DirectX;
extern target_s Target;
extern draws_s Draw;
extern render_s Render;

void directx_s::Initialize(HWND hWnd)
{
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &Object)))
		exit(1);

	ZeroMemory(&Param, sizeof(Param));

	Param.BackBufferFormat = D3DFMT_A8R8G8B8;
	Param.BackBufferWidth = Target.Size[0];
	Param.BackBufferHeight = Target.Size[1];


	Param.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	Param.SwapEffect = D3DSWAPEFFECT_DISCARD;
	Param.hDeviceWindow = hWnd;
	Param.Windowed = true;
	Param.EnableAutoDepthStencil = true;
	Param.AutoDepthStencilFormat = D3DFMT_D16;


	if (FAILED(Object->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &Param, 0, &Device)))
		exit(1);

	if (!iFont)
		D3DXCreateFont(Device, 16, 0, 0, 0, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "Tahoma", &iFont);

	if (!iLine)
		D3DXCreateLine(Device, &iLine);

	if (!lSprite)
	{
		/*D3DXCreateTextureFromFile(Device, "c:\\trollface.png", &lTexture);
		D3DXCreateSprite(Device, &lSprite);
		vPos.x = Target.Size[0] - 30.0f;
		vPos.y = 1;*/
	}
}

void directx_s::Paint()
{
	Device->BeginScene();
	Device->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);

	if (GetForegroundWindow() == Target.hWindow)
	{
		Render.Drawings();
	}

	Device->EndScene();
	Device->PresentEx(0, 0, 0, 0, 0);
}