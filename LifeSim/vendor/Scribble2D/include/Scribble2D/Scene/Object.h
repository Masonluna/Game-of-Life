#pragma once

#include "glm-1.0.1/glm/glm.hpp"

namespace Scribble {

	class Object
	{
	public:
		Object() {}
		//Object(Texture2D texture);
		//Object(glm::vec4& color);
		Object(glm::vec2& position, glm::vec2& size, float rotation, glm::vec3& color)
			: m_Position(position), m_Size(size), m_Rotation(rotation), m_Color(color)
		{

		}
		//Object(glm::vec2& position, glm::vec2& size, float rotation, Texture2D texture);

		const glm::vec2& GetPosition() const { return m_Position; }
		const glm::vec2& GetSize() const { return m_Size; }
		const float GetRotation() const { return m_Rotation; }
		const glm::vec3& GetColor() const { return m_Color; }

	protected:
		glm::vec2 m_Position;
		glm::vec2 m_Size;
		float m_Rotation;


		// Texture2D m_Texture;
		glm::vec3 m_Color;
	};

}