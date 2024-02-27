#include "pch.h"
#include "CStartMenu.h"
#include "CImageFile.h"
#include "resource.h"
#include "startmenu_text.h"


CStartMenu::CStartMenu()
{
	mStartMenuFile	= CImageFile::New(MAKEINTRESOURCE(IDB_LOBBY), L"IDB_LOBBY");
	mHighlightBar	= CImageFile::New(MAKEINTRESOURCE(TEXT_HIGHLIGHT), L"TEXT_HIGHLIGHT");
	mBG.Set(-2, 0, 0, 0, mStartMenuFile, 0, CSprite::DrawType_Draw);
	mHLB.Set(0, 0, 0, 0, mHighlightBar, 0, CSprite::DrawType_AlphaBlend);
	mHLB.mAlpha = 0xFF;

	hlBoxX = 0;
	hlBoxY = 0;
	boxActivated = FALSE;

	frameCount = 0;
	firFrameCount = 0;
	endFrameCount = 0;

	endHandler = FALSE;

	mFont = CreateFontW(17, 0, 0, 0, FW_BOLD, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("돋움"));
}

CStartMenu::~CStartMenu()
{
	DeleteObject(mFont);
	delete mStartMenuFile;
}

bool CStartMenu::isMustChanged()
{
	if (endHandler) return true;
	return false;
}

void CStartMenu::onFrameMove()
{
}

void CStartMenu::onDraw(HDC hdc)
{
	mBG.Draw(hdc);

	if (boxActivated) { mHLB.Draw(hdc); }

	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(0, 0, 0));

	HFONT oldFont;

	oldFont = (HFONT)SelectObject(hdc, mFont);

	for (int i = 0; i < 8; i++) {
		if(i == 0) {
			SetTextColor(hdc, RGB(0xE5, 0xB4, 0x09));
			TextOutW(hdc, textposX, textposY + i * gapY, menuText[i], wcslen(menuText[i]));
			SetTextColor(hdc, RGB(0, 0, 0));
		}
		else {
			TextOutW(hdc, textposX, textposY + i * gapY, menuText[i], wcslen(menuText[i]));
		}
	}

	SelectObject(hdc, oldFont);
}

void CStartMenu::onMouseMove(UINT x, UINT y)
{
	for (int i = 0; i < 8; i++) {
		switch (i) {
		case 0: case 1: case 6: break;
		default:
			if ((x >= textposX) && (x <= textposX + 200) && (y >= textposY + gapY * i) && (y < textposY + gapY * (i + 1))) { // 사각 범위 안에 들어오면
				mHLB.Set(textposX - 4, textposY + gapY * i, 0, 0, mHighlightBar, 0, CSprite::DrawType_AlphaBlend);
				mHLB.mAlpha = 0xFF;
				boxActivated = TRUE;
				return;
			}
			break;
		}
		boxActivated = FALSE;
	}
}

void CStartMenu::onMouseDown(UINT x, UINT y, UCHAR left_right)
{
	if ((x >= textposX) && (x <= textposX + 200) && (y >= textposY + gapY * 7) && (y < textposY + gapY * 8))
		endHandler = TRUE;
	else endHandler = FALSE;
}
