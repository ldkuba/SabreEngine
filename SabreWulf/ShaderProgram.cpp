#include "ShaderProgram.h"

ShaderProgram::ShaderProgram()
	:m_ID(-1)
{}

void ShaderProgram::bind()
{
	glUseProgram(m_ID);
}

void ShaderProgram::unbind()
{
	glUseProgram(0);
}

void ShaderProgram::addUniform(std::string name, ShaderUniformType type, int count)
{
	m_Layout.addShaderUniform(name, type, count);
}

void ShaderProgram::locateUniforms()
{
	m_Layout.locateUniforms(m_ID);
}

void ShaderProgram::loadShader(std::string filename)
{
	std::string vertexSource;
	std::string fragmentSource;
	bool readingVertex;

	std::string line;
	std::ifstream shaderFile(filename.c_str());

	if (shaderFile.is_open()) {
		while (std::getline(shaderFile, line)) {
			if (line == "<SEPERATOR>") {
				readingVertex = false;
			} else {
				if (readingVertex) {
					vertexSource += line;
				} else {
					fragmentSource += line;
				}
			}
		}
		shaderFile.close();
	} else {
		std::cerr << "Failed to open shader file: " << filename << std::endl;
	}

	m_ID = createShader(vertexSource, fragmentSource);
}

GLint ShaderProgram::createShader(std::string vertexShader, std::string fragmentShader)
{
	int program = glCreateProgram();
	int vs = compileShader(vertexShader, GL_VERTEX_SHADER);
	int fs = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);
	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

GLint ShaderProgram::compileShader(std::string source, GLint type)
{
	int id = glCreateShader(type);

	GLchar const* files[] = { source.c_str() };
	GLint lengths[] = { source.size() };

	glShaderSource(id, 1, files, lengths);
	glCompileShader(id);

	GLint isCompiled = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE) {
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		std::cerr << "Failed to compile " << ((type == GL_VERTEX_SHADER) ? "vertex" : "fragment") << " shader!" << std::endl;
		std::cerr << &errorLog[0] << std::endl;

		// Provide the infolog in whatever manor you deem best.
		// Exit with failure.
		glDeleteShader(id); // Don't leak the shader.
		return 0;
	}

	return id;
}