#pragma once
#include <vector>

class BufferLayoutElement {
private:
	enum BufferLayoutElementType {
		Int, Float, Vec3, Vec4, Mat4
	};

	BufferLayoutElementType m_Type;
	int m_Count;
public:
	BufferLayoutElement(BufferLayoutElementType type, int count) :
		m_Type(type), m_Count(count) {}

	unsigned int getTotalSize() 
	{
		unsigned int result = 0;
		switch (m_Type) {
		case Int:
			result = 4; break;
		case Float:
			result = 4; break;
		case Vec3:
			result = 3 * 4; break;
		case Vec4:
			result = 4 * 4; break;
		case Mat4:
			result = 4 * 4 * 4; break;
		default:
			result = -1;
		}

		return result * m_Count;
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
};