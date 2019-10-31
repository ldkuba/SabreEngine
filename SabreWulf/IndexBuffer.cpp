#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
{
	m_Count = 0;
	glGenBuffers(1, &m_ID);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}

void IndexBuffer::updateData(int* data, int count, BufferUsage usage)
{
	m_Count = count;
	m_Usage = usage;
	bind();

	if (usage == BufferUsage::STATIC) {
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * 4, (void*)data, GL_STATIC_DRAW);
	} else {
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * 4, (void*)data, GL_DYNAMIC_DRAW);
	}
}

void IndexBuffer::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void IndexBuffer::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}