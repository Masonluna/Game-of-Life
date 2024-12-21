#pragma once
#include "Scribble2D/Scene/Object.h"
#include "Scribble2D/Renderer/Renderer.h"

namespace Life {

	class Cell : public Scribble::Object
	{
	public:

		Cell() = default;
		Cell(float x, float y, float width, float height, float rotation, glm::vec3& color, bool isAlive = false);

		~Cell() {}
		
		void Draw(Scribble::Renderer& renderer) const;
		void SetAlive(bool val) { m_IsAlive = val; }
		inline const bool IsAlive() const { return m_IsAlive; }

	private:
		bool m_IsAlive = false;
	};

}