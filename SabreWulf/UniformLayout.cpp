#include "UniformLayout.h"

UniformLayout::UniformLayout()
{
	m_Count = 0;
}

void UniformLayout::addShaderUniform(std::string name, ShaderUniformType type, int count)
{
	m_Count++;

	for(int i = 0; i < count; i++)
		m_Uniforms.emplace_back(-1, name, type);
}

void UniformLayout::locateUniforms(GLint programID)
{
	for (ShaderUniform uniform : m_Uniforms) {
		uniform.id = glGetUniformLocation(programID, uniform.name.c_str());
		if (uniform.id == -1)
			std::cerr << "Could not locate uniform: " << uniform.name << std::endl;
	}
}

GLint UniformLayout::getUniformLocation(std::string name)
{
	for (ShaderUniform uniform : m_Uniforms) {
		if (uniform.name == name)
			return uniform.id;
	}

	//No uniform with name name registered
	std::cerr << "No uniform with name: " << name << " registered" << std::endl;
	return -2;
}