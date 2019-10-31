#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

enum BufferUsage {
	STATIC,
	DYNAMIC
};

struct BufferLayoutElement {
	// all types that i will use are 4 bytes numbers. So a single float will be 1 * 4. Vec3 will be 3 * 4.
	unsigned int type;
	int count;

	int getSize() { return count * 4; };
};

class BufferLayout {
public:
	BufferLayout();
	~BufferLayout() = default;

	void addElement(unsigned int type, int count);
	int getTotalSize();

	// get with [] but add with the addElement function
	std::vector<BufferLayoutElement> layout;
	int count;

private:
	
};