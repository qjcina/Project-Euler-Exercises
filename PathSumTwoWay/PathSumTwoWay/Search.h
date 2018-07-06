#pragma once
#include <vector>

using namespace std;

class Search
{
	enum direction { top, right, bottom, left, none };
	pair<unsigned, unsigned> pos;
	unsigned get(pair<unsigned, unsigned> pos, int x, int y);
	direction xyToDir(int x, int y);
	direction opposite(direction dir);
	pair<unsigned, unsigned> move(pair<unsigned, unsigned> pos, direction dir);
public:
	unsigned long long start();
	Search();
	~Search();
};

