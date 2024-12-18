#include "World.h"
#include <iostream>

Life::World::World(unsigned int width, unsigned int height)
{
	for (int i = 0; i < width; i++) {
		std::vector<Cell> column;
		for (int j = 0; j < height; j++) {
			column.emplace_back(Cell());
		}
		m_Grid.emplace_back(column);
	}
}
