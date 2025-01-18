#pragma once

#include "glm-1.0.1/glm/gtc/type_ptr.hpp"
#include "glad/glad.h"
#include <string>

namespace Scribble {

	class Shader
	{
	public:
		uint32_t m_ShaderID = 0;
		Shader() {}
		~Shader() = default;

		void Bind() const { glUseProgram(m_ShaderID); }
		void Unbind() const { glUseProgram(0); }

		void SetInt(const std::string& name, int value);
		void SetIntArray(const std::string& name, int* values, uint32_t count);
		void SetFloat(const std::string& name, float value);
		void SetFloat2(const std::string& name, const glm::vec2& value);
		void SetFloat3(const std::string& name, const glm::vec3& value);
		void SetFloat4(const std::string& name, const glm::vec4& value);
		void SetMat4(const std::string& name, const glm::mat4& value);


		void Compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource = nullptr);

	private:
		bool checkCompileErrors(uint32_t object, std::string type);
	};

}

