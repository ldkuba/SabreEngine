#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>

#include "StateManager.h"

struct AppSettings
{
	int width, height;
	std::string name;
	bool fullscreen;
};

class Application
{
public:
	Application(AppSettings settings);
	~Application();

	void run();

	//Callback wrappers
	static void s_resizeCallback(GLFWwindow* window, int width, int height);

	StateManager stateManager;

private:
	void initialize();
	void cleanup();

	//Callbacks
	void resizeCallback(GLFWwindow* window, int width, int height);
	static void s_errorCallback(int error, const char* description);

	AppSettings m_Settings;
	GLFWwindow* m_Window;
};
