#include "BufferLayout.h"

BufferLayout::BufferLayout()
	:count(0)
{}

void BufferLayout::addElement(unsigned int type, int count)
{
	layout.push_back({ type, count });

	this->count++;
}

int BufferLayout::getTotalSize()
{
	int totalSize = 0;
	for (int i = 0; i < count; i++)
	{
		totalSize += layout[i].getSize();
	}

	return totalSize;
}