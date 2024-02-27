#include "pch.h"
#include "CTextBox.h"
#include "CUnit.h"
#include "resource.h"

#define gapY 19

CTextBox::CTextBox()
{
	px = 200-64;
	py = 150;

	textImg = CImageFile::New(MAKEINTRESOURCE(UI_TEXTBOX), L"UI_TEXTBOX");
	charBox = CImageFile::New(MAKEINTRESOURCE(UI_CHARBOX), L"UI_CHARBOX");

	mCharBox.Set(px, py, 0, 0, charBox, RGB(255, 0, 255), CSprite::DrawType_Transparent);
	mTextImg.Set(px + 64, py, 0, 0, textImg, 0, CSprite::DrawType_Draw);

	mChar = new CUnit();
	mChar->x = px + 16;
	mChar->y = py + 16;
	mChar->ChangeImg(0);
	mChar->mCharSprite.Update(0);

	mFont = CreateFontW(15, 0, 0, 0, FW_BOLD, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("µ¸¿ò"));
}

CTextBox::~CTextBox()
{
	delete textImg;
	delete charBox;
	DeleteObject(mFont);
}


void CTextBox::MoveBox(int x, int y)
{
	this->px = x;
	this->py = y;
}

void CTextBox::SetChar(int mid)
{
	mChar->ChangeImg(mid);
	mChar->mCharFile.ani->CreateSampleNPC();
	mChar->mCharSprite.Set2(L"char_F", px + 16, py + 16, mChar->mCharFile.ani, mChar->mCharFile.imgFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
	mChar->mCharSprite.Update(0);
}

void CTextBox::Print(LPCWSTR tl_1, LPCWSTR tl_2, LPCWSTR tl_3, HDC hdc)
{
	mTextImg.Draw(hdc);
	mCharBox.Draw(hdc);

	mChar->Draw(hdc);

	TextOutW(hdc, px + 84, py + 15 + gapY * 0, tl_1, wcslen(tl_1));
	TextOutW(hdc, px + 84, py + 15 + gapY * 1, tl_2, wcslen(tl_2));
	TextOutW(hdc, px + 84, py + 15 + gapY * 2, tl_3, wcslen(tl_3));
}
