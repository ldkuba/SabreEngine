#include "VertexBuffer.h"

VertexBuffer::VertexBuffer() 
{
	glGenBuffers(1, &m_ID);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}

void VertexBuffer::updateData(BufferLayout layout, void* data, int count, VertexBufferUsage usage, bool alloc)
{
	m_Count = count;
	m_Layout = layout;
	m_Usage = usage;

	bind();

	if (usage == VertexBufferUsage::STATIC) {
		glBufferData(GL_ARRAY_BUFFER, count*layout.getTotalSize(), data, GL_STATIC_DRAW);
	}else
	{
		if (alloc) {
			glBufferData(GL_ARRAY_BUFFER, count * layout.getTotalSize(), data, GL_DYNAMIC_DRAW);
		}else {
			glBufferSubData(GL_ARRAY_BUFFER, 0, count * layout.getTotalSize(), data);
		}
	}

	//May be incorrect due to padding
	int offset;
	for (int i = 0; i < layout.count; i++) {
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, layout.layout[i].count, layout.layout[i].type, false, layout.getTotalSize(), (void*)offset);

		offset += layout.layout[i].getSize();
	}
}