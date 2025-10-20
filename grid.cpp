#include "grid.h"
#include <corecrt_malloc.h>
#include <cstdlib>
#include <iostream>

void AskDifficulty(Grid* grid)
{
	int difficulty;
	std::cout << "choississez votre difficulte " <<std::endl;
	std::cout << "1 : Mode Facile : 9x9" << std::endl;
	std::cout << "2 : Mode Normal : 16x16" << std::endl;
	std::cout << "3 : Mode Difficile : 30x16" << std::endl;
	std::cout << "4 : Mode Personnalise" << std::endl;
	std::cin >> difficulty;
	switch (difficulty)
	{
	case(1):
		grid->line = 9;
		grid->column = 9;
		break;
	case(2):
		grid->line = 16;
		grid->column = 16;
		break;
	case(3):
		grid->line = 30;
		grid->column = 16;
		break;
	case(4):
		std::cout << "Nombre de Lignes (entre 1 et 48)" << std::endl;
		std::cin >> grid->line;
		std::cout << "Nombre de Lignes (entre 1 et 48)" << std::endl;
		std::cin >> grid->column;
		break;
	default:
		break;
	}
}

void CreateTab(Grid* grid)
{
	AskDifficulty(grid);

	grid->totalmine = grid->column * grid->line / 0.15f;
	grid->celltab = (Cell**)malloc(sizeof(Cell) * grid->column);
	if (grid->celltab == nullptr) exit(1);
	for (int i = 0; i < grid->line; i++)
	{
		grid->celltab[i] = (Cell*)malloc(grid->line * sizeof(Cell));
		if (grid->celltab[i] == nullptr) exit(1);
		for (int j = 0; j < grid->line; j++)
		{
			Cell Ncell;
			Ncell.reveal = false;
			Ncell.flag = false;
			Ncell.mine = false;
			Ncell.mine_adj = 9;
			grid->celltab[i][j] = Ncell;
		}
	}
}

void DisplayTab(Grid* grid)
{
	system("cls");
	std::cout << "    ";
	for (int i = 0; i < grid->column; i++)
	{
		std::cout << i << "   ";
	}
	std::cout << std::endl;
	std::cout << "  ";
	for (int i = 0; i < grid->column; i++)
	{
		std::cout << "+---";

	}
	std::cout << "+";
	std::cout << std::endl;
	for (int i = 0; i < grid->line; i++)
	{
		std::cout << i;
		if (i < 10)std::cout << " ";
		std::cout << "";
		std::cout << "| ";
		for (int j = 0; j < grid->column ; j++)
		{
			if (!grid->celltab[i][j].reveal)
			{
				std::cout << "6";
			}
			std::cout << " | ";
		}
		std::cout << std::endl;
		std::cout << "  ";
		for (int k = 0; k < grid->column;k++)
		{
			std::cout << "+---";

		}
		std::cout << "+";
		std::cout << std::endl;
	}
}

int MineAround(Grid* grid, int i,int j)
{
	int 
}