#pragma once

#include <glad/glad.h> // include glad to get all the required OpenGL headers

#include "debug.hpp"
#include "IResource.hpp"
#include "basicmath.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>

namespace Resources {
	class Shader : public IResource
	{
	public:
		Shader() {};
		~Shader();

		void loadResource(fs::path shaderName) override;

		bool setVertexS(fs::path filePath, bool autoLink = false);
		bool setFragmentS(fs::path filePath, bool autoLink = false);
		bool linkShaders();

		void use();

		void setBool(const string& name, bool value) const;
		void setInt(const string& name, int value) const;
		void setFloat(const string& name, float value) const;
		void setvec2(const std::string& name, const vec2& value) const;
		void setvec2(const std::string& name, float x, float y) const;
		void setvec3(const std::string& name, const vec3& value) const;
		void setvec3(const std::string& name, float x, float y, float z) const;
		void setvec4(const std::string& name, const mat4& value) const;
		void setvec4(const std::string& name, float x, float y, float z, float w) const;
		void setmat3(const std::string& name, const mat3& mat) const;
		void setmat4(const std::string& name, const mat4& mat) const;

	private:
		unsigned int vertex = 0, fragment = 0;

		bool checkCompileErrors(unsigned int& shader, string type);
	};
}