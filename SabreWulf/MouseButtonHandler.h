#pragma once

#include <vector>
#include "MouseListener.h"
#include <GLFW\glfw3.h>

class MouseButtonHandler {
private:
	std::vector<MouseListener*> mouseListeners;

public:
	MouseButtonHandler();
	~MouseButtonHandler();

	void invoke(GLFWwindow* window, int button, int action, int mods);
	void addListener(MouseListener* listener);
	void removeListener(MouseListener* listener);
};