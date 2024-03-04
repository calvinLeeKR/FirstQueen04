#pragma once
#include "CImageFile.h"
#include "CSprite.h"
#include "CAnimation.h"

class CUnit {
public:
	CUnit();
	~CUnit();
	void Twitch(int frames);
	void Move(int x, int y); //단순 이동
	void Walk(int dx, int dy); //방향, 애니메이션 포함
	void UpdateCamPos(float cx, float cy);
	void Draw(HDC hdc);
	void OnFrameMove();
	void ChangeImg(int mid);
	void ChangeAni(std::wstring& pname);
public:
	//CImageFile* charImg;
	//CSprite	mCharImg;

	ANIM_FILE	mCharFile;
	CFrameSprite mCharSprite;

	int id;

	int x;
	int y; //coordinate
};

