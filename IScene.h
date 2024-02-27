#pragma once
#include "pch.h"

//추상클래스
//인터페이스 클래스

class IScene
{
public:
	virtual bool isMustChanged() = 0;
	virtual void onFrameMove() = 0;
	virtual void onDraw(HDC hdc) = 0;

	virtual void onKeyDown(UINT virtual_key) {}
	virtual void onMouseMove(UINT x, UINT y) {}
	virtual void onMouseDown(UINT x, UINT y, UCHAR left_right) {};
};

