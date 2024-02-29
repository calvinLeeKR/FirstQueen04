#include "pch.h"
#include "CAnimation.h"

CAnimation::~CAnimation() {
	for (auto i : m_FrameAnimations) {
		if (i) {
			delete i;
			i = nullptr;
		}
	}
}

void CAnimation::CreateSample() {
	int w = 260 / 4;
	int h = 200 / 4; //frame 수가 4

	FrameAnimation* fa = new FrameAnimation;
	fa->m_Frames.push_back(FRAME(0		, 0, w, h));
	fa->m_Frames.push_back(FRAME(w		, 0, w, h));
	fa->m_Frames.push_back(FRAME(w * 2	, 0, w, h));
	fa->m_Frames.push_back(FRAME(w * 3	, 0, w, h)); //pos vector
	fa->m_AnimKeys.push_back(ANIM_KEY(0, 500));
	fa->m_AnimKeys.push_back(ANIM_KEY(1, 500));
	fa->m_AnimKeys.push_back(ANIM_KEY(2, 500));
	fa->m_AnimKeys.push_back(ANIM_KEY(3, 500));
	fa->m_Name = L"char_F";
	m_FrameAnimations.push_back(fa);

	FrameAnimation* fa_left = new FrameAnimation;
	fa_left->m_Frames.push_back(FRAME(0		, h, w, h));
	fa_left->m_Frames.push_back(FRAME(w		, h, w, h));
	fa_left->m_Frames.push_back(FRAME(w * 2	, h, w, h));
	fa_left->m_Frames.push_back(FRAME(w * 3	, h, w, h));
	fa_left->m_AnimKeys.push_back(ANIM_KEY(0, 500));
	fa_left->m_AnimKeys.push_back(ANIM_KEY(1, 500));
	fa_left->m_AnimKeys.push_back(ANIM_KEY(2, 500));
	fa_left->m_AnimKeys.push_back(ANIM_KEY(3, 500));
	fa_left->m_Name = L"char_L";
	m_FrameAnimations.push_back(fa_left);

	FrameAnimation* fa_right = new FrameAnimation;
	fa_right->m_Frames.push_back(FRAME(0	, h * 2, w, h));
	fa_right->m_Frames.push_back(FRAME(w	, h * 2, w, h));
	fa_right->m_Frames.push_back(FRAME(w * 2, h * 2, w, h));
	fa_right->m_Frames.push_back(FRAME(w * 3, h * 2, w, h));
	fa_right->m_AnimKeys.push_back(ANIM_KEY(0, 500));
	fa_right->m_AnimKeys.push_back(ANIM_KEY(1, 500));
	fa_right->m_AnimKeys.push_back(ANIM_KEY(2, 500));
	fa_right->m_AnimKeys.push_back(ANIM_KEY(3, 500));
	fa_right->m_Name = L"char_R";
	m_FrameAnimations.push_back(fa_right);

	FrameAnimation* fa_top = new FrameAnimation;
	fa_top->m_Frames.push_back(FRAME(0, h * 3, w, h));
	fa_top->m_Frames.push_back(FRAME(w, h * 3, w, h));
	fa_top->m_Frames.push_back(FRAME(w * 2, h * 3, w, h));
	fa_top->m_Frames.push_back(FRAME(w * 3, h * 3, w, h));
	fa_top->m_AnimKeys.push_back(ANIM_KEY(0, 500));
	fa_top->m_AnimKeys.push_back(ANIM_KEY(1, 500));
	fa_top->m_AnimKeys.push_back(ANIM_KEY(2, 500));
	fa_top->m_AnimKeys.push_back(ANIM_KEY(3, 500));
	fa_top->m_Name = L"char_B";
	m_FrameAnimations.push_back(fa_top);
}

void CAnimation::CreateSampleNPC()
{
	int w = 32;
	int h = 32;

	FrameAnimation* fa_front = new FrameAnimation;
	fa_front->m_Frames.push_back(FRAME(0, 0, w, h));
	fa_front->m_Frames.push_back(FRAME(w, 0, w, h));
	fa_front->m_AnimKeys.push_back(ANIM_KEY(0, 500));
	fa_front->m_AnimKeys.push_back(ANIM_KEY(1, 500));
	fa_front->m_Name = L"char_F";
	m_FrameAnimations.push_back(fa_front);

	FrameAnimation* fa_other = new FrameAnimation;
	fa_other->m_Frames.push_back(FRAME(0, h, w, h));
	fa_other->m_Frames.push_back(FRAME(w, h, w, h));
	fa_other->m_AnimKeys.push_back(ANIM_KEY(0, 500));
	fa_other->m_AnimKeys.push_back(ANIM_KEY(1, 500));
	fa_other->m_Name = L"char_O";
	m_FrameAnimations.push_back(fa_other);
}

void CAnimation::CreateSample4Direction() {
	int w = 32;
	int h = 32;

	FrameAnimation* fa = new FrameAnimation;
	fa->m_Frames.push_back(FRAME(0, 0, w, h));
	fa->m_Frames.push_back(FRAME(w, 0, w, h));
	fa->m_AnimKeys.push_back(ANIM_KEY(0, 500));
	fa->m_AnimKeys.push_back(ANIM_KEY(1, 500));
	fa->m_Name = L"char_F";
	m_FrameAnimations.push_back(fa);

	FrameAnimation* fa_left = new FrameAnimation;
	fa_left->m_Frames.push_back(FRAME(0, h, w, h));
	fa_left->m_Frames.push_back(FRAME(w, h, w, h));
	fa_left->m_AnimKeys.push_back(ANIM_KEY(0, 500));
	fa_left->m_AnimKeys.push_back(ANIM_KEY(1, 500));
	fa_left->m_Name = L"char_L";
	m_FrameAnimations.push_back(fa_left);

	FrameAnimation* fa_right = new FrameAnimation;
	fa_right->m_Frames.push_back(FRAME(0, h * 2, w, h));
	fa_right->m_Frames.push_back(FRAME(w, h * 2, w, h));
	fa_right->m_AnimKeys.push_back(ANIM_KEY(0, 500));
	fa_right->m_AnimKeys.push_back(ANIM_KEY(1, 500));
	fa_right->m_Name = L"char_R";
	m_FrameAnimations.push_back(fa_right);

	FrameAnimation* fa_top = new FrameAnimation;
	fa_top->m_Frames.push_back(FRAME(0, h * 3, w, h));
	fa_top->m_Frames.push_back(FRAME(w, h * 3, w, h));
	fa_top->m_AnimKeys.push_back(ANIM_KEY(0, 500));
	fa_top->m_AnimKeys.push_back(ANIM_KEY(1, 500));
	fa_top->m_Name = L"char_B";
	m_FrameAnimations.push_back(fa_top);

	FrameAnimation* fa_act = new FrameAnimation;
	fa_act->m_Frames.push_back(FRAME(0, h * 4, w, h));
	fa_act->m_Frames.push_back(FRAME(w, h * 4, w, h));
	fa_act->m_AnimKeys.push_back(ANIM_KEY(0, 500));
	fa_act->m_AnimKeys.push_back(ANIM_KEY(1, 500));
	fa_act->m_Name = L"char_A";
	m_FrameAnimations.push_back(fa_act);
}

FrameAnimation* CAnimation::Find(std::wstring& name)
{
	for (FrameAnimation* it : m_FrameAnimations) { //vector일경우 : 이용해서 멤버접근가능
		if (it->m_Name == name) {
			return it;
		}
	}

	return nullptr;
}

void CFrameSprite::Set2(std::wstring pname,
						int dx, int dy,
						CAnimation* ani,
						CImageFile* img, UINT color, TDrawType dt)
{
	std::wstring name(pname);
	CSprite::Set(dx, dy, 0, 0, img, color, dt);
	m_Animation = ani;

	ChangeAnimation(name);
}

void CFrameSprite::ChangeAnimation(std::wstring& pname)
{
	std::wstring name(pname);
	m_CurrentFAni = m_Animation->Find(name);
	ANIM_KEY key = m_CurrentFAni->m_AnimKeys[0];

	m_AnimInst.anikeyNo = 0;
	m_AnimInst.currentTime = 0;
	m_AnimInst.delayTime = key.delayTime;
	m_AnimInst.frame = m_CurrentFAni->m_Frames[key.frameNo];
}

void CFrameSprite::Update(int dt)
{
	m_AnimInst.currentTime += dt;
	m_AnimInst.delayTime -= dt;

	m_CurrentFAni->UpdateInstance(m_AnimInst); //update call

	mSrcX		= m_AnimInst.frame.x;
	mSrcY		= m_AnimInst.frame.y;
	mSrcWidth	= m_AnimInst.frame.width;
	mSrcHeight	= m_AnimInst.frame.height; //draw info 넘겨줌
}

void FrameAnimation::UpdateInstance(FRAMANIM_INSTANCE& inst)
{
	if (inst.delayTime > 0) return;

	inst.anikeyNo++;
	if (inst.anikeyNo >= m_AnimKeys.size()) inst.anikeyNo = 0;

	inst.delayTime = m_AnimKeys[inst.anikeyNo].delayTime;
	inst.frame = m_Frames[m_AnimKeys[inst.anikeyNo].frameNo];
}
