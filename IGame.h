#pragma once

#include "IScene.h"
#include "CScreen.h"
#include "CApplication.h"


class IGame
{
public:
	IGame() : mCurrent(NULL) {}

	virtual void onChangeScene() = 0;

	virtual void onFrameMove() 
	{
		onChangeScene();
		if (mCurrent) mCurrent->onFrameMove();
		InvalidateRect(CApplication::theApp->mhWnd, NULL, FALSE);
	}

	virtual void onDraw(HDC hdcWnd) 
	{
		if (mCurrent) {
			CScreen screen(hdcWnd, 640, 480); //window size
			mCurrent->onDraw(screen.m_HDC); //double buffering
			
			screen.Draw(hdcWnd);
		}
	}

	virtual void onKeyDown(UINT virtual_key)
	{
		char str[100];
		//sprintf_s(str, 100, "V key: %d\n", virtual_key);
		OutputDebugStringA(str);

		if (mCurrent) mCurrent->onKeyDown(virtual_key);
	}

	virtual void onMouseMove(UINT x, UINT y)
	{
		char str[100];
		//sprintf_s(str, 100, "Mouse Move : %d, %d\n", x,y);
		OutputDebugStringA(str);

		if (mCurrent) mCurrent->onMouseMove(x, y);
	}

	virtual void onMouseDown(UINT x, UINT y, UCHAR left_right)
	{
		char str[100];
		//sprintf_s(str, 100, "Mouse Down :(%d) %d, %d\n", left_right, x, y );
		OutputDebugStringA(str);

		if (mCurrent) mCurrent->onMouseDown(x, y, left_right);
	}

public:
	IScene* mCurrent;

};

