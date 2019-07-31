#pragma once
#include <vector>
#include "KeyboardListener.h"
#include <GLFW\glfw3.h>

class KeyboardHandler {
private:
	std::vector<KeyboardListener*> keyboardListeners;

public:
	KeyboardHandler();
	~KeyboardHandler();

	void invoke(GLFWwindow* window, int key, int scancode, int action, int mods);
	void addListener(KeyboardListener* listener);
	void removeListener(KeyboardListener* listener);
};