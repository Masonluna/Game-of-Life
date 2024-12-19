#include "World.h"
#include <iostream>

Life::World::World(unsigned int width, unsigned int height)
	: m_Width(width), m_Height(height), m_Grid(width * height)
{
}

void Life::World::InitLiveCells(int x[], int y[], int numCells)
{
	for (int i = 0; i < numCells; i++) {
		if (x[i] > m_Width || x[i] < 0) {
			//SCB_ERROR("Invalid X Position! item #{0}", i);
			std::cerr << "INVALID X";
			continue;
		}
		if (y[i] > m_Height || y[i] < 0) {
			//SCB_ERROR("Invalid Y Position! Item #{0}", i);
			std::cerr << "INVALID Y";
			continue;
		}

		Cell& cell = GetCellAt(x[i], y[i]);
		cell.setAlive(true);
	}
}
