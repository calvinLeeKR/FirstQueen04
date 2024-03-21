#include "pch.h"
#include "CUnit.h"
#include "character_id_table.h"
#include "resource.h"

CUnit::CUnit()
{
	//charImg = CImageFile::New(MAKEINTRESOURCE(OBJ_SOLDIER_F), L"OBJ_SOLDIER");
	//mCharImg.Set(0, 0, 0, 0, charImg, RGB(255,0,255), CSprite::DrawType_Transparent);
	//normal unit sample
	selfAnimFrame = 0;

	mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_SOLDIER2), L"OBJ_SOLDIER2");
	mCharFile.ani = new CAnimation;
	mCharFile.ani->CreateSampleNPC();
	mCharSprite.Set2(L"char_F", -64, -64, mCharFile.ani, mCharFile.imgFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
	mCharSprite.Update(0);
	//animated unit sample
}

CUnit::~CUnit()
{
	delete mCharFile.imgFile;
	delete mCharFile.ani;
}

void CUnit::Twitch(int frames)
{
	mCharSprite.Update(frames);
}

void CUnit::Move(int sx, int sy)
{
	this->x += sx;
	this->y += sy;
}

void CUnit::MoveTo(int sx, int sy) {
	this->x = sx;
	this->y = sy;
}

void CUnit::Walk(int dx, int dy) //for 4dir image file
{
	Move(dx, dy);
	std::wstring charR = L"char_R";
	std::wstring charL = L"char_L";
	std::wstring charF = L"char_F";
	std::wstring charB = L"char_B";
	if (dx >= 0 && dy == 0) mCharSprite.ChangeAnimation(charR);
	else if (dx < 0 && dy == 0) mCharSprite.ChangeAnimation(charL);
	else if (dx == 0 && dy >= 0) mCharSprite.ChangeAnimation(charF);
	else if (dx == 0 && dy < 0) mCharSprite.ChangeAnimation(charB);
	mCharSprite.Update((selfAnimFrame % 2) * 500);
	selfAnimFrame++;
}

void CUnit::UpdateCamPos(float cx, float cy)
{
	mCharSprite.mDestX = (-1) * cx + 16 * x;
	mCharSprite.mDestY = (-1) * cy + 16 * y;
}

void CUnit::Draw(HDC hdc)
{
	mCharSprite.Draw(hdc);
}

void CUnit::OnFrameMove()
{

}

void CUnit::ChangeImg(int mid)
{
	switch (mid) {
	case ID_SOLDIER:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_SOLDIER_F), L"OBJ_SOLDIER"); break;
	case ID_GABI:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_GABI), L"OBJ_GABI"); break;
	case ID_JANIL:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_JANIL), L"OBJ_JANIL"); break;
	case ID_KECK:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_KECK), L"OBJ_KECK"); break;
	case ID_LAIOS:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_LAIOS), L"OBJ_LAIOS"); break;
	case ID_MACGAIA:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_MACGAIA), L"OBJ_MACGAIA"); break;
	case ID_MAREAM:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_MAREAM), L"OBJ_MAREAM"); break;
	case ID_MOLDRED:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_MOLDRED), L"OBJ_MOLDRED"); break;
	case ID_MYSOLEN:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_MYSOLEN), L"OBJ_MYSOLEN"); break;
	case ID_OGG:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_OGG), L"OBJ_OGG"); break;
	case ID_ORASON:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_ORASON), L"OBJ_ORASON"); break;
	case ID_SARK:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_SARK), L"OBJ_SARK"); break;
	case ID_THRYHOOT:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_THRYHOOT), L"OBJ_THRYHOOT"); break;
	case ID_GENELU:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_GENELU), L"OBJ_GENELU"); break;
	case ID_AERAIN:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_AERAIN), L"OBJ_AERAIN"); break;
	case ID_GONRAD:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_GONRAD), L"OBJ_GONRAD"); break;
	case ID_ARCBISHOP:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_ARCBISHOP), L"OBJ_ARCBISHOP"); break;
	case ID_ARMORSOLDIER:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_ARMOREDSOLDIER), L"OBJ_ARMOREDSOLDIER"); break;
	case ID_FULLARMORSOLDIER:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_FULLARMORSOLDIER), L"OBJ_FULLARMORSOLDIER"); break;
	case ID_ARES:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_ARES), L"OBJ_ARES"); break;
	case ID_STONEGOLEM:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_STONEGOLEM), L"OBJ_STONEGOLEM"); break;
	case ID_GENERAL_01:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_GENERAL1), L"OBJ_GENERAL1"); break;
	case ID_SOLDIER_2:
		mCharFile.imgFile = CImageFile::New(MAKEINTRESOURCE(OBJ_SOLDIER2), L"OBJ_SOLDIER2"); break;
	}

	this->id = mid;
}

void CUnit::ChangeAni(std::wstring& pname)
{
	mCharSprite.ChangeAnimation(pname);
	mCharSprite.Update(0);
}

void CUnit::pathFind(int destX, int destY, CMap* cmap, CUnit* cunit)
{
	mAStarHandler = new CAStarHandler();
	mAStarHandler->RunAStar(x, y, destX, destY, cmap, cunit);
}

bool CUnit::trackingPath()
{
	if (mAStarHandler) {
		if (!mAStarHandler->path.empty()) { //경로가 남아있다면
			NODE* nextStep = mAStarHandler->path.top();
			Walk(nextStep->x - x, nextStep->y - y); //이동하고
			mAStarHandler->path.pop(); //경로 하나 제거
			return true; //탐색중이다
		}
		else {
			delete mAStarHandler;
			return false; //끝났다
		}
	}
	return false;
}

