#include "pch.h"

#include "CMap.h"

#include "CApplication.h"
#include "CScreen.h"
#include "CCastleHall.h"
#include "CImageFile.h"
#include "resource.h"
#include "castlehall_text.h"

CCastleHall::CCastleHall()
{
	scroll = 0;

	mMap = new CMap();


	m_minimap.width = 288 - 32;
	m_minimap.height = 0;
	m_minimap.x = 192;
	m_minimap.y = 16;
	m_minimap.origin_x = 192;
	m_minimap.origin_y = 336;
	//minimap initialize

	mBG_CastleHall		= CImageFile::New(MAKEINTRESOURCE(CBG_CASTLEHALL), L"CBG_CASTLEHALL");
	
	mUI_MapFrame	= CImageFile::New(MAKEINTRESOURCE(UI_MAPFRAME_MINI), L"UI_MAPFRAME_MINI");
	mUI_Frame		= CImageFile::New(MAKEINTRESOURCE(UI_FRAME), L"UI_FRAME");
	mUI_PlaceTBox	= CImageFile::New(MAKEINTRESOURCE(UI_PLACEBOX), L"UI_PLACEBOX");
	mUI_Status		= CImageFile::New(MAKEINTRESOURCE(UI_STATUS), L"UI_STATUS");

	
	mUIFrame.Set(0, 0, 0, 0, mUI_Frame, 0, CSprite::DrawType_Transparent);
	mUIFrame.mTransColor = RGB(255, 0, 255);
	mUIStatus.Set(0, 400, 0, 0, mUI_Status, 0, CSprite::DrawType_Draw);
	mUIText.Set(200 - 64, 150, 0, 0, mUI_PlaceTBox, 0, CSprite::DrawType_AlphaBlend);
	mUIText.mAlpha = 0x00;
	mUIMapFrame.Set(192 - 16, -150, 0, 0, mUI_MapFrame, RGB(255, 0, 255), CSprite::DrawType_Transparent);
	//ui initialize

	//map initialize

	for (int i = 0; i < 27; i++) {
		mMap->AddCharacter(chrToAdd[i][0], chrToAdd[i][1] + 1, chrToAdd[i][2], chrToAdd[i][3]);
	}
	//character add

	frameCount = 0;
	sceneOrder = 0;
	textOrder = 1;

	isWaitingClick = FALSE;
	textReady = FALSE;
	textSceneCheck = FALSE;
	//variable initialize
	mFont = CreateFontW(20, 0, 0, 0, FW_EXTRABOLD, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("돋움"));
}

CCastleHall::~CCastleHall()
{
	DeleteObject(mFont);
	CImageFile::Delete(mUI_Frame);
	CImageFile::Delete(mUI_PlaceTBox);
	CImageFile::Delete(mUI_Status);
}

bool CCastleHall::isMustChanged()
{
	return false;
}

void CCastleHall::onFrameMove()
{
	switch (sceneOrder) {
	case 0:
		if (frameCount > 20) {
			mUIText.Set(200 - 64, 150, 0, 0, mUI_PlaceTBox, 0, CSprite::DrawType_AlphaBlend);
			mUIText.mAlpha = 0xFF;
			isWaitingClick = TRUE;
			textReady = TRUE;
		} //장소 출력
		else {
			frameCount++;
			break;
		}
		break;
	case 1:
		if (frameCount < 124) {
			mMap->CameraMove(0, 4);
			frameCount++;
		}
		else if (frameCount < 124 + 192/2) {
			mUIMapFrame.mDestY += 2;
			m_minimap.height += 2;
			//mMapSmall->CameraMove(0, -1);
			frameCount++;
		}
		else {
			isWaitingClick = TRUE;
			break;
		}
		break; //scroll
	case 2:	
	case 3:		case 4:		case 5:		case 6:		case 7:		case 8:		case 9:
	case 10:	case 11:	case 12:	case 13:	case 14:	case 15:	case 16:	case 17:
	case 18:	case 19:
		if (frameCount > 40) {
			textSceneCheck = TRUE;
			mTxtBox = new CTextBox;
			mTxtBox->SetChar(textChr[textOrder]);
			isWaitingClick = TRUE;
			textReady = TRUE;
		}
		else {
			mMap->CharMoves(ChrActs[textOrder]);
			frameCount++;
			break;
		}
		break; //text 출력
	}

	mMap->OnFrameMove();
}

void CCastleHall::onDraw(HDC hdc)
{
	CScreen screen(610 + 16, 863);
	//HDC hdc = screen.m_HDC;

	mMap->Draw2(screen.m_HDC);

	screen.DrawS(hdc, mMap->cameraX, mMap->cameraY, CApplication::theApp->w_width, CApplication::theApp->w_height);

	mUIText.Draw(hdc);

	screen.DrawDS(hdc, m_minimap.x, m_minimap.y,
		m_minimap.origin_x, m_minimap.origin_y, m_minimap.width, m_minimap.height);
	mUIMapFrame.Draw(hdc);

	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(0, 0, 0));
	HFONT oldFont;
	oldFont = (HFONT)SelectObject(hdc, mFont); //text option

	if (textReady) {
		if (mTxtBox) {
			mFont = mTxtBox->mFont;
			mTxtBox->Print(text[textOrder][0], text[textOrder][1], text[textOrder][2], hdc);
		}
		else {
			TextOutW(hdc, 240, 165, text[sceneOrder][0], 19);
		}
	}

	mUIStatus.Draw(hdc);
	mUIFrame.Draw(hdc);

	//CScreen renderTarget(CApplication::theApp->hWnd)
}

void CCastleHall::onMouseDown(UINT x, UINT y, UCHAR left_right)
{
	if (isWaitingClick) {
		sceneOrder++;
		frameCount = 0;
		textReady = FALSE;
		isWaitingClick = FALSE;
		mUIText.mAlpha = 0x00;

		if (textSceneCheck) {
			delete mTxtBox;
			textOrder++;
			textSceneCheck = FALSE;
		}
	}
}
