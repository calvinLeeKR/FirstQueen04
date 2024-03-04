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

void CMap::ChangeBGImage(CImageFile* mBGF)
{
	mBG.mImgFile = mBGF;
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

	switch (dir)
	{
	case 0: tempstr = L"char_F"; break;
	case 10: tempstr = L"char_L"; break;
	case 11: tempstr = L"char_R"; break;
	case 12: tempstr = L"char_B"; break;
	case 13: tempstr = L"char_A"; break;
	default: tempstr = L"char_O"; break;
	}
	
	switch (tempchrptr->id)
	{
	case ID_AERAIN:	case ID_GONRAD:	case ID_ARMORSOLDIER: case ID_FULLARMORSOLDIER:
	case ID_ARES:
		tempchrptr->mCharFile.ani->CreateSample4Direction();
		break;
	default:
		tempchrptr->mCharFile.ani->CreateSampleNPC();
		break;
	}

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
			mCharacters[moves[0]]->Twitch(120);
		}
	}

	if (mCharacters[moves[2]]) {
		mCharacters[moves[2]]->Move(moves[3], moves[4]);
		moves[3] = 0;
		moves[4] = 0;
	}

	if (mCharacters[moves[5]]) {
		std::wstring chrF = L"char_F";
		std::wstring chrO = L"char_O";
		if (moves[6] == 1) {
			mCharacters[moves[5]]->ChangeAni(chrF);
			moves[6] = 0;
		}
		else if (moves[6] == 2) {
			mCharacters[moves[5]]->ChangeAni(chrO);
			moves[6] = 0;
		}
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
