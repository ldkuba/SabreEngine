#pragma once
#include <GLFW/glfw3.h>
#include "Application.h"
#include "KeyboardHandler.h"
#include "MouseButtonHandler.h"

class InputManager {

private:
	KeyboardHandler* keyboardHandler;
	MouseButtonHandler* mouseButtonHandler;
	Application *app;
	GLFWwindow* window;

public:
	InputManager(Application* app);
	~InputManager();
	
	bool isKeyPressed(int keycode);
	bool isMouseButtonPressed(int button);

	double getMouseX();
	double getMouseY();

	void addKeyboardListener(KeyboardListener* listener);
	void removeKeyboardListener(KeyboardListener* listener);

	void addMouseListener(MouseListener* listener);
	void removeMouseListener(MouseListener* listener);
};