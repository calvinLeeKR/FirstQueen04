#include "pch.h"
#include "CUnit.h"
#include "character_id_table.h"
#include "resource.h"

CUnit::CUnit()
{
	//charImg = CImageFile::New(MAKEINTRESOURCE(OBJ_SOLDIER_F), L"OBJ_SOLDIER");
	//mCharImg.Set(0, 0, 0, 0, charImg, RGB(255,0,255), CSprite::DrawType_Transparent);
	//normal unit sample

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
