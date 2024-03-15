#include "pch.h"
#include "CAStarHandler.h"
#include "CMap.h"
#include "CUnit.h"

CAStarHandler::CAStarHandler()
{
	int tcostX[4] = { 0, -1, 1, 0 };
	int tcostY[4] = { -1, 0, 0, 1 };

	costX = tcostX;
	costY = tcostY;

	for (int i = 0; i < 70; i++) {
		for (int j = 0; j < 70; j++) {
			openMap[i][j] = INT32_MAX; //가중치 최대
		}
	}
}

CAStarHandler::~CAStarHandler()
{
}

int CAStarHandler::GetManhattonDist(int curX, int curY, int destY, int destX)
{
	return (destX - curX) + (destY - curY);
}

void CAStarHandler::AStar(int x, int y, int destX, int destY, CMap* cmap)
{
	while (pq.size() > 0) {
		NODE* node = pq.top(); //우선순위 큐에서 pop, 가중치 제일 작은것
		pq.pop();

		if (closedMap[node->x][node->y]) continue; //이미 방문한 노드면 스킵

		closedMap[node->x][node->y] = TRUE; //현재 노드 방문처리

		if (node->x == destX && node->y == destY) break;

		for (int i = 0; i < 4; i++) {
			int nextX = node->x + costX[i];
			int nextY = node->y + costY[i];

			if (nextX < 0 || nextX > 70 || nextY < 0 || nextY > 70)
				continue; //맵 밖 나가면 스킵
			if (cmap->tileMap[nextX][nextY].unit)
				continue; //방문하려는 곳에 유닛이 있다면 스킵
			if (closedMap[nextX][nextY])
				continue; //이미 방문한 노드면 스킵

			int tempG = node->g + costX[i] + costY[i];
			int tempH = abs(destX - nextX) + abs(destY - nextY); //G, H value 계산

			if (openMap[nextX][nextX] < tempG) continue; //가중치 비교

			openMap[nextX][nextY] = tempG + tempH; //가중치 저장

			NODE* newNode = new NODE();
			newNode->g = tempG;
			newNode->x = nextX;
			newNode->y = nextY;
			pq.push(newNode); //우선순위 큐에 추가

			parent[nextX][nextY].x = node->x;
			parent[nextX][nextY].y = node->y;
		}
	}
}

