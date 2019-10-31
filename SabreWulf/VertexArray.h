#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class VertexArray {
public:
	VertexArray();
	~VertexArray();

	void bind();
	void unbind();

private:
	GLuint m_ID;
};