#pragma once
#include "GLFW/glfw3.h"


namespace Scribble {

	class RenderContext
	{
	public:
		RenderContext(GLFWwindow* window);

		void Init();
		void SwapBuffers();

	private:
		GLFWwindow* m_Window;
	};

}