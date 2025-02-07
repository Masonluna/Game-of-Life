#include "Cell.h"
#include "Scribble2D/Core/Log.h"

Life::Cell::Cell(float x, float y, float width, float height, float rotation, glm::vec3& color, bool isAlive)
	: Scribble::Object(glm::vec2(x, y), glm::vec2(width, height), rotation, color), m_IsAlive(isAlive)
{

}

void Life::Cell::Draw(Scribble::Renderer& renderer) const
{
	if (m_IsAlive) {
		renderer.DrawQuad(m_Position, m_Size.x, m_Size.y, m_Rotation, m_Color);
	}
}
