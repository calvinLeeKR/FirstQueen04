#pragma once

#include "CImageFile.h"
#include "CSprite.h"
#include "CUnit.h"

class CTextBox
{
public:
	CTextBox();
	~CTextBox();
	void MoveBox(int x, int y);
	void SetChar(int mid);
	void Print(LPCWSTR tl_1, LPCWSTR tl_2, LPCWSTR tl_3, HDC hdc);
public:
	int px;
	int py;

	HFONT mFont;

	CImageFile* textImg;
	CImageFile* charBox;

	CSprite mTextImg;
	CSprite mCharBox;

	CUnit* mChar;

};

