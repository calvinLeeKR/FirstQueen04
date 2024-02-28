#pragma once

#include "CImageFile.h"
#include "CSprite.h"

struct MINIMAP {
	int origin_x;
	int origin_y;
	int x;
	int y;
	int width;
	int height;
};

class CUnit;

class CMap {
public:
	CMap();
	CMap(int x, int y);
	~CMap();

	void Draw(HDC hdc);
	void Draw2(HDC hdc);
	
	void AddCharacter(int id, int x, int y, int dir);
	void CameraMove(float x, float y); //x,y만큼 카메라 움직임
	void OnFrameMove();

	void CharMoves(int moves[5]);

	void Duplicate(CMap* oldMap);
public:
	std::vector<CUnit*> mCharacters;

	CImageFile* mBackGround;

	CSprite mBG;

	int posX;
	int posY; //map pos

	int sizeX; //pixel 16 : 1
	int sizeY;

	int cameraX; //camera view
	int cameraY;
};

