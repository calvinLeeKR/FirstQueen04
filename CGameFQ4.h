#pragma once
#include "IGame.h"
//intro
class CIntroScene;
class CIntroSceneDwarf;
class CIntroSceneSoulGirl;
class CIntroSceneKingOrb;
class CIntroSceneKingHall;
class CIntroSceneWitch;
class CIntroSceneCitizen;
class CIntroSceneCastle;
class CIntroSceneBlack;
class CIntroSceneTitle;
class CStartMenu;
//main
class CCastleHall;
class CKarionMeetingRoom;
class CCastleHall_02;

class CGameFQ4 : public IGame {
public:
	~CGameFQ4();

	void onChangeScene() override;
	void onCreate();
	void onDestroy();

	void onKeyDown(UINT virtual_key);
	void onMouseMove(UINT x, UINT y);
	void onMouseDown(UINT x, UINT y, UCHAR left_right);
public:
	bool introCalling;
	bool isKeyPressed;

	CIntroScene*			mIntroS;
	CIntroSceneDwarf*		mIntroDwarf;
	CIntroSceneSoulGirl*	mIntroSoulGirl;
	CIntroSceneKingOrb*		mIntroKingOrb;
	CIntroSceneKingHall*	mIntroKingHall;
	CIntroSceneWitch*		mIntroWitch;
	CIntroSceneCitizen*		mIntroCitizen;
	CIntroSceneCastle*		mIntroCastle;
	CIntroSceneBlack*		mIntroBlack;
	CIntroSceneTitle*		mIntroTitle;
	CStartMenu*				mStartMenu;

	CCastleHall*			mCastleHall;
	CKarionMeetingRoom*		mKarionMeetingRoom;
	CCastleHall_02*			mCastleHall_02;
};

