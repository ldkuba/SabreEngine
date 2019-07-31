#include "BufferLayout.h"

BufferLayout::BufferLayout() {}

BufferLayout::BufferLayout(std::vector<BufferLayoutElement> layout) :
	m_BufferLayout(layout) {}

unsigned int BufferLayout::getLayoutSize() const 
{
	unsigned int size = 0;
	for (BufferLayoutElement el : m_BufferLayout) {
		size += el.getTotalSize();
	}
	return size;
}