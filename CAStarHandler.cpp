#include "pch.h"
#include "CAStarHandler.h"
#include "CMap.h"
#include "CUnit.h"

CAStarHandler::CAStarHandler()
{
	for (int i = 0; i < mapX; i++) {
		for (int j = 0; j < mapY; j++) {
			openMap[i][j] = 1000; //가중치 높은값 채움
			closedMap[i][j] = FALSE;
			parent[i][j] = { 0, 0, 0, 0 };//initialize
		}
	}
}

CAStarHandler::~CAStarHandler()
{
}

int CAStarHandler::GetManhattonDist(int curX, int curY, int destX, int destY)
{
	return abs(destX - curX) + abs(destY - curY);
}

void CAStarHandler::RunAStar(int x, int y, int destX, int destY, CMap* cmap, CUnit* cunit)
{
	int costX[4] = { 0, -1, 1, 0 };
	int costY[4] = { -1, 0, 0, 1 };

	int finishedX = 0;
	int finishedY = 0; //최종 종결점 저장

	NODE* newNode = new NODE{ x, y, 0, GetManhattonDist(x, y, destX, destY) };

	pq.push(newNode); //시작점 노드 추가

	while (!pq.empty()) {
		NODE* node = pq.top(); //우선순위 큐에서 pop, 가중치 제일 작은것
		pq.pop();

		if (closedMap[node->x][node->y]) continue; //이미 방문한 노드면 스킵

		//충돌처리
		bool isUnitExist = false;
		for (int i = 0; i < 2; i++) { //unit size instead of 2
			for (int j = 0; j < 2; j++) {
				if (cmap->tileMap[node->x + i][node->y + j].unit
					&& cmap->tileMap[node->x + i][node->y + j].unit != cunit) {
					isUnitExist = true; //유닛이 있으면 있다체크
				}
			}
		}

		//충돌도착처리
		bool isUnitExistAndFinished = false;
		for (int i = -1; i < 3; i++) {
			for (int j = -1; j < 3; j++) {
				if (node->x + i == destX && node->y + j == destY) 
					isUnitExistAndFinished = true;
			}
		}

		if (isUnitExist) {
			if (isUnitExistAndFinished) {
				finishedX = node->x;
				finishedY = node->y; //충돌처리됐으면 종결점과 다르므로 저장
				break;
			} //도착점에 유닛이 있는 경우 끝
			continue; //방문하려는 곳에 유닛이 있다면 스킵 (자신제외)
		}

		closedMap[node->x][node->y] = true; //현재 노드 방문처리

		if (node->x == destX && node->y == destY) {
			break; //목적지면 끝
		}

		for (int i = 0; i < 4; i++) {
			int nextX = node->x + costX[i];
			int nextY = node->y + costY[i];

			if (nextX < 0 || nextX > mapX || nextY < 0 || nextY > mapY)
				continue; //맵 밖 나가면 스킵
			if (closedMap[nextX][nextY])
				continue; //이미 방문한 노드면 스킵

			int tempG = node->g + 1; //지나온 비용 계산
			int tempH = GetManhattonDist(nextX, nextY, destX, destY); //G, H value 계산
			int tempF = tempG + tempH;

			if (openMap[nextX][nextY] < tempF) continue; //가중치 비교

			openMap[nextX][nextY] = tempF; //가중치 저장

			NODE* tempNode = new NODE{ nextX, nextY, tempG, tempF };

			pq.push(tempNode); //우선순위 큐에 추가

			parent[nextX][nextY].x = node->x;
			parent[nextX][nextY].y = node->y;
		}
	}

	if (finishedX == 0) finishedX = destX;
	if (finishedY == 0) finishedY = destY;

	NODE* traversal = new NODE{ finishedX, finishedY, 0, 0 };
	path.push(traversal);
	while (traversal->x != x || traversal->y != y) {
		int tempTX = parent[traversal->x][traversal->y].x;
		int tempTY = parent[traversal->x][traversal->y].y;
		traversal->x = tempTX;
		traversal->y = tempTY;
		path.push(new NODE{ tempTX, tempTY, 0, 0 });
	}
	traversal->x = finishedX;
	traversal->y = finishedY;
}

