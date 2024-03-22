#include "pch.h"
#include "CAStarHandler.h"
#include "CMap.h"
#include "CUnit.h"

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

void CAStarHandler::RunAStar(int x, int y, int destX, int destY, CMap* cmap, CUnit* cunit)
{
	int costX[4] = { 0, -1, 1, 0 };
	int costY[4] = { -1, 0, 0, 1 };

	int finishedX = 0;
	int finishedY = 0; //���� ������ ����

	NODE* newNode = new NODE{ x, y, 0, GetManhattonDist(x, y, destX, destY) };

	pq.push(newNode); //������ ��� �߰�

	while (!pq.empty()) {
		NODE* node = pq.top(); //�켱���� ť���� pop, ����ġ ���� ������
		pq.pop();

		if (closedMap[node->x][node->y]) continue; //�̹� �湮�� ���� ��ŵ

		//�浹ó��
		bool isUnitExist = false;
		for (int i = 0; i < 2; i++) { //unit size instead of 2
			for (int j = 0; j < 2; j++) {
				if (cmap->tileMap[node->x + i][node->y + j].unit
					&& cmap->tileMap[node->x + i][node->y + j].unit != cunit) {
					isUnitExist = true; //������ ������ �ִ�üũ
				}
			}
		}

		//�浹����ó��
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
				finishedY = node->y; //�浹ó�������� �������� �ٸ��Ƿ� ����
				break;
			} //�������� ������ �ִ� ��� ��
			continue; //�湮�Ϸ��� ���� ������ �ִٸ� ��ŵ (�ڽ�����)
		}

		closedMap[node->x][node->y] = true; //���� ��� �湮ó��

		if (node->x == destX && node->y == destY) {
			break; //�������� ��
		}

		for (int i = 0; i < 4; i++) {
			int nextX = node->x + costX[i];
			int nextY = node->y + costY[i];

			if (nextX < 0 || nextX > mapX || nextY < 0 || nextY > mapY)
				continue; //�� �� ������ ��ŵ
			if (closedMap[nextX][nextY])
				continue; //�̹� �湮�� ���� ��ŵ

			int tempG = node->g + 1; //������ ��� ���
			int tempH = GetManhattonDist(nextX, nextY, destX, destY); //G, H value ���
			int tempF = tempG + tempH;

			if (openMap[nextX][nextY] < tempF) continue; //����ġ ��

			openMap[nextX][nextY] = tempF; //����ġ ����

			NODE* tempNode = new NODE{ nextX, nextY, tempG, tempF };

			pq.push(tempNode); //�켱���� ť�� �߰�

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

