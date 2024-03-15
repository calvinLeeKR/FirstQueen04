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
			openMap[i][j] = INT32_MAX; //����ġ �ִ�
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
		NODE* node = pq.top(); //�켱���� ť���� pop, ����ġ ���� ������
		pq.pop();

		if (closedMap[node->x][node->y]) continue; //�̹� �湮�� ���� ��ŵ

		closedMap[node->x][node->y] = TRUE; //���� ��� �湮ó��

		if (node->x == destX && node->y == destY) break;

		for (int i = 0; i < 4; i++) {
			int nextX = node->x + costX[i];
			int nextY = node->y + costY[i];

			if (nextX < 0 || nextX > 70 || nextY < 0 || nextY > 70)
				continue; //�� �� ������ ��ŵ
			if (cmap->tileMap[nextX][nextY].unit)
				continue; //�湮�Ϸ��� ���� ������ �ִٸ� ��ŵ
			if (closedMap[nextX][nextY])
				continue; //�̹� �湮�� ���� ��ŵ

			int tempG = node->g + costX[i] + costY[i];
			int tempH = abs(destX - nextX) + abs(destY - nextY); //G, H value ���

			if (openMap[nextX][nextX] < tempG) continue; //����ġ ��

			openMap[nextX][nextY] = tempG + tempH; //����ġ ����

			NODE* newNode = new NODE();
			newNode->g = tempG;
			newNode->x = nextX;
			newNode->y = nextY;
			pq.push(newNode); //�켱���� ť�� �߰�

			parent[nextX][nextY].x = node->x;
			parent[nextX][nextY].y = node->y;
		}
	}
}

