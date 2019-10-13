#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <memory>

#include "BufferLayout.h"

enum VertexBufferUsage{
	STATIC,
	DYNAMIC
};

class VertexBuffer {
public:
	VertexBuffer();
	~VertexBuffer();

	void updateData(BufferLayout layout, void* data, int count, VertexBufferUsage usage, bool alloc);

	void bind();
	void unbind();

private:
	GLuint m_ID;
	BufferLayout m_Layout;
	VertexBufferUsage m_Usage;
	int m_Count;
};