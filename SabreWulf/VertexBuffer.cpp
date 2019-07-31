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
	setData(data, size, layout, bufferUsage, true);
}

void VertexBuffer::setData(const void* data, unsigned int size, 
	const BufferLayout& layout, VertexBufferUsage bufferUsage, bool alloc)
{
	m_Size = size;
	m_VertexLayout = layout;
	m_BufferUsage = bufferUsage;

	bind();
	
	if (m_BufferUsage == VertexBufferUsage::STATIC) {
		glBufferData(GL_ARRAY_BUFFER, size * layout.getLayoutSize(), data, GL_STATIC_DRAW);
	}
	else {
		if (alloc) {
			glBufferData(GL_ARRAY_BUFFER, size * layout.getLayoutSize(), data, GL_DYNAMIC_DRAW);
		}
		else {
			glBufferSubData(GL_ARRAY_BUFFER, 0, size * layout.getLayoutSize(), data);
		}
	}

	long offset = 0;
	for (int i = 0; i < layout.getLayoutCount(); i++)
	{
		glVertexAttribPointer(i, layout.getElement(i).getCount(), layout.getElement(i).getType(), false, layout.getLayoutSize(), &offset);
		glEnableVertexAttribArray(i);

		offset += layout.getElement(i).getTotalSize();
	}
}

void VertexBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VertexBuffer::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}