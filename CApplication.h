#pragma once


class CApplication
{
public:
	CApplication();

	void ȭ�鰻��();

public:
	static CApplication* theApp; //Ŭ���� ���̾ ��������, singletone : ���� �Ѱ� Ŭ���� ��ü�� ������� �� ���.

	HINSTANCE	mhInst;
	HWND		mhWnd;

	int w_width;
	int w_height;
};

