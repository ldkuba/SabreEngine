#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <fstream>

#include "UniformLayout.h"

class ShaderProgram {
public:
	ShaderProgram();

	void bind();
	void unbind();

	void addUniform(std::string name, ShaderUniformType type, int count);
	void locateUniforms();

	void loadShader(std::string filename);

private:
	GLint createShader(std::string vertexShader, std::string fragmentShader);
	GLint compileShader(std::string source, GLint type);

	GLuint m_ID;
	UniformLayout m_Layout;
};