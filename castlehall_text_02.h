#pragma once

#include "pch.h"
#include "character_id_table.h"

int chrToAdd_02[30][4] = { //id, x, y, direction //front = 0, other = 1, left = 10, right = 11, back = 12, action = 13
	{ID_SOLDIER, 12, 9, 0},			//0
	{ID_SOLDIER, 24, 9, 0},
	{ID_SOLDIER_2, 2, 30, 11},
	{ID_SOLDIER_2, 8, 30, 11},
	{ID_SOLDIER_2, 5, 32, 11},		//4
	{ID_SOLDIER_2, 2, 34, 11},
	{ID_SOLDIER_2, 8, 34, 11},
	{ID_SOLDIER_2, 5, 36, 11},
	{ID_SOLDIER_2, 28, 30, 10},
	{ID_SOLDIER_2, 31, 32, 10},		//9
	{ID_SOLDIER_2, 28, 34, 10},
	{ID_SOLDIER_2, 34, 30, 10},
	{ID_SOLDIER_2, 31, 36, 10},
	{ID_SOLDIER_2, 34, 34, 10},		
	{ID_SOLDIER_2, 14, 30, 0},		//14
	{ID_SOLDIER_2, 22, 30, 0},
	{ID_SOLDIER_2, 12, 32, 11},
	{ID_SOLDIER_2, 24, 32, 10},
	{ID_GENELU, 18, 26, 0},			//18
	{ID_ARES, 18, 35, 12}			//19
};

int ChrActs_02[30][7] = { // id, if:Twitch(), Move{id, x, y}, ChangeAni(id, string)
	{},
};


int textChr_02[30] = {
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

const LPCWSTR text_02[30][4] = {
	{
	},
	{
	L"아레스:⋯그러므로 바르시아의 왕이여!",
	L"신의 섭리에 따라 당신이 만든 병사들",
	L"을 가능한 빨리 처분하여 주기 바라오."
	},
	{
	L"제넬루:카리온의 생각은 이미 알고 있",
	L"다. 그러나 나의 병사는 나의 아들과",
	L"마찬가지. 처분할 수는 없다. 필요하다면",
	L"나누어 주지."
	},
	{
	L"닥치시오! 당신이 만든 악마때문에 백",
	L"성들도 고통받고 있소! 사람들을 몰아",
	L"내고 로그리스를 당신의 쓰레기로 채울",
	L"생각이오!"
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