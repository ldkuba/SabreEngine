#include "MouseButtonHandler.h"
#include <algorithm>

MouseButtonHandler::MouseButtonHandler()
{
	mouseListeners.resize(0);
}

MouseButtonHandler::~MouseButtonHandler() {}

void MouseButtonHandler::invoke(GLFWwindow* window, int button, int action, int mods)
{
	for (MouseListener* listener : mouseListeners)
	{
		listener->mouseAction(button, action);
	}
}

void MouseButtonHandler::addListener(MouseListener* listener)
{
	mouseListeners.push_back(listener);
}

void MouseButtonHandler::removeListener(MouseListener* listener)
{
	auto it = std::find(mouseListeners.begin(), mouseListeners.end(), listener);
	if (it != mouseListeners.end())
	{
		mouseListeners.erase(it);
	}
}