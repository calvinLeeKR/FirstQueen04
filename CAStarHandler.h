#pragma once

#define mapX 70
#define mapY 70

struct NODE {
	int x;
	int y;
	int g;
	int f;
};

struct NODE_COMPARE {
	bool operator()(const NODE& n1, const NODE& n2) {
		return n1.f > n2.f;
	}
};

class CMap;

class CAStarHandler
{
public:
	CAStarHandler();
	~CAStarHandler();
	int GetManhattonDist(int curX, int curY, int destX, int destY);
	void RunAStar(int x, int y, int destX, int destY, CMap* cmap);

public:

	std::stack<NODE> path;

	//AStar variables

	int openMap[mapX][mapY];
	bool closedMap[mapX][mapY];

	NODE parent[mapX][mapY];

	std::priority_queue<NODE, std::vector<NODE>, NODE_COMPARE> pq;
	std::vector<NODE> openList, closedList;
};

