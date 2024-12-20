#include "Cell.h"
#include "Scribble2D/Core/Log.h"

Life::Cell::Cell(float x, float y, float width, float height, float rotation, glm::vec3& color)
	: Scribble::Object(glm::vec2(x, y), glm::vec2(width, height), rotation, color), m_IsAlive(false)
{

}

void Life::Cell::Draw(Scribble::Renderer& renderer) const
{

	if (m_IsAlive) {
		renderer.DrawQuad(m_Position, m_Size, m_Rotation, m_Color);
	}
}