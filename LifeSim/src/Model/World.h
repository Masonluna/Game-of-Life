#pragma once
#include "Cell.h"
#include <memory>
#include <vector>


namespace Life {

	class World
	{
	public:
		World(unsigned int width, unsigned int height);
		~World() {}


		const std::shared_ptr<std::vector<Cell>> GetGrid() const { return m_Grid; }
		std::shared_ptr<std::vector<Cell>> GetGrid() { return m_Grid; }
		const Cell& GetCellAt(unsigned int xPos, unsigned int yPos) const { return m_Grid->at(yPos * m_Width + xPos); }
		Cell& GetCellAt(unsigned int xPos, unsigned int yPos) { return m_Grid->at(yPos * m_Width + xPos); }
		void SetCellAt(unsigned int x, unsigned int y, Cell cell) 
		{ 
			m_Grid->at(y * m_Width + x) = cell; 
			m_Backbuffer->at(y * m_Width + x) = cell;
		}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		void Update();
		void InitCell(int gridX, int gridY, float posX, float posY, float width, float height, float rotation, glm::vec3& color);
	private:
		bool CheckForLife(unsigned int xPos, unsigned int yPos);
		unsigned int m_Width;

		std::shared_ptr<std::vector<Cell>> m_Grid;
		std::shared_ptr<std::vector<Cell>> m_Backbuffer;
		unsigned int m_Height;
	};

}