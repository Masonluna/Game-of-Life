#pragma once
#include "Cell.h"
#include <vector>


namespace Life {

	class World
	{
	public:
		World(unsigned int width, unsigned int height);
		~World() {}


		const std::vector<Cell>& GetGrid() const { return m_Grid; }
		std::vector<Cell>& GetGrid() { return m_Grid; }
		const Cell& GetCellAt(unsigned int xPos, unsigned int yPos) const { return m_Grid[yPos * m_Width + xPos]; }
		Cell& GetCellAt(unsigned int xPos, unsigned int yPos) { return m_Grid[yPos * m_Width + xPos]; }

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		void Update();

	private:
		bool CheckForLife(unsigned int xPos, unsigned int yPos);
		unsigned int m_Width;
		unsigned int m_Height;

		std::vector<Cell> m_Grid;
		std::vector<Cell> m_Backbuffer;
	};

}