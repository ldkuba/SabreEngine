#include "InputManager.h"

InputManager::InputManager(Application* app)
{
	this->app = app;
	this->window = app->getWindow();

	keyboardHandler = new KeyboardHandler();
	mouseButtonHandler = new MouseButtonHandler();

	glfwSetKeyCallback(this->window, keyboardHandler->invoke);
	glfwSetMouseButtonCallback(this->window, mouseButtonHandler->invoke);
}

InputManager::~InputManager()
{
	delete keyboardHandler;
	delete mouseButtonHandler;
}

bool InputManager::isKeyPressed(int keycode)
{
	return glfwGetKey(window, keycode) == 0;
}

bool InputManager::isMouseButtonPressed(int button)
{
	return glfwGetMouseButton(window, button) == 0;
}

double InputManager::getMouseX()
{
	double x;
	glfwGetCursorPos(window, &x, nullptr);
	return x;
}

double InputManager::getMouseY()
{
	double y;
	glfwGetCursorPos(window, nullptr, &y);
	return y;
}

void InputManager::addKeyboardListener(KeyboardListener* listener)
{
	keyboardHandler->addListener(listener);
}

void InputManager::removeKeyboardListener(KeyboardListener* listener)
{
	keyboardHandler->removeListener(listener);
}

void InputManager::addMouseListener(MouseListener* listener)
{
	mouseButtonHandler->addListener(listener);
}

void InputManager::removeMouseListener(MouseListener* listener)
{
	mouseButtonHandler->removeListener(listener);
}

