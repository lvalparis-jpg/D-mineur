#pragma once
#include "cell.h"

struct Grid
{
	int line;
	int column;
	int totalmine;
	Cell** celltab;
};

void AskDifficulty(Grid* grid);
void CreateTab(Grid* grid);
void DisplayTab(Grid* grid);
int MineAround(Grid* grid,int i,int j);

