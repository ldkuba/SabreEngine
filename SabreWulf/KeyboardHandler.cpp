#include "KeyboardHandler.h"
#include <algorithm>

KeyboardHandler::KeyboardHandler()
{
	keyboardListeners.resize(0);
}

KeyboardHandler::~KeyboardHandler() {}

void KeyboardHandler::invoke(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	for (KeyboardListener* listener : keyboardListeners)
	{
		listener->keyAction(key, action);
	}
}

void KeyboardHandler::addListener(KeyboardListener* listener)
{
	keyboardListeners.push_back(listener);
}

void KeyboardHandler::removeListener(KeyboardListener* listener)
{
	auto it = std::find(keyboardListeners.begin(), keyboardListeners.end(), listener);
	if (it != keyboardListeners.end()) 
	{
		keyboardListeners.erase(it); 
	}
}