#pragma once

struct NODE {
	int x;
	int y;
	int g;
};

class CAStarHandler
{
public:
	CAStarHandler();
	~CAStarHandler();
	int GetManhattonDist(int curX, int curY, int destX, int destY);
	void AStar(int x, int y, int destX, int destY, CMap* cmap);

public:
	int* costX;
	int* costY;

	std::vector<NODE> path;

	//AStar variables

	int openMap[70][70];
	bool closedMap[70][70];

	NODE parent[70][70];

	std::priority_queue<NODE*> pq;
	std::vector<NODE> openList, closedList;
};

