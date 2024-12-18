#pragma once
#include "Cell.h"
#include <vector>


namespace Life {

	class World
	{
	public:
		World(unsigned int width, unsigned int height);
		~World() {}

		const std::vector<std::vector<Cell>> GetGrid() const { return m_Grid; }
		const Cell GetCellAt(int xPos, int yPos) { return m_Grid[xPos][yPos]; }
	private:
		std::vector<std::vector<Cell>> m_Grid;
	};

}