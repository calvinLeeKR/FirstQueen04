#pragma once

struct ARGB {
	BYTE b, g, r, a;
};

union ARGBColor {
	UINT32	c;
	ARGB	argb;
}; //union : 내부 변수 어떤 형태로든 된다. typecasting

/*UINT getRed(UINT32 color) {
	UINT a = (color & 0xFF000000) >> 24;
	UINT r = (color & 0x00FF0000) >> 16;
	UINT g = (color & 0x0000FF00) >> 8;
	UINT b = (color & 0x000000FF);

	ARGBColor cc;
	cc.c = color;

	return a;
}*/

class CMemoryBitmap
{
	HBITMAP m_Old;

public:
	HBITMAP m_hBitmap;
	HDC     m_HDC;


	UINT32* m_Colors;
	BITMAPINFO m_BMI;        // bitmap header

public:
	CMemoryBitmap() {};
	CMemoryBitmap(HDC hdcWnd, int width, int height);
    void Create(HDC hdcWnd, int width, int height);
	~CMemoryBitmap();

	UINT32 getColor(int x, int y)			{ return m_Colors[y * m_BMI.bmiHeader.biWidth + x]; }
	void setColor(int x, int y, UINT32 c)	{ m_Colors[y * m_BMI.bmiHeader.biWidth + x] = c; }

	int getWidth()							{ return m_BMI.bmiHeader.biWidth; }
	int getHeight()							{ return m_BMI.bmiHeader.biHeight; }

	void Clear(UINT32 color = 0xFF000000);
};

