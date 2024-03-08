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
	void Print(const LPCWSTR text[4], HDC hdc);
public:
	int px;
	int py;

	int lines;

	HFONT mFont;

	CImageFile* textImg;
	CImageFile* charBox;

	CSprite mTextImg;
	CSprite mCharBox;

	CUnit* mChar;

};

