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
			openMap[i][j] = 1000; //����ġ ������ ä��
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
	pq.push({x, y, 0, GetManhattonDist(x, y, destX, destY) }); //������ ��� �߰�

	while (pq.size() > 0) {
		NODE node = pq.top(); //�켱���� ť���� pop, ����ġ ���� ������
		pq.pop();

		if (closedMap[node.x][node.y]) continue; //�̹� �湮�� ���� ��ŵ
		closedMap[node.x][node.y] = TRUE; //���� ��� �湮ó��

		if (node.x == destX && node.y == destY) {
			break; //�������� ��
		}

		for (int i = 0; i < 4; i++) {
			int nextX = node.x + costX[i];
			int nextY = node.y + costY[i];

			if (nextX < 0 || nextX > mapX || nextY < 0 || nextY > mapY)
				continue; //�� �� ������ ��ŵ
			if (cmap->tileMap[nextX][nextY].unit)
				if (nextX == destX && nextY == destY) {
					parent[nextX][nextY].x = node.x;
					parent[nextX][nextY].y = node.y;
					break;
				}
				continue; //�湮�Ϸ��� ���� ������ �ִٸ� ��ŵ
			if (closedMap[nextX][nextY])
				continue; //�̹� �湮�� ���� ��ŵ

			int tempG = node.g + 1; //������ ��� ���
			int tempH = GetManhattonDist(nextX, nextY, destX, destY); //G, H value ���

			if (openMap[nextX][nextY] < tempG + tempH) continue; //����ġ ��

			openMap[nextX][nextY] = tempG + tempH; //����ġ ����

			pq.push({nextX, nextY, tempG, tempG + tempH}); //�켱���� ť�� �߰�

			parent[nextX][nextY].x = node.x;
			parent[nextX][nextY].y = node.y;
		}
	}

	//if (pq.size() == 0) return; //�� ��ã���� ����

	NODE traversal = { destX, destY, 0, 0 };
	path.push(traversal);
	while (traversal.x != x && traversal.y != y) {
		traversal = parent[traversal.x][traversal.y];
		path.push({ traversal.x, traversal.y, 0, 0 });
	}
}

