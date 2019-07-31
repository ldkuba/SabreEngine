#pragma once
#include <vector>
#include <GL/glew.h>

class BufferLayoutElement {
private:
	enum BufferLayoutElementType {
		Int = GL_INT, Float = GL_FLOAT
	};

	BufferLayoutElementType m_Type;
	int m_Count;
public:
	BufferLayoutElement(BufferLayoutElementType type, int count) :
		m_Type(type), m_Count(count) {}

	unsigned int getTotalSize() 
	{
		return 4 * m_Count;
	}

	int getCount()
	{
		return m_Count;
	}

	BufferLayoutElementType getType() 
	{
		return m_Type;
	}
};

class BufferLayout {
private:
	std::vector<BufferLayoutElement> m_BufferLayout;

public:
	BufferLayout();
	BufferLayout(std::vector<BufferLayoutElement> elements);

	inline void addElement(BufferLayoutElement el) { m_BufferLayout.push_back(el); };
	inline BufferLayoutElement getElement(int index) const { return m_BufferLayout[index]; };
	unsigned int getLayoutSize() const;
	inline unsigned int getLayoutCount() const { return m_BufferLayout.size(); };
};