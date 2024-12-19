#pragma once
#include "Cell.h"
#include <vector>


namespace Life {

	class World
	{
	public:
		World(unsigned int width, unsigned int height);
		~World() {}


		const std::vector<Cell> GetGrid() const { return m_Grid; }
		const Cell& GetCellAt(int xPos, int yPos) const { return m_Grid[yPos * m_Width + xPos]; }
		Cell& GetCellAt(int xPos, int yPos) { return m_Grid[yPos * m_Width + xPos]; }

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

	private:
		unsigned int m_Width;
		unsigned int m_Height;

		void InitLiveCells(int x[], int y[], int numCells);
		std::vector<Cell> m_Grid;
	};

}