#pragma once

class CImageFile
{
private:
	int mRefCount; //자신을 참조하는 객체를 카운트함
	void AddRef() { mRefCount++; }
	int Release() { return mRefCount--; }
public:
	std::wstring mName;

    HBITMAP   mhBitmap;
    BITMAP    mBmpInfo;

    CImageFile(const WCHAR* fileName, const WCHAR* name);
    ~CImageFile();

	static CImageFile* New(const WCHAR* fileName, const WCHAR* name);
	static void Delete(CImageFile* delItem);
	static void DestroyAll();

    void Draw(HDC hdc, 
		int dest_x, int dest_y,
		int src_x, int src_y,
		int width, int height);
    void TransDraw(HDC hdc, 
		int dest_x, int dest_y, 
        int src_x, int src_y,
		int width, int height,
		UINT color);
	void AlphaDraw(HDC hdc,
		int dest_x, int dest_y,
		int src_x, int src_y,
		int width, int height,
		BYTE alpha);
	void FadeInOut(HDC hdc,
		int dest_x, int dest_y,
		int src_x, int src_y,
		int width, int height,
		BYTE alpha);



    int Height() const { return mBmpInfo.bmHeight; }
    int Width() const { return mBmpInfo.bmWidth;  }
};

