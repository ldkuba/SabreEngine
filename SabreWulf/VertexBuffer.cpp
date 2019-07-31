#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &m_ID);
	m_Size = 0;
}

VertexBuffer::VertexBuffer(const void* data, unsigned int size,
	const BufferLayout& layout, VertexBufferUsage bufferUsage)
{
	glGenBuffers(1, &m_ID);
	SetData(data, size, layout, bufferUsage);
}

void VertexBuffer::SetData(const void* data, unsigned int size, 
	const BufferLayout& layout, VertexBufferUsage bufferUsage)
{
	m_Size = size;
	m_VertexLayout = layout;
	m_BufferUsage = bufferUsage;

	Bind();
	
	if (m_BufferUsage == VertexBufferUsage::STATIC) {
		glBufferData(GL_ARRAY_BUFFER, size * layout.GetSizeInBytes(), data, GL_STATIC_DRAW);
	}
	else {
		glBufferData(GL_ARRAY_BUFFER, size * layout.GetSizeInBytes(), data, GL_DYNAMIC_DRAW);
	}

	//TODO: enable vertex attributes
}

void VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}