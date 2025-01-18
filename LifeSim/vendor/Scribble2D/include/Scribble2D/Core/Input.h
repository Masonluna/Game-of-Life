#pragma once
#include "Scribble2D/Core/KeyCode.h"
#include "Scribble2D/Core/MouseCode.h"

#include <glm-1.0.1/glm/glm.hpp>

namespace Scribble {

	class Input
	{
	public:

		static bool IsKeyPressed(KeyCode key);
		static bool IsMouseButtonPressed(MouseCode button);

		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}

