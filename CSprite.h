#pragma once

class CImageFile;

class CSprite
{
public:
    int mDestX;
    int mDestY;
    int mDestWidth;
    int mDestHeight;

    int mSrcX;
    int mSrcY;
    int mSrcWidth;
    int mSrcHeight;

	int mAlpha;

    UINT  mTransColor;

public:
    enum TDrawType  {
        DrawType_Transparent, 
        DrawType_Draw,
		DrawType_AlphaBlend,
		DrawType_FadeInOut
    };
    TDrawType mDrawType;

    CImageFile* mImgFile;

    void Set(int dx, int dy, 
             int sx, int sy, 
		CImageFile* img, UINT color, TDrawType dt);
    void Draw(HDC hdc);
};

