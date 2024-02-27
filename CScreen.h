#pragma once
#include "CMemoryBitmap.h"

class CScreen
	: public CMemoryBitmap
{
public:
	CScreen(HDC hdcWnd, int width, int height)
		: CMemoryBitmap(hdcWnd, width, height) {}
	CScreen(int width, int height);
	void Draw(HDC hdc);
	void Draw(HDC hdc, int x, int y, int width, int height);
	void DrawS(HDC hdc, int x, int y, int width, int height);
	void DrawDS(HDC hdc, int dx, int dy, int sx, int sy, int width, int height);
};

