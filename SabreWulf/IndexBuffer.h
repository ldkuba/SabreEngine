#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "BufferLayout.h"

class IndexBuffer {
public:
	IndexBuffer();
	~IndexBuffer();

	void updateData(int* data, int count, BufferUsage usage);

	void bind();
	void unbind();

private:
	GLuint m_ID;
	int m_Count;
	BufferUsage m_Usage;
};