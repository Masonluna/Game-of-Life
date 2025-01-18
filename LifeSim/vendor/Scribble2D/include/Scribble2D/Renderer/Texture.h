#pragma once
#include "glm-1.0.1/glm/glm.hpp"

#include <glad/glad.h>


namespace Scribble {

	class Texture2D
	{
	public:
		uint32_t m_TextureID = 0;

		uint32_t m_Width;
		uint32_t m_Height;
		uint32_t m_InternalFormat;
		uint32_t m_ImageFormat;

		uint32_t m_WrapS;
		uint32_t m_WrapT;

		uint32_t m_FilterMin;
		uint32_t m_FilterMax;

		Texture2D();

		void Generate(uint32_t width, uint32_t height, unsigned char* data);
		void Bind() const { glBindTexture(GL_TEXTURE_2D, m_TextureID); }
	};

}