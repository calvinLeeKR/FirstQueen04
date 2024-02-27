#pragma once

#define textposX 210
#define textposY 120

#define gapY 19
#define FRAME_COUNTER 4
#define CHANGE_SCENE_FRAME 100
#define ENTER_SCENE_FRAME 100

#include "pch.h"

const WCHAR menuText[8][50] = {
	L"시작  장소의  선택",
	L"",
	L"리오스/서쪽",
	L"리오스/서쪽",
	L"카리온성",
	L"카리온성",
	L"",
	L"처음부터"
};

const WCHAR savedataInfo[2][4][20] = {
	{
	L"리오스/서쪽",
	L"리오스/서쪽",
	L"카리온성",
	L"카리온성"
	},
	{
	L"320분",
	L"120분",
	L"20분",
	L"8분"
	}
};
