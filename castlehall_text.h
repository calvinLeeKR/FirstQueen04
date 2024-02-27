#pragma once

#include "pch.h"
#include "character_id_table.h"

#define textposX 220
#define textposY 165

#define gapY 19
#define FRAME_COUNTER 4
#define CHANGE_SCENE_FRAME 100
#define ENTER_SCENE_FRAME 100


int chrToAdd[30][4] = { //id, x, y, direction //front = 0, other = 1
	{ID_SOLDIER, 12, 9, 0},
	{ID_SOLDIER, 24, 9, 0},
	{ID_SOLDIER_2, 2, 30, 0},
	{ID_SOLDIER_2, 8, 30, 0},
	{ID_SOLDIER_2, 5, 34, 0},
	{ID_SOLDIER_2, 2, 34, 0},
	{ID_SOLDIER_2, 8, 34, 0},
	{ID_SOLDIER_2, 5, 36, 0},
	{ID_SOLDIER_2, 28, 30, 1},
	{ID_SOLDIER_2, 31, 32, 1},
	{ID_SOLDIER_2, 28, 34, 1},
	{ID_SOLDIER_2, 34, 30, 1},
	{ID_SOLDIER_2, 31, 36, 1},
	{ID_SOLDIER_2, 34, 34, 1},
	{ID_GENELU, 18, 26, 0},
	{ID_MACGAIA, 22, 27, 0},
	{ID_MOLDRED, 24, 28, 1},
	{ID_JANIL, 16, 24, 1},
	{ID_THRYHOOT, 24, 27, 1},
	{ID_OGG, 12, 28, 1},
	{ID_ORASON, 23, 48, 1},
	{ID_LAIOS, 20, 49, 1},
	{ID_KECK, 16, 49, 1},
	{ID_GABI, 13, 48, 1},
	{ID_MAREAM, 21, 52, 1},
	{ID_SARK, 18, 52, 1},
	{ID_MYSOLEN, 15, 52, 1},
};

int textChr[30] = {
	100,
	ID_GENELU,
	ID_GENELU,
	ID_KECK,
	ID_GABI,
	ID_ORASON,
	ID_LAIOS,
	ID_MYSOLEN,
	ID_MAREAM,
	ID_GENELU,
	ID_GENELU,
	ID_SARK,
	ID_THRYHOOT,
	ID_MACGAIA,
	ID_GENELU,
	ID_GENELU,
	ID_GENELU,
	ID_OGG,
	ID_MOLDRED
};

const WCHAR text[30][3][50] = {
	{
	L"바르시아성 왕실"
	},
	{
	L"바르시아왕 제넬루 : 여러분! 난 로그리",
	L"스의 대표로서 이제껏 많은 어려움을",
	L"극복해 왔소."
	},
	{
	L"허나, 요즘 내 우정을 배신하는 자가",
	L"나타났소. 그래도 나의 군대는 여러분의",
	L"나라를 반드시 지킬 것이오."
	},
	{
	L"베닉크왕 케크 : 마음도 넓으시군요! 그",
	L"런데 남쪽과 주변 촌놈들은 무슨 생각",
	L"을 하고 있는지 알 수가 없소."
	},
	{
	L"마시아왕 가비 : 만약 남쪽 녀석들이 이",
	L"마시아를 쳐들어 온다면 나와 루아스가",
	L"가만 두지는 않을거요!"
	},
	{
	L"노호크왕 오라슨 : 마시아의 좌우는 베닉",
	L"크성과 노호크성이 단단히 지키고 있으",
	L"니 안심하시오."
	},
	{
	L"리스레이왕 라이오스:마시아의 뒤에는",
	L"우리 리스레이성과 벨더의 세 성이 있소.",
	L"감히 바르시아까지 올 군대는 없소."
	},
	{
	L"알카나야왕 미솔렌:제넬루님의 마법으로",
	L"드레곤과 강력한 글리펀조종사 부대는",
	L"내 손 안에 있소."
	},
	{
	L"에드윈왕 마레암:왕이여! 바위인간의",
	L"힘이 아니라도 바르시아는 무사하리라",
	L"생각하오만⋯."
	},
	{
	L"제넬루:시끄럽소! 전쟁으로 귀중한 생",
	L"명이 죽는 것이 안타까와 자닐의 힘을",
	L"빌어 바위인간을 만든 것이오."
	},
	{
	L"당신들마저도 배신할 생각이오?",
	L"",
	L""
	},
	{
	L"세버트왕 사크:에드윈은 남쪽영향을 받",
	L"기 쉽소. 바르시아왕이여! 힘이 될만한",
	L"자를 에드윈에 보내는 것이 좋겠소."
	},
	{
	L"바람장군 스리후트:그렇다면 내가 가겠",
	L"소!",
	L""
	},
	{
	L"흙의 장군 맥가이어:라이오스님이 허락",
	L"하신다면 난 리스레이성에 있겠소.",
	L""
	},
	{
	L"제넬루:다 알고 있겠지만 내가 신뢰하",
	L"는 부하요. 힘이 되게 해 주시오.",
	L""
	},
	{
	L"지난날 불행히도 모로시아왕과 벨더왕이",
	L"잇달아 죽었소. 참혹한 일이오. 후계자가",
	L"결정될 때까지 오그와 몰드레드가 지키"
	},
	{
	L"게 하시오."
	},
	{
	L"물장군 오그 : 그럼, 저는 모로시아로⋯.",
	L""
	},
	{
	L"불장군 몰드레도:벨더성은 내게 맡기시",
	L"오."
	}
};