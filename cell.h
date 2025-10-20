#pragma once

struct Cell
{
	bool reveal;
	bool mine;
	bool flag;
	int mine_adj;
};