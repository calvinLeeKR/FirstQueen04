#pragma once

#include "pch.h"
#include "character_id_table.h"

int chrToAdd_01[30][4] = { //id, x, y, direction //front = 0, other = 1
	{ID_FULLARMORSOLDIER, 12, 5, 0},	//0
	{ID_FULLARMORSOLDIER, 16, 5, 0},	
	{ID_FULLARMORSOLDIER, 24, 5, 0},
	{ID_FULLARMORSOLDIER, 14, 18, 0},
	{ID_FULLARMORSOLDIER, 22, 18, 0},
	{ID_ARMORSOLDIER, 5, 7, 1},			//5
	{ID_ARMORSOLDIER, 31, 7, 0},
	{ID_ARCBISHOP, 14, 3, 0},
	{ID_GONRAD, 20, 5, 0},
	{ID_ARES, 18, 16, 0},				//9
	{ID_AERAIN, 18, 22, 0}				//10
};

int ChrActs_01[30][7] = { // id, if:Twitch(), Move{id, x, y}, ChangeAni(id, string)
	{},
	{	0,	0,	0,	0,	0,	0,	0	},
	{	0,	0,	0,	0,	0,	0,	0	},
	{	0,	0,	0,	0,	0,	0,	0	},
	{	0,	0,	0,	0,	0,	0,	0	},
	{	0,	0,	0,	0,	0,	0,	0	},
	{	0,	0,	0,	0,	0,	0,	0	},
	{	0,	0,	0,	0,	0,	0,	0	},
	{	0,	0,	0,	0,	0,	0,	0	},
	{	0,	0,	0,	0,	0,	0,	0	},
	{	0,	0,	0,	0,	0,	0,	0	}
};


int textChr_01[30] = {
	100,
	ID_ARES,
	ID_FULLARMORSOLDIER,
	ID_GONRAD,
	ID_ARES,
	ID_GONRAD,
	ID_ARES,
	ID_GONRAD,
	ID_ARES,
	ID_ARCBISHOP,
	ID_AERAIN,
	ID_ARES
};

const WCHAR text_01[30][3][50] = {
	{
	L"카리온성 회의실"
	},
	{
	L"아레스 : 여러분! 나는 지금부터 바르시",
	L"아왕 제넬루를 암살하기 위해 떠날 생각이오."
	},
	{
	L"에크터 : 그런 일이라면 나한테 맡기시오!",
	L"그는 마법으로 강한 군대를 조직했소. 이",
	L"제 곧 로그리스를 멸망시키고 말 것이오."
	},
	{
	L"곤라트 : 그렇소! 제넬루는 우리에게",
	L"맡기시오 !"
	},
	{
	L"아레스 : 모르는 소리 ! 제넬루에게는 강",
	L"한 호위대가 있소. 나는 그를 직접 만날 수",
	L"있으니 없앨 기회가 있을 것이오."
	},
	{
	L"곤라트 : 정 그러시다면 호위병과 함께..."
	},
	{
	L"아레스 : 그럴 필요 없소 ! 애크터, 국경을",
	L"맡아 주시오. 곤라트는 나에게 만약 일이",
	L"생기면 뒤를 맡아 주시오."
	},
	{
	L"곤라트 : 왕에게 일이 생기면 뒤를 따르",
	L"는 것은 신하된 도리. 염려 마시고 바",
	L"르시아를 빨리 무찔러 주십시오."
	},
	{
	L"아레스 : 서둘지 마시오! 우리에겐 아직",
	L"힘이 없소. 그러나 나는 반드시 살아서",
	L"돌아올 것이오. 그때까지 잘 부탁하오."
	},
	{
	L"대주교 : 신의 가호가 있기를..."
	},
	{
	L"애레인 : 기다려요! 같이 가요!"
	},
	{
	L"아레스 : 너는 오히려 방해가 될 뿐이야,",
	L"애레인. 더 걱정되거든. 무슨 뜻인지",
	L"알겠지 ? "
	}
};