#include "pch.h"
#include "CImageFile.h"
#include "CApplication.h"

#pragma comment(lib, "Msimg32.lib")

static std::vector< CImageFile*> g_ImgFileArray;

CImageFile* CImageFile::New(const WCHAR* fileName, const WCHAR* name)
{
	std::wstring n = name;
	for (CImageFile* it : g_ImgFileArray) {
		if (it->mName == n) {
			it->AddRef();
			return it;
		}
	}

	CImageFile* it = new CImageFile(fileName, name);

	bool success = false;
	for (CImageFile* i : g_ImgFileArray) {
		if (i == nullptr) {
			i = it;
			success = true;
			break;
		}
	}
	if (!success) g_ImgFileArray.push_back(it);

	it->AddRef();

	return it;
}

void CImageFile::Delete(CImageFile* delItem)
{
	delItem->Release();
	
	if (delItem->mRefCount <= 0) {
		for (auto& i : g_ImgFileArray) {
			if (i == delItem) {
				i = nullptr;
			}
		}
		delete delItem;
	}
}

void CImageFile::DestroyAll()
{
	for (CImageFile* it : g_ImgFileArray) {
		if(it) delete it;
	}
}

CImageFile::CImageFile(const WCHAR* fileName, const WCHAR* name)
{
	mRefCount = 0;

	mName = name;
    mhBitmap = LoadBitmapW(CApplication::theApp->mhInst, fileName);
    GetObject(mhBitmap, sizeof(BITMAP), &mBmpInfo);
}

CImageFile::~CImageFile()
{
    DeleteObject(mhBitmap);
}

void CImageFile::Draw(HDC hdc, 
                      int dest_x, int dest_y, 
                      int src_x, int src_y, 
                      int width, int height)
{
    HDC hBmpDC = CreateCompatibleDC(hdc);
    HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);
    BitBlt(hdc,
        dest_x, dest_y,
        width, height,
        hBmpDC,
        src_x, src_y, SRCCOPY);


    SelectObject(hBmpDC, old);
    DeleteDC(hBmpDC);
}

void CImageFile::TransDraw(HDC hdc, int dest_x, int dest_y, int src_x, int src_y, int width, int height, UINT color)
{
    HDC hBmpDC = CreateCompatibleDC(hdc);
    HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);
    TransparentBlt(hdc,
        dest_x, dest_y, width, height,
        hBmpDC,
        src_x, src_y, width, height,
        color);


    SelectObject(hBmpDC, old);
    DeleteDC(hBmpDC);
}

void CImageFile::FadeInOut(HDC hdcWnd, int dest_x, int dest_y, int src_x, int src_y, int width, int height, BYTE alpha)
{
	BLENDFUNCTION bf;


	BITMAPINFO bmi;        // bitmap header
	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = height;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;         // four 8-bit components 
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = width * height * 4;

	VOID* pvBits;          // pointer to DIB section 
	HDC hdc = CreateCompatibleDC(hdcWnd);
	HBITMAP hbitmapDIB = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
	SelectObject(hdc, hbitmapDIB);

	UINT32 rgba = alpha;
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			((UINT32*)pvBits)[y * width + x] = 0xFF000000;


	{
		HDC hBmpDC = CreateCompatibleDC(hdcWnd);
		HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);

		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.SourceConstantAlpha = alpha;
		bf.AlphaFormat = 0;
		AlphaBlend(hdc, 0, 0, width, height,
			hBmpDC, src_x, src_y, width, height,
			bf);


		SelectObject(hBmpDC, old);
		DeleteDC(hBmpDC);
	}


	//bf.SourceConstantAlpha = 0xff;
	//bf.AlphaFormat = AC_SRC_ALPHA;

	//AlphaBlend(hdcWnd,
	//	dest_x, dest_y, width, height,
	//	hdc, 
	//	0, 0, width, height,
	//	bf);
	BitBlt(hdcWnd, dest_x, dest_y, width, height,
		hdc, 0, 0, SRCCOPY);


	DeleteObject(hbitmapDIB);
	DeleteDC(hdc);

}


void CImageFile::AlphaDraw(HDC hdcWnd, int dest_x, int dest_y, int src_x, int src_y, int width, int height, BYTE alpha)
{
	HDC hBmpDC = CreateCompatibleDC(hdcWnd);
	HBITMAP old = (HBITMAP)SelectObject(hBmpDC, mhBitmap);

	BLENDFUNCTION bf;
	bf.BlendOp = 0;
	bf.BlendFlags = 0;
	bf.SourceConstantAlpha = alpha;
	bf.AlphaFormat = AC_SRC_OVER;
	GdiAlphaBlend(hdcWnd, dest_x, dest_y, width, height,
		hBmpDC, src_x, src_y, width, height,
		bf);

	SelectObject(hBmpDC, old);
	DeleteDC(hBmpDC);
}
