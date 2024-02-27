#pragma once


class CApplication
{
public:
	CApplication();

	void 화면갱신();

public:
	static CApplication* theApp; //클래스 안이어도 전역변수, singletone : 오직 한개 클래스 객체만 만드려고 할 경우.

	HINSTANCE	mhInst;
	HWND		mhWnd;

	int w_width;
	int w_height;
};

