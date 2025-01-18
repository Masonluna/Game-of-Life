#pragma once
#include "Scribble2D/Core/Application.h"
#include "VertexArray.h"
#include "Shader.h"
#include "glad/glad.h"

#include <map>

namespace Scribble {


	struct Character
	{
		unsigned int TextureID;
		glm::ivec2 Size;
		glm::ivec2 Bearing;
		unsigned int Advance;
	};

	class TextRenderer
	{
	public:
		TextRenderer() = default;
		void Init();

		void LoadFont(std::string font, unsigned int fontSize);

		void DrawString(const std::string& text, glm::vec2& pos, float scale, const glm::vec3& color = glm::vec3(1.0f));
	private:
		Shader m_TextShader;
		VertexArray m_VertexArray;
		unsigned int m_TextVBO;
		std::map<char, Character> m_Characters;

	};
}