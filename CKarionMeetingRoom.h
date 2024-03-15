#pragma once
#include "IScene.h"
#include "CSprite.h"
#include "CMap.h"
#include "CTextBox.h"

class CKarionMeetingRoom : public IScene {

public:
	CKarionMeetingRoom();
	~CKarionMeetingRoom();

	virtual bool isMustChanged() override;
	virtual void onFrameMove() override;
	virtual void onDraw(HDC hdc) override;
	virtual void onMouseDown(UINT x, UINT y, UCHAR left_right);
public:
	CMap* mMap;

	CTextBox* mTxtBox;

	CImageFile* mBG_KarionMeetingRoom;

	CImageFile* mUI_Frame;
	CImageFile* mUI_PlaceTBox;
	CImageFile* mUI_Status;

	CSprite		mUIFrame;
	CSprite		mUIStatus;
	CSprite		mUIText;
	CSprite		mBG;

	HFONT		mFont;

	float scroll;

	int frameCount;

	int textOrder;
	int sceneOrder;

	bool isWaitingClick;
	bool textReady;
	bool textSceneCheck;

	bool isSceneEnded;
};


