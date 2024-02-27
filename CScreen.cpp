#include "pch.h"
#include "CScreen.h"
#include "CApplication.h"

CScreen::CScreen(int width, int height) : CMemoryBitmap()
{
	HDC hdc = GetDC(CApplication::theApp->mhWnd);

	Create(hdc, width, height);
	ReleaseDC(CApplication::theApp->mhWnd, hdc);
}

void CScreen::Draw(HDC hdc)
{
	BitBlt(hdc,
		0, 0,
		getWidth(), getHeight(),
		m_HDC,
		0, 0, SRCCOPY
	);
}

void CScreen::Draw(HDC hdc, int x, int y, int width, int height)
{
	BitBlt(hdc,
		x, y,
		width, height,
		m_HDC,
		0, 0, SRCCOPY
	);
}

void CScreen::DrawS(HDC hdc, int x, int y, int width, int height)
{
	BitBlt(hdc,
		0, 16,
		width, height,
		m_HDC,
		x, y, SRCCOPY
	);
}

void CScreen::DrawDS(HDC hdc, int dx, int dy, int sx, int sy, int width, int height)
{
	BitBlt(hdc,
		dx, dy,
		width, height,
		m_HDC,
		sx, sy, SRCCOPY
	);
}
