#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "BufferLayout.h"

enum VertexBufferUsage {
	STATIC, DYNAMIC
};

class VertexBuffer {
private:
	GLuint m_ID;
	BufferLayout m_VertexLayout;
	unsigned int m_Size;
	VertexBufferUsage m_BufferUsage;

public:
	VertexBuffer();
	VertexBuffer(const void* data, unsigned int size, const BufferLayout& layout, VertexBufferUsage bufferUsage);
	~VertexBuffer();

	void SetData(const void* data, unsigned int size, const BufferLayout& layout, VertexBufferUsage bufferUsage);

	void Bind();
	void Unbind();
};