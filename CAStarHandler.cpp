#include "pch.h"
#include "CAStarHandler.h"
#include "CMap.h"
#include "CUnit.h"

int costX[4] = { 0, -1, 1, 0 };
int costY[4] = { -1, 0, 0, 1 };

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

void CAStarHandler::RunAStar(int x, int y, int destX, int destY, CMap* cmap)
{
	pq.push({x, y, 0, GetManhattonDist(x, y, destX, destY) }); //시작점 노드 추가

	while (pq.size() > 0) {
		NODE node = pq.top(); //우선순위 큐에서 pop, 가중치 제일 작은것
		pq.pop();

		if (closedMap[node.x][node.y]) continue; //이미 방문한 노드면 스킵
		closedMap[node.x][node.y] = TRUE; //현재 노드 방문처리

		if (node.x == destX && node.y == destY) {
			break; //목적지면 끝
		}

		for (int i = 0; i < 4; i++) {
			int nextX = node.x + costX[i];
			int nextY = node.y + costY[i];

			if (nextX < 0 || nextX > mapX || nextY < 0 || nextY > mapY)
				continue; //맵 밖 나가면 스킵
			if (cmap->tileMap[nextX][nextY].unit)
				if (nextX == destX && nextY == destY) {
					parent[nextX][nextY].x = node.x;
					parent[nextX][nextY].y = node.y;
					break;
				}
				continue; //방문하려는 곳에 유닛이 있다면 스킵
			if (closedMap[nextX][nextY])
				continue; //이미 방문한 노드면 스킵

			int tempG = node.g + 1; //지나온 비용 계산
			int tempH = GetManhattonDist(nextX, nextY, destX, destY); //G, H value 계산

			if (openMap[nextX][nextY] < tempG + tempH) continue; //가중치 비교

			openMap[nextX][nextY] = tempG + tempH; //가중치 저장

			pq.push({nextX, nextY, tempG, tempG + tempH}); //우선순위 큐에 추가

			parent[nextX][nextY].x = node.x;
			parent[nextX][nextY].y = node.y;
		}
	}

	//if (pq.size() == 0) return; //길 못찾으면 종료

	NODE traversal = { destX, destY, 0, 0 };
	path.push(traversal);
	while (traversal.x != x && traversal.y != y) {
		traversal = parent[traversal.x][traversal.y];
		path.push({ traversal.x, traversal.y, 0, 0 });
	}
}

