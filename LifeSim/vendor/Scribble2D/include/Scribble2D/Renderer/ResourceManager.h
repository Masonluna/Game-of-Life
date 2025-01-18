#pragma once

#include "Texture.h"
#include "Shader.h"

#include <string>
#include <unordered_map>

namespace Scribble {


	class ResourceManager
	{
	public:


		static void InitializeShaders();
		static void InitializeTextures();

		static Shader LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name);
		static Shader GetShader(std::string name);

		static Texture2D LoadTexture(const char* file, bool alpha, std::string name);
		static Texture2D GetTexture(std::string name);

		static void Clear();
	private:
		ResourceManager() {}
		static std::map<std::string, Shader> s_Shaders;
		static std::map<std::string, Texture2D> s_Textures;
		static Shader LoadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFIle = nullptr);
		static Texture2D LoadTextureFromFile(const char* file, bool alpha);
	};


}