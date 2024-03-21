#pragma once
#include "CImageFile.h"
#include "CSprite.h"
#include "CAnimation.h"
#include "CAStarHandler.h"

class CUnit {
public:
	CUnit();
	~CUnit();
	void Twitch(int frames);
	void Move(int x, int y); //단순 이동
    void MoveTo(int sx, int sy);
	void Walk(int dx, int dy); //방향, 애니메이션 포함
	void ChangeAni(std::wstring& pname);
	
	void pathFind(int destX, int destY, CMap* cmap, CUnit* cunit);
	bool trackingPath();

	void UpdateCamPos(float cx, float cy);
	void Draw(HDC hdc);
	void ChangeImg(int mid);

	void OnFrameMove();
public:
	//CImageFile* charImg;
	//CSprite	mCharImg;

	ANIM_FILE	mCharFile;
	CFrameSprite mCharSprite;

	CAStarHandler* mAStarHandler;

	int selfAnimFrame;

	int id;

	int x;
	int y; //coordinate

	int destX;
	int destY;
};

