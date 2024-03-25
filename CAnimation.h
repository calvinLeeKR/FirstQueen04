#pragma once

#include "CSprite.h"

struct FRAME {
	int x;
	int y;
	int width;
	int height;

	FRAME() :x(0), y(0), width(0), height(0) {}
	FRAME(int _x, int _y, int _w, int _h) :x(_x), y(_y), width(_w), height(_h) {}
	//auto initialize
}; //frame별 데이터 struct

struct ANIM_KEY {
	int frameNo; //frame번호로 들고있을것이므로
	int delayTime;

	ANIM_KEY() :frameNo(0), delayTime(0) {}
	ANIM_KEY(int idx, int delay) :frameNo(idx), delayTime(delay) {}
};

struct FRAMANIM_INSTANCE {
	int currentTime;
	int delayTime;
	int anikeyNo;
	FRAME frame;
};

struct FrameAnimation {
	std::wstring			m_Name;
	std::vector<FRAME>		m_Frames;
	std::vector<ANIM_KEY>	m_AnimKeys;

	void UpdateInstance(FRAMANIM_INSTANCE& inst);
};

class CAnimation {
public:
	~CAnimation();
	void CreateSample();
	void CreateSampleNPC();
    void CreateSample4Direction();
    void CreateSample4DirectionDead();
	void CreateSample4D48();

	FrameAnimation* Find(std::wstring& name);
public:
	std::vector<FrameAnimation*> m_FrameAnimations;
};

struct ANIM_FILE {
	CImageFile* imgFile;
	CAnimation* ani;
};

class CFrameSprite : public CSprite { //csprite 선언된 좌표 입력 할것임
public:
	void Set2(std::wstring pname,
		int dx, int dy,
		CAnimation* ani,
		CImageFile* img, UINT color, TDrawType dt);
	void ChangeAnimation(std::wstring& pname);
	void Update(int dt);

public:
	CAnimation*			m_Animation;
	FrameAnimation*		m_CurrentFAni;

	FRAMANIM_INSTANCE	m_AnimInst;
};

