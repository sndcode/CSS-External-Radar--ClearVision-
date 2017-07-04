#include "Drawing.h"

draws_s Draw;
extern directx_s DirectX;

void draws_s::Text(char * string, float x, float y, int r, int g, int b)
{
	Position.left = x;
	Position.top = y;
	DirectX.iFont->DrawTextA(0, string, strlen(string), &Position, DT_NOCLIP, D3DCOLOR_ARGB(255, r, g, b));
}

void draws_s::ShadowText(char * string, float x, float y, int r, int g, int b, int a)
{
	Position.left = x + 1;
	Position.top = y + 1;
	DirectX.iFont->DrawTextA(0, string, strlen(string), &Position, DT_NOCLIP, D3DCOLOR_ARGB(a, r / 30, g / 30, b / 30));

	Position.left = x; 
	Position.top = y;
	DirectX.iFont->DrawTextA(0, string, strlen(string), &Position, DT_NOCLIP, D3DCOLOR_ARGB(a, r, g, b));
}

int draws_s::GetCenterPos(char * string)
{
	RECT Center = { 0, 0, 0, 0 };
	DirectX.iFont->DrawTextA(0, string, -1, &Center, DT_CALCRECT, 0);
	return Center.right;
}

void draws_s::Line(float x, float y, float x2, float y2, int r, int g, int b, int a)
{
	Cordinate[0] = D3DXVECTOR2(x, y);
	Cordinate[1] = D3DXVECTOR2(x2, y2);

	DirectX.iLine->SetWidth(1);
	DirectX.iLine->SetAntialias(false);

	DirectX.iLine->Draw(Cordinate, 2, D3DCOLOR_ARGB(a, r, g, b));
}

void draws_s::Box(float x, float y, float width, float height, int r, int g, int b, int a)
{
	BoxCorner[0] = D3DXVECTOR2(x, y);
	BoxCorner[1] = D3DXVECTOR2(x + width, y);
	BoxCorner[2] = D3DXVECTOR2(x + width, y + height);
	BoxCorner[3] = D3DXVECTOR2(x, y + height);
	BoxCorner[4] = D3DXVECTOR2(x, y);

	DirectX.iLine->SetAntialias(false);
	DirectX.iLine->SetWidth(1);

	DirectX.iLine->Draw(BoxCorner, 5, D3DCOLOR_ARGB(a, r, g, b));
}

void draws_s::GradientBox(float x, float y, float width, float height, int r, int g, int b, int r1, int g1, int b1, int a)
{
	int ColorR, ColorG, ColorB;
	for (int i = 1; i < height; i++)
	{
		ColorR = (i / height * r);
		ColorG = (i / height * g);
		ColorB = (i / height * b);
		Box(x, y + i, width, 1, r - ColorR, g - ColorG, b - ColorB, a);
	}

	BoxCorner[0] = D3DXVECTOR2(x, y);
	BoxCorner[1] = D3DXVECTOR2(x + width, y);
	BoxCorner[2] = D3DXVECTOR2(x + width, y + height);
	BoxCorner[3] = D3DXVECTOR2(x, y + height);
	BoxCorner[4] = D3DXVECTOR2(x, y);

	DirectX.iLine->SetAntialias(false);
	DirectX.iLine->SetWidth(1);
	DirectX.iLine->Draw(BoxCorner, 5, D3DCOLOR_ARGB(a, r1, g1, b1));
}

void draws_s::FilledBox(float x, float y, float width, float height, int r, int g, int b, int a)
{
	BoxCorner[0] = D3DXVECTOR2(x + width / 2, y);
	BoxCorner[1] = D3DXVECTOR2(x + width / 2, y + height);

	DirectX.iLine->SetAntialias(false);
	DirectX.iLine->SetWidth(width);
	DirectX.iLine->Draw(BoxCorner, 2, D3DCOLOR_ARGB(a, r, g, b));

	BoxCorner[0] = D3DXVECTOR2(x, y);
	BoxCorner[1] = D3DXVECTOR2(x + width, y);
	BoxCorner[2] = D3DXVECTOR2(x + width, y + height);
	BoxCorner[3] = D3DXVECTOR2(x, y + height);
	BoxCorner[4] = D3DXVECTOR2(x, y);

	DirectX.iLine->SetAntialias(false);
	DirectX.iLine->SetWidth(1);
	DirectX.iLine->Draw(BoxCorner, 5, D3DCOLOR_ARGB(a, r, g, b));
}

void draws_s::BorderFilledBox(float x, float y, float width, float height, int r, int g, int b, int r1, int g1, int b1, int a)
{
	BoxCorner[0] = D3DXVECTOR2(x + width / 2, y);
	BoxCorner[1] = D3DXVECTOR2(x + width / 2, y + height);

	DirectX.iLine->SetAntialias(false);
	DirectX.iLine->SetWidth(width);
	DirectX.iLine->Draw(BoxCorner, 2, D3DCOLOR_ARGB(a, r1, g1, b1));

	BoxCorner[0] = D3DXVECTOR2(x, y);
	BoxCorner[1] = D3DXVECTOR2(x + width, y);
	BoxCorner[2] = D3DXVECTOR2(x + width, y + height);
	BoxCorner[3] = D3DXVECTOR2(x, y + height);
	BoxCorner[4] = D3DXVECTOR2(x, y);

	DirectX.iLine->SetAntialias(false);
	DirectX.iLine->SetWidth(1);
	DirectX.iLine->Draw(BoxCorner, 5, D3DCOLOR_ARGB(a, r, g, b));
}

void draws_s::ShadowBox(float x, float y, float width, float height, int r, int g, int b)
{
	BoxCorner[0] = D3DXVECTOR2(x - 1, y - 1);
	BoxCorner[1] = D3DXVECTOR2(x + width + 1, y - 1);
	BoxCorner[2] = D3DXVECTOR2(x + width + 1, y + height + 1);
	BoxCorner[3] = D3DXVECTOR2(x - 1, y + height + 1);
	BoxCorner[4] = D3DXVECTOR2(x - 1, y - 1);

	DirectX.iLine->SetAntialias(false);
	DirectX.iLine->SetWidth(1);

	DirectX.iLine->Draw(BoxCorner, 5, D3DCOLOR_ARGB(255, 0, 0, 0));

	BoxCorner[0] = D3DXVECTOR2(x + 1, y + 1);
	BoxCorner[1] = D3DXVECTOR2(x + width - 1, y + 1);
	BoxCorner[2] = D3DXVECTOR2(x + width - 1, y + height - 1);
	BoxCorner[3] = D3DXVECTOR2(x + 1, y + height - 1);
	BoxCorner[4] = D3DXVECTOR2(x + 1, y + 1);

	DirectX.iLine->SetAntialias(false);
	DirectX.iLine->SetWidth(1);

	DirectX.iLine->Draw(BoxCorner, 5, D3DCOLOR_ARGB(255, 0, 0, 0));

	BoxCorner[0] = D3DXVECTOR2(x, y);
	BoxCorner[1] = D3DXVECTOR2(x + width, y);
	BoxCorner[2] = D3DXVECTOR2(x + width, y + height);
	BoxCorner[3] = D3DXVECTOR2(x, y + height);
	BoxCorner[4] = D3DXVECTOR2(x, y);

	DirectX.iLine->SetAntialias(false);
	DirectX.iLine->SetWidth(1);

	DirectX.iLine->Draw(BoxCorner, 5, D3DCOLOR_ARGB(255, r, g, b));
}
