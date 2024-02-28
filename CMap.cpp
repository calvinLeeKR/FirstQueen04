#include "pch.h"
#include "CScreen.h"
#include "CApplication.h"
#include "CMap.h"
#include "CUnit.h"
#include "resource.h"
#include "character_id_table.h"

CMap::CMap()
{
	posX = 16;
	posY = 16;

	cameraX = 0;
	cameraY = 0;
	
	mBackGround = CImageFile::New(MAKEINTRESOURCE(CBG_CASTLEHALL), L"CBG_CASTLEHALL");
	mBG.Set(posX, posY, 0, 0, mBackGround, 0, CSprite::DrawType_Draw);
}

CMap::CMap(int x, int y)
{
	sizeX = x;
	sizeY = y;
}

CMap::~CMap()
{
	delete mBackGround;
}

void CMap::Draw(HDC hdc)
{
	mBG.mDestX = (-1) * cameraX + posX;
	mBG.mDestY = (-1) * cameraY + posY;

	for (CUnit* ic : mCharacters) {
		ic->UpdateCamPos(cameraX, cameraY);
	}

	mBG.Draw(hdc);

	for (CUnit* ic : mCharacters) {
		ic->Draw(hdc);
	}
}

void CMap::Draw2(HDC hdc)
{
	mBG.mDestX = posX;
	mBG.mDestY = posY;

	for (CUnit* ic : mCharacters) {
		ic->UpdateCamPos(0, 0);
	}

	mBG.Draw(hdc);

	for (CUnit* ic : mCharacters) {
		ic->Draw(hdc);
	}
}


void CMap::AddCharacter(int id, int x, int y, int dir)
{
	CUnit* tempchrptr;
	tempchrptr = new CUnit();

	tempchrptr->ChangeImg(id);
	tempchrptr->id = id;
	tempchrptr->x = x;
	tempchrptr->y = y;


	std::wstring tempstr;
	if (dir == 0) tempstr = L"char_F";
	else tempstr = L"char_O";
	
	tempchrptr->mCharFile.ani->CreateSampleNPC();

	tempchrptr->ChangeAni(tempstr);

	tempchrptr->mCharSprite.Set2(tempstr, x, y, tempchrptr->mCharFile.ani, tempchrptr->mCharFile.imgFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
	tempchrptr->mCharSprite.Update(0);

	mCharacters.push_back(tempchrptr);
}

void CMap::CameraMove(float x, float y)
{
	cameraX += x;
	cameraY += y;
}

void CMap::OnFrameMove()
{
	for (auto it : mCharacters) {
		it->OnFrameMove();
	}
}

void CMap::CharMoves(int moves[5])
{
	if (mCharacters[moves[0]]) {
		if (moves[1]) {
			mCharacters[moves[0]]->Twitch(60);
		}
	}

	if (mCharacters[moves[2]]) {
		mCharacters[moves[2]]->Move(moves[3], moves[4]);
		moves[3] = 0;
		moves[4] = 0;
	}

	if (mCharacters[moves[5]]) {
		if (moves[6] == 1)
			mCharacters[moves[5]]->ChangeAni((std::wstring&)L"char_F");
	}
}

void CMap::Duplicate(CMap* oldMap)
{
	mCharacters = oldMap->mCharacters;
	mBackGround = oldMap->mBackGround;
	mBG = oldMap->mBG;
	posX = 0;
	posY = 0;
}
