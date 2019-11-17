#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <string>

enum ShaderUniformType {
	Int,
	Float,
	Vec3,
	Vec4,
	Mat4
};

struct ShaderUniform {
	ShaderUniform(GLint id, std::string name, ShaderUniformType type)
	{
		this->id;
		this->name = name;
		this->type = type;
	}
	GLint id;
	std::string name;
	ShaderUniformType type;
};

class UniformLayout {
public:
	UniformLayout();

	void addShaderUniform(std::string name, ShaderUniformType type, int count);
	void locateUniforms(GLint programID);
	GLint getUniformLocation(std::string name);

private:
	std::vector<ShaderUniform> m_Uniforms;
	int m_Count;
};