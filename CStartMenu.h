#pragma once
#include "CSprite.h"
#include "IScene.h"

class CImageFile;

class CStartMenu : public IScene {
public:
	CStartMenu();
	~CStartMenu();

	virtual bool isMustChanged() override;
	virtual void onFrameMove() override;
	virtual void onDraw(HDC hdc) override;
	virtual void onMouseMove(UINT x, UINT y) override;
	virtual void onMouseDown(UINT x, UINT y, UCHAR left_right) override;
public:
	CImageFile*		mStartMenuFile;
	CImageFile*		mHighlightBar;

	CSprite			mBG;
	CSprite			mHLB;

	HFONT		mFont;

	int hlBoxX;
	int hlBoxY;
	bool boxActivated;

	int frameCount;
	int firFrameCount;
	int endFrameCount;

	bool endHandler;
};

