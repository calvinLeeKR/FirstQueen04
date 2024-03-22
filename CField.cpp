#include "pch.h"

#include "CMap.h"
#include "CApplication.h"
#include "CScreen.h"
#include "CField.h"
#include "CImageFile.h"
#include "resource.h"
#include "field_text.h"

CField::CField()
{
	scroll = 0;

	mMap = new CMap();

	m_minimap.width = 863;
	m_minimap.height = 0;
	m_minimap.x = 0;
	m_minimap.y = 0;
	m_minimap.origin_x = 0;
	m_minimap.origin_y = 50;
	//minimap initialize

	mBG_CastleHall = CImageFile::New(MAKEINTRESOURCE(CBG_CASTLEHALL), L"CBG_CASTLEHALL");

	mUI_MapFrame = CImageFile::New(MAKEINTRESOURCE(UI_MAPFRAME_MINI), L"UI_MAPFRAME_MINI");
	mUI_Frame = CImageFile::New(MAKEINTRESOURCE(UI_FRAME), L"UI_FRAME");
	mUI_PlaceTBox = CImageFile::New(MAKEINTRESOURCE(UI_PLACEBOX), L"UI_PLACEBOX");
	mUI_Status = CImageFile::New(MAKEINTRESOURCE(UI_STATUS), L"UI_STATUS");


	mUIFrame.Set(0, 0, 0, 0, mUI_Frame, 0, CSprite::DrawType_Transparent);
	mUIFrame.mTransColor = RGB(255, 0, 255);
	mUIStatus.Set(0, 400, 0, 0, mUI_Status, 0, CSprite::DrawType_Draw);
	mUIText.Set(200 - 64, 150, 0, 0, mUI_PlaceTBox, 0, CSprite::DrawType_AlphaBlend);
	mUIText.mAlpha = 0x00;
	mUIMapFrame.Set(192 - 16, -150, 0, 0, mUI_MapFrame, RGB(255, 0, 255), CSprite::DrawType_Transparent);
	//ui initialize

	//map initialize

	for (int i = 0; i < 20; i++) {
		mMap->AddCharacter(chrToAdd_03[i][0], chrToAdd_03[i][1] + 1, chrToAdd_03[i][2], chrToAdd_03[i][3]);
	}
	//character add

	frameCount = 0;
	sceneOrder = 0;
	textOrder = 1;

	isWaitingClick = FALSE;
	textReady = FALSE;
	textSceneCheck = FALSE;
	//variable initialize
	mFont = CreateFontW(20, 0, 0, 0, FW_EXTRABOLD, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("µ¸¿ò"));
}

CField::~CField()
{
	DeleteObject(mFont);
	CImageFile::Delete(mUI_Frame);
	CImageFile::Delete(mUI_PlaceTBox);
	CImageFile::Delete(mUI_Status);
}

bool CField::isMustChanged()
{
	return isSceneEnded;
}

void CField::onFrameMove()
{
	std::wstring charF = L"char_F";
	std::wstring charB = L"char_B";
	std::wstring charR = L"char_R";
	std::wstring charL = L"char_L";
	std::wstring charA = L"char_A";
	std::wstring charD = L"char_D";
	std::wstring charO = L"char_O";

	switch (sceneOrder) {
	case 0:
		if (frameCount < 80) {
			mMap->CameraMove(0, 4);
			frameCount++;
		}
		else {
			isWaitingClick = TRUE;
			break;
		}
		break; //scroll
	case 1:
		if (frameCount < 10) {
			if (frameCount % 10 == 0) {
				mMap->UpdateMap();
				mMap->mCharacters[19]->pathFind(5, 30, mMap);
			}
		}
		else if (frameCount < 500) {
			if (frameCount % 5 == 0) {
				if(mMap->mCharacters[19]->isMoving)
					mMap->mCharacters[19]->trackingPath();
			}
		}
		else {
			isWaitingClick = TRUE;
			break;
		}
		frameCount++;
		break;
	case 2:		case 3:		case 5:		case 7:		case 8:		case 10:
		if (frameCount > 40) {
			textSceneCheck = TRUE;
			mTxtBox = new CTextBox;
			mTxtBox->SetChar(textChr_03[textOrder]);
			isWaitingClick = TRUE;
			textReady = TRUE;
		}
		else {
			mMap->CharMoves(ChrActs_03[textOrder]);
			frameCount++;
			break;
		}
		break; //text Ãâ·Â
	case 20:
		isSceneEnded = TRUE;
		break;
	}

	mMap->OnFrameMove();
}

void CField::onDraw(HDC hdc)
{
	CScreen screen(610 + 16, 863);
	//HDC hdc = screen.m_HDC;

	mMap->Draw2(screen.m_HDC);

	screen.DrawS(hdc, mMap->cameraX, mMap->cameraY, CApplication::theApp->w_width, CApplication::theApp->w_height);

	mUIText.Draw(hdc);

	screen.DrawDS(hdc, m_minimap.x, m_minimap.y,
		m_minimap.origin_x, m_minimap.origin_y, m_minimap.width, m_minimap.height);
	//mUIMapFrame.Draw(hdc);

	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(0, 0, 0));
	HFONT oldFont;
	oldFont = (HFONT)SelectObject(hdc, mFont); //text option

	if (textReady) {
		if (mTxtBox) {
			mFont = mTxtBox->mFont;
			mTxtBox->Print(text_03[textOrder], hdc);
		}
		else {
			TextOutW(hdc, 240, 165, text_03[sceneOrder][0], 19);
		}
	}

	mUIStatus.Draw(hdc);
	mUIFrame.Draw(hdc);
}

void CField::onMouseDown(UINT x, UINT y, UCHAR left_right)
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
