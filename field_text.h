#pragma once

#include "pch.h"
#include "character_id_table.h"

int chrToAdd_03[40][4] = { //id, x, y, direction //front = 0, other = 1, left = 10, right = 11, back = 12, action = 13
	{ID_SOLDIER_2, 8, 2, 0},		//0
	{ID_SOLDIER_2, 11, 2, 0},
	{ID_SOLDIER_2, 14, 2, 0},
	{ID_SOLDIER_2, 21, 2, 0},
	{ID_SOLDIER_2, 24, 2, 0},		//4
	{ID_SOLDIER_2, 27, 2, 0},
	{ID_SOLDIER_2, 5, 5, 11},
	{ID_SOLDIER_2, 8, 5, 0},
	{ID_SOLDIER_2, 11, 5, 0},
	{ID_SOLDIER_2, 14, 5, 0},		//9
	{ID_SOLDIER_2, 21, 5, 0},
	{ID_SOLDIER_2, 24, 5, 0},
	{ID_SOLDIER_2, 27, 5, 0},
	{ID_SOLDIER_2, 30, 5, 10},		
	{ID_SOLDIER_2, 16, 7, 0},		//14
	{ID_SOLDIER_2, 19, 7, 0},
	{ID_SOLDIER_2, 2, 8, 11},
	{ID_SOLDIER_2, 2, 11, 11},
	{ID_SOLDIER_2, 2, 14, 11},
	{ID_SOLDIER_2, 5, 9, 11},		//19
	{ID_SOLDIER_2, 5, 12, 11},
	{ID_SOLDIER_2, 8, 8, 11},
	{ID_SOLDIER_2, 12, 8, 0},
	{ID_SOLDIER_2, 23, 8, 0},
	{ID_SOLDIER_2, 27, 8, 10},		//24
	{ID_SOLDIER_2, 30, 9, 10},
	{ID_SOLDIER_2, 30, 12, 10},
	{ID_SOLDIER_2, 33, 8, 10},
	{ID_SOLDIER_2, 33, 11, 10},
	{ID_SOLDIER_2, 33, 14, 10},		//29
	{ID_HORSEGENERAL_1, 17, 3, 12},	//30
	{ID_HORSESOLDIER_1, 13, 11, 11},	
	{ID_HORSESOLDIER_1, 21, 11, 10},
	{ID_LIGHTSOLDIER, 9, 16, 11},
	{ID_LIGHTSOLDIER, 11, 19, 11},	//34
	{ID_LIGHTSOLDIER, 13, 16, 11},
	{ID_HORSESOLDIER_2, 17, 16, 12},
	{ID_LIGHTSOLDIER, 22, 16, 10},
	{ID_LIGHTSOLDIER, 24, 19, 10},
	{ID_LIGHTSOLDIER, 26, 16, 10},	//39
};

int ChrActs_03[30][7] = { // id, if:Twitch(), Move{id, x, y}, ChangeAni(id, string)
	{},
};


int textChr_03[30] = {
	100,
	ID_ARES,
	ID_GENELU,
	ID_ARES,
	ID_ARES,
	ID_GENELU,
	ID_GENELU,
	ID_GENELU,
	ID_GENERAL_01
};

const LPCWSTR text_03[30][4] = {
	{
	},
	{
	L"적장:포기해라! 너의 아레스는 우리",
	L"군대에게 잡혔다. 덤빌수록 그 녀석의",
	L"목숨만 짧아 질 뿐이다!"
	},
	{
	L"애크터:윽! 후퇴하라! 그러나 난 물",
	L"러서지 않는다! 여기서 죽어도 후회는",
	L"없다!"
	},
	{
	L"병사 : 우리도 싸우자 !!"
	},
	{
	L"으악! 모, 몸이⋯?!"
	},
	{
	L"제넬루:멍청한 놈! 네 머리속 쯤은",
	L"다 꿰뚫어 보고 있다. 미리 경계하고",
	L"있었지. 헤헤헤!"
	},
	{
	L"감옥에서 천천히 머리나 식히시지. 그",
	L"후에 처벌하마!"
	},
	{
	L"제넬루:지금 즉시 카리온으로 출동하라",
	L"! 아레스가 없는 한 카리온은 문제없",
	L"다!!"
	},
	{
	L"장군:예잇!"
	}
};