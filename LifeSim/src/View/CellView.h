#pragma once
#include "Model/Cell.h"
#include "Scribble2D/Scene/Object.h"
#include "Scribble2D/Renderer/Renderer.h"


namespace Life {

	class CellView : public Scribble::Object
	{
	public:
		CellView(int gridX, int gridY, float x, float y, float width, float height, float rotation, glm::vec3& color, Cell& model);

		~CellView() {}

		int GetGridX() const { return m_GridX; }
		int GetGridY() const { return m_GridY; }

		void Draw(Scribble::Renderer& renderer);

	private:
		Cell& m_Model;
		int m_GridX;
		int m_GridY;
	};

}