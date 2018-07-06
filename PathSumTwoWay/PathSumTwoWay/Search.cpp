#include "stdafx.h"
#include "Search.h"

#include "Map.h"

unsigned Search::get(pair<unsigned, unsigned> pos, int x, int y)
{
	if (pos.first + x < 0 || pos.first + x >= 80
		|| pos.second + y < 0 || pos.second + y >= 80)
		return 40000000;
	return map[pos.first][pos.second];
}

Search::direction Search::xyToDir(int x, int y)
{
	if (x == 1)
		return right;
	if (x == -1)
		return left;
	if (y == 1)
		return top;
	if (y == -1)
		return bottom;
}

Search::direction Search::opposite(direction dir)
{
	if (dir == right)
		return left;
	if (dir == left)
		return right;
	if (dir == top)
		return bottom;
	if (dir == bottom)
		return top;
	return none;
}

pair<unsigned, unsigned> Search::move(pair<unsigned, unsigned> pos, direction dir)
{
	switch (dir)
	{
	case Search::top:
		return make_pair(pos.first, pos.second + 1);
	case Search::right:
		return make_pair(pos.first + 1, pos.second);
	case Search::bottom:
		return make_pair(pos.first, pos.second - 1);
	case Search::left:
		return make_pair(pos.first - 1, pos.second);
	case Search::none:
	default:
		return make_pair(pos.first, pos.second);
	}
}

unsigned long long Search::start()
{
	pos = make_pair(0, 0);
	unsigned long long sum = 0;
	direction moved = none;
	while (pos.first != 79 && pos.second != 79) {
		int min = 40000000;
		direction moveDir;
		for (int x = -1; x <= 1; x++)
			for (int y = -1; y <= 1; y++)
				if ((x != 0 && y == 0) || (x == 0 && y != 0))
				{
					auto offsetValue = get(pos, x, y);
					direction currentDir = xyToDir(x, y);
					if (min > offsetValue && currentDir != opposite(moved)) {
						min = offsetValue;
						moveDir = currentDir;
					}
				}

		sum += get(pos, 0, 0);
		moved = moveDir;
		pos = move(pos, moveDir);
	}
	return sum;
}

Search::Search()
{
	
}


Search::~Search()
{
}
