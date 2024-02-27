#include "pch.h"
#include "CIntroSceneBlack.h"
#include "CImageFile.h"
#include "resource.h"
#include "intro_text.h"

#define sceneTh 8

CIntroSceneBlack::CIntroSceneBlack()
{
	mIntroFile = CImageFile::New(MAKEINTRESOURCE(IDB_BLACK), L"IDB_BLACK");
	mBlackFile = CImageFile::New(MAKEINTRESOURCE(IDB_BLACK), L"IDB_BLACK");

	mBG.Set(0, 0, 0, 0, mIntroFile, 0, CSprite::DrawType_Draw);
	mFade.Set(0, 0, 0, 0, mBlackFile, 0, CSprite::DrawType_AlphaBlend);
	mFade.mAlpha = 0xFF;

	curX = 0;
	curY = 0;
	frameCount = 0;
	firFrameCount = 0;
	endFrameCount = 0;

	mFont = CreateFontW(17, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("궁서"));
}

CIntroSceneBlack::~CIntroSceneBlack()
{
	DeleteObject(mFont);
	delete mIntroFile;
	delete mBlackFile;
}

bool CIntroSceneBlack::isMustChanged()
{
	if (endFrameCount == CHANGE_SCENE_FRAME) return TRUE;
	else return false;
}

void CIntroSceneBlack::onFrameMove()
{
	if (firFrameCount != ENTER_SCENE_FRAME) {
		firFrameCount++;
		if (mFade.mAlpha <= 0) return;
		mFade.mAlpha -= 3;
		return;
	}

	if (frameCount == FRAME_COUNTER) {
		if (curY >= 5);
		else if (curX < wcslen(introText[sceneTh][curY])) curX++;
		else { curX = 0; curY++; }
		frameCount = 0;
	}
	else frameCount++;

	if (curY == 5 && curX == 0) {
		endFrameCount++;
		if (mFade.mAlpha >= 255) return;
		mFade.mAlpha += 3;
	}
}

void CIntroSceneBlack::onDraw(HDC hdc)
{
	mBG.Draw(hdc);

	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(0, 0, 0));

	HFONT oldFont;

	oldFont = (HFONT)SelectObject(hdc, mFont);

	int k = 0;
	for (int i = 1; i >= -1; i--) {
		for (int j = 1; j >= -1; j--) {
			while (k <= curY - 1) {
				TextOutW(hdc, textStyle[sceneTh][0] + i, textStyle[sceneTh][1] + j + k * gapY, introText[sceneTh][k], wcslen(introText[sceneTh][k]));
				k++;
			}
			TextOutW(hdc, textStyle[sceneTh][0] + i, textStyle[sceneTh][1] + j + curY * gapY, introText[sceneTh][curY], curX); //검은글자배경
		}
	}
	SetTextColor(hdc, RGB(255, 255, 255));
	k = 0;
	while (k <= curY - 1) {
		TextOutW(hdc, textStyle[sceneTh][0], textStyle[sceneTh][1] + k * gapY, introText[sceneTh][k], wcslen(introText[sceneTh][k]));
		k++;
	}
	TextOutW(hdc, textStyle[sceneTh][0], textStyle[sceneTh][1] + curY * gapY, introText[sceneTh][curY], curX); //흰글자


	SelectObject(hdc, oldFont);

	mFade.Draw(hdc); //curtain
}