#pragma once
#include "CSprite.h"
#include "IScene.h"
#include "CAnimation.h"

class CImageFile;

class CIntroScene : public IScene {
public:
	CIntroScene();
	~CIntroScene();

	virtual bool isMustChanged() override;
	virtual void onFrameMove() override;
	virtual void onDraw(HDC hdc) override;
public:
	CImageFile* mIntroFile;
	CImageFile* mBlackFile;

	CSprite		mBG;
	CSprite		mFade;

	HFONT		mFont;

	int testTime;

	int curX;
	int curY;
	int frameCount;

	int firFrameCount;
	int endFrameCount;
};

