#include "pch.h"
#include "CTextBox.h"
#include "CUnit.h"
#include "resource.h"

#define gapY 19

CTextBox::CTextBox()
{
	px = 200-64;
	py = 150;

	lines = 0;

	textImg = CImageFile::New(MAKEINTRESOURCE(UI_TEXTBOX_L4), L"UI_TEXTBOX");
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
	CImageFile::Delete(textImg);
	CImageFile::Delete(charBox);
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

void CTextBox::Print(const LPCWSTR text[4], HDC hdc)
{
	int templinecount = 0;

	while (text[templinecount++] && templinecount < 5) {}
	if(lines != templinecount-1) {
		//CImageFile::Delete(textImg);
		switch (templinecount-1) {
		case 1: 
			textImg = CImageFile::New(MAKEINTRESOURCE(UI_TEXTBOX_L1), L"UI_TEXTBOX_L1"); break;
		case 2:
			textImg = CImageFile::New(MAKEINTRESOURCE(UI_TEXTBOX_L2), L"UI_TEXTBOX_L2"); break;
		case 3:
			textImg = CImageFile::New(MAKEINTRESOURCE(UI_TEXTBOX), L""); break;
		case 4: case 5:
			textImg = CImageFile::New(MAKEINTRESOURCE(UI_TEXTBOX_L4), L"UI_TEXTBOX_L4"); break;
		}
		mTextImg.mImgFile = textImg;
		lines = templinecount-1;
	}

	mTextImg.Draw(hdc);

	mCharBox.Draw(hdc);

	mChar->Draw(hdc);

	for (int i = 0; i < lines; i++) {
		TextOutW(hdc, px + 84, py + 15 + gapY * i, text[i], wcslen(text[i]));
	}
}
