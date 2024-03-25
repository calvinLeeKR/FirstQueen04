#include "pch.h"

#include "CMap.h"

#include "CApplication.h"
#include "CScreen.h"
#include "CKarionMeetingRoom.h"
#include "CImageFile.h"
#include "resource.h"
#include "karionmeetingroom_text.h"

std::wstring charF = L"char_F";
std::wstring charB = L"char_B";
std::wstring charR = L"char_R";
std::wstring charL = L"char_L";
std::wstring charA = L"char_A";
std::wstring charD = L"char_D";

CKarionMeetingRoom::CKarionMeetingRoom()
{
	scroll = 0;

	mMap = new CMap();

	mBG_KarionMeetingRoom = CImageFile::New(MAKEINTRESOURCE(CBG_KARIONMEETINGROOM), L"CBG_KARIONMEETINGROOM");
	mMap->ChangeBGImage(mBG_KarionMeetingRoom);

	mUI_Frame = CImageFile::New(MAKEINTRESOURCE(UI_FRAME), L"UI_FRAME");
	mUI_PlaceTBox = CImageFile::New(MAKEINTRESOURCE(UI_PLACEBOX), L"UI_PLACEBOX");
	mUI_Status = CImageFile::New(MAKEINTRESOURCE(UI_STATUS), L"UI_STATUS");


	mUIFrame.Set(0, 0, 0, 0, mUI_Frame, 0, CSprite::DrawType_Transparent);
	mUIFrame.mTransColor = RGB(255, 0, 255);
	mUIStatus.Set(0, 400, 0, 0, mUI_Status, 0, CSprite::DrawType_Draw);
	mUIText.Set(200 - 64, 150, 0, 0, mUI_PlaceTBox, 0, CSprite::DrawType_AlphaBlend);
	mUIText.mAlpha = 0x00;
	//ui initialize

	//map initialize

	for (int i = 0; i < 11; i++) {
		mMap->AddCharacter(chrToAdd_01[i][0], chrToAdd_01[i][1] + 1, chrToAdd_01[i][2], chrToAdd_01[i][3]);
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

CKarionMeetingRoom::~CKarionMeetingRoom()
{
	DeleteObject(mFont);
	CImageFile::Delete(mUI_Frame);
	CImageFile::Delete(mUI_PlaceTBox);
	CImageFile::Delete(mUI_Status);
}

bool CKarionMeetingRoom::isMustChanged()
{
	return isSceneEnded;
}

void CKarionMeetingRoom::onFrameMove()
{
	switch (sceneOrder) {
	case 0:
		if (frameCount > 10) {
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
	case 1: //char move
		if (frameCount <= 90) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[9]->Walk(1, 0, mMap);
				switch (frameCount / 10) {
				case 0:
					mMap->mCharacters[3]->ChangeAni(charR);
					mMap->mCharacters[4]->ChangeAni(charL);
					mMap->mCharacters[5]->ChangeAni(charR);
					break;
				case 2:
					mMap->mCharacters[4]->ChangeAni(charB);
					break;
				case 3:
					mMap->mCharacters[4]->ChangeAni(charR);
					break;
				case 7:
					mMap->mCharacters[0]->ChangeAni(charR);
					break;
				}
			}
		}
		else if (frameCount <= 150) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[9]->Walk(0, -1, mMap);
				switch (frameCount / 10 - 9) {
				case 1:
					mMap->mCharacters[1]->ChangeAni(charR);
					break;
				case 3:
					mMap->mCharacters[8]->ChangeAni(charR);
					break;
				}
			}
		}
		else {
			mMap->mCharacters[9]->ChangeAni(charL);
			isWaitingClick = TRUE;
		}
		frameCount++;
		break;
	case 4:
		if (frameCount <= 5) {
			if (frameCount % 5 == 0) {
				mMap->mCharacters[8]->Walk(0, -1, mMap);
			}
		}
		else if (frameCount <= 45) {
			if (frameCount % 5 == 0) {
				mMap->mCharacters[8]->Walk(1, 0, mMap);
			}
		}
		else if (frameCount <= 65) {
			if (frameCount % 5 == 0) {
				mMap->mCharacters[8]->Walk(0, 1, mMap);
			}
		}
		else {
			mMap->mCharacters[9]->ChangeAni(charB);
			isWaitingClick = TRUE;
		}
		frameCount++;
		break;
	case 12:
		if (frameCount <= 25) {
			if (frameCount % 5 == 0) {
				mMap->mCharacters[9]->Walk(0, 1, mMap);
				switch (frameCount / 5) {
				case 0:
					mMap->mCharacters[6]->ChangeAni(charL);
					break;
				}
			}
		}
		else if (frameCount <= 75) {
			if (frameCount % 5 == 0) {
				mMap->mCharacters[9]->Walk(-1, 0, mMap);
				switch (frameCount / 5 - 5) {
				case 1:
					mMap->mCharacters[1]->ChangeAni(charF);
					break;
				case 3:
					mMap->mCharacters[0]->ChangeAni(charF);
					break;
				case 5:
					mMap->mCharacters[4]->ChangeAni(charB);
					break;
				case 8:
					mMap->mCharacters[4]->ChangeAni(charL);
				}
			}
		}
		else if (frameCount <= 85) {
			if (frameCount % 5 == 0) {
				mMap->mCharacters[9]->Walk(0, 1, mMap);
			}
		}
		else if (frameCount <= 95) {
			if (frameCount % 5 == 0) {
				mMap->mCharacters[10]->Walk(0, -1, mMap);
			}
		}
		else {
			
			isWaitingClick = TRUE;
		}
		frameCount++;
		break;
	case 15:
		if (frameCount <= 10) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[9]->Walk(1, 0, mMap);
			}
		}
		else if (frameCount <= 60) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[9]->Walk(0, 1, mMap);
				switch (frameCount / 10 - 1)
				{
				case 0:
					mMap->mCharacters[10]->ChangeAni(charR);
				case 4:
					mMap->mCharacters[10]->ChangeAni(charF);
				}
			}
		}
		else if (frameCount <= 80) {}
		else if (frameCount <= 100) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[3]->Walk(1, 0, mMap);
				mMap->mCharacters[4]->Walk(-1, 0, mMap);
			}
		}
		else if (frameCount <= 140) {
			if (frameCount % 10 == 0) {
				mMap->mCharacters[3]->Walk(0, 1, mMap);
				mMap->mCharacters[4]->Walk(0, 1, mMap);
			}
		}
		else if (frameCount > 160) isSceneEnded = TRUE;
		frameCount++;
		break;
	case 2:		case 3:		case 5:		case 6:		case 7:		case 8:		case 9:
	case 10:	case 11:	case 13:	case 14:
		if (frameCount < 20) {
			mMap->CharMoves(ChrActs_01[textOrder]);
			frameCount++;
			break;
		}
		else {
			mTxtBox = new CTextBox;
			mTxtBox->SetChar(textChr_01[textOrder]);
			textSceneCheck = TRUE;
			isWaitingClick = TRUE;
			textReady = TRUE;
			
		}
		break; //text 출력, 단순 움직임
	case 16:
		isSceneEnded = TRUE;
		break;
	}

	mMap->OnFrameMove();
}

void CKarionMeetingRoom::onDraw(HDC hdc)
{
	CScreen screen(608 + 16, 336+16);

	mMap->Draw2(screen.m_HDC);

	screen.DrawDS(hdc, 0, 48-16,
		0, 0, CApplication::theApp->w_width, CApplication::theApp->w_height);

	mUIText.Draw(hdc);

	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(0, 0, 0));
	HFONT oldFont;
	oldFont = (HFONT)SelectObject(hdc, mFont); //text option

	if (textReady) {
		if (mTxtBox) {
			mFont = mTxtBox->mFont;
			mTxtBox->Print(text_01[textOrder], hdc);
		}
		else {
			TextOutW(hdc, 240, 165, text_01[sceneOrder][0], wcslen(text_01[sceneOrder][0]));
		}
	}

	mUIStatus.Draw(hdc);
	mUIFrame.Draw(hdc);
}

void CKarionMeetingRoom::onMouseDown(UINT x, UINT y, UCHAR left_right)
{
	if (isWaitingClick) {
		sceneOrder++;
		frameCount = 0;
		textReady = FALSE;
		isWaitingClick = FALSE;
		mUIText.mAlpha = 0x00;

		if (textSceneCheck) {
			if(mTxtBox) delete mTxtBox;
			mTxtBox = nullptr;
			textOrder++;
			textSceneCheck = FALSE;
		}
	}
}
