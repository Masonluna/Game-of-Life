#include "CellView.h"
#include "Scribble2D/Core/Log.h"

Life::CellView::CellView(int gridX, int gridY, float x, float y, float width, float height, float rotation, glm::vec3& color, Cell& model)
	: m_GridX(gridX), m_GridY(gridY), Scribble::Object(glm::vec2(x, y), glm::vec2(width, height), rotation, color), m_Model(model)
{

}

void Life::CellView::Draw(Scribble::Renderer& renderer)
{

	if (m_Model.isAlive()) {
		renderer.DrawQuad(m_Position, m_Size, m_Rotation, m_Color);
	}
}
