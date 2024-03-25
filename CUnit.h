#pragma once
#include "CImageFile.h"
#include "CSprite.h"
#include "CAnimation.h"
#include "CAStarHandler.h"

class CMap;

class CUnit {
public:
	CUnit();
	~CUnit();
	void Twitch(int frames);
	bool Move(int x, int y, CMap* cmap); //단순 이동
    void MoveTo(int sx, int sy);
	bool Walk(int dx, int dy, CMap* cmap); //방향, 애니메이션 포함
	void ChangeAni(std::wstring& pname);
	
	void pathFind(int destX, int destY, CMap* cmap);
	bool trackingPath(CMap* cmap);

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

	int size;

	int x;
	int y; //coordinate

	int destX;
	int destY;

	bool isMoving;
};

