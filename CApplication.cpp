#include "pch.h"
#include "CApplication.h"

CApplication* CApplication::theApp = NULL;

CApplication app;

CApplication::CApplication()
{
	theApp = this;

}

void CApplication::화면갱신()
{
	InvalidateRect(mhWnd, NULL, TRUE);

}
