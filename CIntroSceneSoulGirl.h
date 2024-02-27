#pragma once
#include "IScene.h"
#include "CSprite.h"

class CImageFile;

class CIntroSceneSoulGirl : public IScene {
public:
	CIntroSceneSoulGirl();
	~CIntroSceneSoulGirl();

	virtual bool isMustChanged() override;
	virtual void onFrameMove() override;
	virtual void onDraw(HDC hdc) override;
public:
	CImageFile* mIntroFile;
	CImageFile* mBlackFile;

	CSprite		mBG;
	CSprite		mFade;

	HFONT		mFont;

	int curX;
	int curY;
	int frameCount;

	int firFrameCount;
	int endFrameCount;
};

