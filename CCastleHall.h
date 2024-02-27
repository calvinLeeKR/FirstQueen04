#pragma once
#include "IScene.h"
#include "CSprite.h"
#include "CMap.h"
#include "CTextBox.h"

class CCastleHall : public IScene {

public:
	CCastleHall();
	~CCastleHall();

	virtual bool isMustChanged() override;
	virtual void onFrameMove() override;
	virtual void onDraw(HDC hdc) override;
	virtual void onMouseDown(UINT x, UINT y, UCHAR left_right);
public:
	MINIMAP m_minimap;

	CMap* mMap;
	//CMap* mMapSmall;

	CTextBox* mTxtBox;

	CImageFile* mBG_CastleHall;
	CImageFile* mBG_CastleHallMini;

	CImageFile* mUI_Frame;
	CImageFile* mUI_PlaceTBox;
	CImageFile* mUI_Status;
	CImageFile* mUI_MapFrame;

	CSprite		mUIFrame;
	CSprite		mUIStatus;
	CSprite		mUIText;
	CSprite		mBG;
	CSprite		mUIMapFrame;

	HFONT		mFont;

	float scroll;

	int frameCount;

	int textOrder;
	int sceneOrder;

	bool isWaitingClick;
	bool textReady;
	bool textSceneCheck;
};

