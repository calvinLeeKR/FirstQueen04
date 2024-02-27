#pragma once
#include "CSprite.h"
#include "IScene.h"

class CImageFile;

class CIntroSceneKingOrb : public IScene {
public:
	CIntroSceneKingOrb();
	~CIntroSceneKingOrb();

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
