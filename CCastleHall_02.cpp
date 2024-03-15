#include "pch.h"

#include "CMap.h"

#include "CApplication.h"
#include "CScreen.h"
#include "CCastleHall_02.h"
#include "CImageFile.h"
#include "resource.h"
#include "castlehall_text_02.h"

CCastleHall_02::CCastleHall_02()
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

	for (int i = 0; i < 20; i++) {
		mMap->AddCharacter(chrToAdd_02[i][0], chrToAdd_02[i][1] + 1, chrToAdd_02[i][2], chrToAdd_02[i][3]);
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

CCastleHall_02::~CCastleHall_02()
{
	DeleteObject(mFont);
	CImageFile::Delete(mUI_Frame);
	CImageFile::Delete(mUI_PlaceTBox);
	CImageFile::Delete(mUI_Status);
}

bool CCastleHall_02::isMustChanged()
{
	return isSceneEnded;
}

void CCastleHall_02::onFrameMove()
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
		if (frameCount > 40) {
			textSceneCheck = TRUE;
			mTxtBox = new CTextBox;
			mTxtBox->SetChar(textChr_02[textOrder]);
			isWaitingClick = TRUE;
			textReady = TRUE;
		}
		else if (frameCount == 10) {
			mMap->mCharacters[19]->Walk(0, -1);
		}
		frameCount++;
		break;
	case 4:
		if (frameCount < 30) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[19]->Walk(0, -1);
			}
		}
		else if (frameCount < 50) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[14]->Walk(1, 0);
				mMap->mCharacters[16]->Walk(1, 0);
				mMap->mCharacters[15]->Walk(-1, 0);
				mMap->mCharacters[17]->Walk(-1, 0);
			}
		}
		else if (frameCount < 70) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[16]->Walk(1, 0);
				mMap->mCharacters[17]->Walk(-1, 0);
			}
		}
		else if (frameCount < 200) {
			if (frameCount % 5 == 0) {
				for (int i = 14; i < 20; i++) {
				mMap->mCharacters[i]->mCharSprite.Update(500);
				}
			}
		}
		else if (frameCount < 210) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[19]->ChangeAni(charL);
			}
		}
		else if (frameCount < 220) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[19]->ChangeAni(charF);
			}
		}
		else if (frameCount < 230) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[19]->ChangeAni(charR);
			}
		}
		else if (frameCount < 240) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[19]->ChangeAni(charB);
			}
		}
		else if (frameCount == 240) {
			for (int i = 14; i < 18; i++) {
				mMap->mCharacters[i]->ChangeAni(charA);
			}
		}
		else if (frameCount < 280) {
			if (frameCount % 10 == 0) {
				for (int i = 14; i < 18; i++) {
					mMap->mCharacters[i]->mCharSprite.Update(500);
				}
			}
		}
		else if (frameCount == 280) {
			for (int i = 14; i < 18; i++) {
				mMap->mCharacters[i]->ChangeAni(charD);
			}
		}
		else if (frameCount < 300) {
			if (frameCount % 10 == 0) {
				for (int i = 14; i < 18; i++) {
					mMap->mCharacters[i]->mCharSprite.Update(500);
				}
			}
		}
		else if (frameCount == 300) {
			for (int i = 14; i < 18; i++) {
				mMap->mCharacters.erase(mMap->mCharacters.begin() + 14);
			}
		}
		else if (frameCount < 320) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[15]->Walk(0, -1); //ares : 15
			}
		}
		else if (frameCount == 320) {
			mMap->mCharacters[15]->ChangeAni(charA);
		}
		else {
			isWaitingClick = TRUE;
			break;
		}
		frameCount++;
		break;
	case 6:
		if (frameCount == 0) {
			mMap->mCharacters[14]->ChangeAni(charA);
		}
		else if (frameCount < 20) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[14]->mCharSprite.Update(500);
			}
		}
		else if (frameCount == 30) {
			mMap->CameraMove(0, -320);
		}
		else if (frameCount == 40) {
			mMap->mCharacters[14]->MoveTo(19, 9);
			mMap->mCharacters[14]->ChangeAni(charD);
		}
		else if (frameCount < 60) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[14]->mCharSprite.Update(500);
			}
		}
		else if (frameCount == 60) {
			mMap->mCharacters[14]->ChangeAni(charF);
		}
		else {
			isWaitingClick = TRUE;
			break;
		}
		frameCount++;
		break;
	case 9:
		if (frameCount < 80) {
			mMap->CameraMove(0, 4);
		}
		else if (frameCount < 90) {}
		else if (frameCount <= 90) {
			if (frameCount % 5 == 0) {
				mMap->AddCharacter(ID_GENERAL_01, 21, 25, 0);
				mMap->AddCharacter(ID_STONEGOLEM, 18, 28, 0);
			}
		}
		else if (frameCount <= 95) {
			if (frameCount % 5 == 0) {
				mMap->AddCharacter(ID_STONEGOLEM, 20, 28, 0);
			}
		}
		else if (frameCount <= 100) {
			if (frameCount % 5 == 0) {
				mMap->AddCharacter(ID_STONEGOLEM, 21, 30, 10);
			}
		}
		else if (frameCount <= 105) {
			if (frameCount % 5 == 0) {
				mMap->AddCharacter(ID_STONEGOLEM, 20, 32, 12);
			}
		}
		else if (frameCount <= 110) {
			if (frameCount % 5 == 0) {
				mMap->AddCharacter(ID_STONEGOLEM, 18, 32, 12);
			}
		}
		else if (frameCount <= 115) {
			if (frameCount % 5 == 0) {
				mMap->AddCharacter(ID_STONEGOLEM, 17, 30, 11);
				mMap->mCharacters[15]->ChangeAni(charD);
			}
		}
		else if (frameCount < 220) {
			if (frameCount % 10 == 0) {
				for (int i = 15; i < 23; i++) {
					mMap->mCharacters[i]->mCharSprite.Update(500);
				}
			}
		}
		else if (frameCount == 220) {
			mMap->mCharacters[16]->ChangeAni(charO);
		}
		else if (frameCount < 300) {
			m_minimap.height += 2;
		}
		else {
			isWaitingClick = TRUE;
			break;
		}
		frameCount++;
		break; //scroll
	case 12:
		if (frameCount == 0) mMap->mCharacters[15]->Move(0, 1);
		if (frameCount < 110) {
			if (frameCount % 10 == 0) {
				if (frameCount % 10 == 0) {
					mMap->mCharacters[15]->Move(0, 1);
					for (int i = 16; i < 23; i++) {
						mMap->mCharacters[i]->Walk(0, 1);
					}
					mMap->CameraMove(0, 16);
				}
			}
		}
		else {
			isSceneEnded = TRUE;
			break;
		}
		frameCount++;
		break;
	case 11:
		if (frameCount < 80) {
			if (m_minimap.height > 2) m_minimap.height -= 2;
		}
		frameCount++;
	case 2:		case 3:		case 5:		case 7:		case 8:		case 10:
		if (frameCount > 40) {
			textSceneCheck = TRUE;
			mTxtBox = new CTextBox;
			mTxtBox->SetChar(textChr_02[textOrder]);
			isWaitingClick = TRUE;
			textReady = TRUE;
		}
		else {
			mMap->CharMoves(ChrActs_02[textOrder]);
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

void CCastleHall_02::onDraw(HDC hdc)
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
			mTxtBox->Print(text_02[textOrder], hdc);
		}
		else {
			TextOutW(hdc, 240, 165, text_02[sceneOrder][0], 19);
		}
	}

	mUIStatus.Draw(hdc);
	mUIFrame.Draw(hdc);

	//CScreen renderTarget(CApplication::theApp->hWnd)
}

void CCastleHall_02::onMouseDown(UINT x, UINT y, UCHAR left_right)
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
