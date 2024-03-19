#include "pch.h"
//intro
#include "CIntroScene.h"
#include "CIntroSceneDwarf.h"
#include "CIntroSceneSoulGirl.h"
#include "CIntroSceneKingOrb.h"
#include "CIntroSceneKingHall.h"
#include "CIntroSceneWitch.h"
#include "CIntroSceneCitizen.h"
#include "CIntroSceneCastle.h"
#include "CIntroSceneBlack.h"
#include "CIntroSceneTitle.h"
#include "CStartMenu.h"
//main
#include "CCastleHall.h"
#include "CKarionMeetingRoom.h"
#include "CCastleHall_02.h"
#include "CField.h"

#include "CGameFQ4.h"




CGameFQ4::~CGameFQ4()
{
	CImageFile::DestroyAll();
}

void CGameFQ4::onChangeScene()
{
	if (mCurrent->isMustChanged()) {
		if (mCurrent == mIntroS) {
			mIntroDwarf = new CIntroSceneDwarf;
			mCurrent = mIntroDwarf;
		}
		else if (mCurrent == mIntroDwarf) {
			mIntroSoulGirl = new CIntroSceneSoulGirl;
			mCurrent = mIntroSoulGirl;
		}
		else if (mCurrent == mIntroSoulGirl) {
			mIntroKingOrb = new CIntroSceneKingOrb;
			mCurrent = mIntroKingOrb;
		}
		else if (mCurrent == mIntroKingOrb) {
			mIntroKingHall = new CIntroSceneKingHall;
			mCurrent = mIntroKingHall;
		}
		else if (mCurrent == mIntroKingHall) {
			mIntroWitch = new CIntroSceneWitch;
			mCurrent = mIntroWitch;
		}
		else if (mCurrent == mIntroWitch) {
			mIntroCitizen = new CIntroSceneCitizen;
			mCurrent = mIntroCitizen;
		}
		else if (mCurrent == mIntroCitizen) {
			mIntroCastle = new CIntroSceneCastle;
			mCurrent = mIntroCastle;
		}
		else if (mCurrent == mIntroCastle) {
			mIntroBlack = new CIntroSceneBlack;
			mCurrent = mIntroBlack;
		}
		else if (mCurrent == mIntroBlack) {
			mIntroTitle = new CIntroSceneTitle;
			mCurrent = mIntroTitle;
		}
		else if (mCurrent == mIntroTitle) {
			mStartMenu = new CStartMenu;
			mCurrent = mStartMenu;
		}
		else if (mCurrent == mCastleHall) {
			mKarionMeetingRoom = new CKarionMeetingRoom;
			mCurrent = mKarionMeetingRoom;
		}
		else if (mCurrent == mKarionMeetingRoom) {
			mCastleHall_02 = new CCastleHall_02;
			mCurrent = mCastleHall_02;
		}
	}

	if (introCalling && isKeyPressed) {
		mIntroTitle = new CIntroSceneTitle;
		mCurrent = mIntroTitle;

		introCalling = FALSE;
		isKeyPressed = FALSE;
	}

	if (mCurrent == mStartMenu && mCurrent->isMustChanged()) {
		mCastleHall = new CCastleHall;
		mCurrent = mCastleHall;
	}
}

void CGameFQ4::onCreate()
{
	mField = new CField;
	mCurrent = mField;

	//mIntroS = new CIntroScene;
	//mCurrent = mIntroS;

	introCalling = TRUE;
	isKeyPressed = FALSE;
}

void CGameFQ4::onDestroy()
{
	delete mCurrent;
}

void CGameFQ4::onKeyDown(UINT virtual_key)
{
	isKeyPressed = TRUE;
}

void CGameFQ4::onMouseMove(UINT x, UINT y)
{
	if(mCurrent) mCurrent->onMouseMove(x, y);
}

void CGameFQ4::onMouseDown(UINT x, UINT y, UCHAR left_right)
{
	if (mCurrent) mCurrent->onMouseDown(x, y, left_right);
}


