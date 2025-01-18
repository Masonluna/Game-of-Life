#pragma once
#include "glad/glad.h"

namespace Scribble {

	class IndexBuffer
	{
	public:
		IndexBuffer() = default;
		IndexBuffer(uint32_t* indices, uint32_t count);

		~IndexBuffer()
		{
			if (m_RendererID != 0)
				glDeleteBuffers(1, &m_RendererID);
		}

		void Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID); }
		void Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

		inline unsigned int GetID() const { return m_RendererID; }

		const uint32_t GetCount() const { return m_Count; }

	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	};
}