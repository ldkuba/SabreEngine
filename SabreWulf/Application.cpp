#include "Application.h"
#include <iostream>

Application::Application(ApplicationSettings settings)
{
	this->headless = settings.headless;
	if (!settings.headless) {

		initialise(settings.width, settings.height, settings.vsyncInterval, settings.name, settings.fullscreen);
		inputManager = new InputManager(this);
		assetManager = new AssetManager();
		soundManager = new SoundManager();
		setViewport(10.0f * (s_WindowSize.getX() / s_WindowSize.getY()), 10.0f);
		netManager = new NetworkManager(this, settings.networkType);

	}
	else {
		netManager = new NetworkManager(this, settings.networkType);
	}

	timer = new Timer(60.0f);
	stateManager = new StateManager(this);
}

Application::~Application() {}

void Application::initialise(unsigned int width, unsigned int height, unsigned int vsyncInterval, const char* name, bool fullscreen)
{
	// Initialise GLFW
	if (!glfwInit()) {
		std::cerr << "Failed to initialie GLFW" << std::endl;
	}

	isFullscreen = fullscreen;

	const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	if (!isFullscreen) {

		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
		// Create the window
		window = glfwCreateWindow(width, height, name, NULL, NULL);
		setResolution(width, height);
	}
	else {

		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		window = glfwCreateWindow(vidmode->width, vidmode->height, name, glfwGetPrimaryMonitor(), NULL);
		setResolution(vidmode->width, vidmode->height);
	}

	// before context creation
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

	if (!window) {
		std::cerr << "Failed to create window" << std::endl;
	}

	// Centre the window
	int pWidth, pHeight;
	glfwGetWindowSize(window, &pWidth, &pHeight);
	glfwSetWindowPos(window, (vidmode->width - pWidth) / 2, (vidmode->height - pHeight) / 2);

	glfwMakeContextCurrent(window);

	// set errorCallback
	glfwSetErrorCallback(this->error_callback);
	// set resizeCallback
	glfwSetWindowSizeCallback(window, this->resize);
	// Enable v-sync
	glfwSwapInterval(vsyncInterval);
	// Enable Antialiasing
	glfwWindowHint(GLFW_SAMPLES, 2);
	// Make the window visible
	glfwShowWindow(window);
}

void Application::run()
{
	if (!headless) {
		// Run the rendering loop until the user presses esc or quits
		while (!glfwWindowShouldClose(window)) {

			netManager.handleMessagesAndConnections();
			stateManager.updateState();
			gui.update();

			stateManager.renderState();

			glfwSwapBuffers(window); // swap the colour buffers
			glfwPollEvents(); // Poll for window events. The key callback
							  // above
							  // will only be invoked during this call.

			timer.waitForTick();
		}
	}
	else {
		// Run the rendering loop until the user presses esc or quits
		while (running) {
			netManager.handleMessagesAndConnections();
			stateManager.updateState();

			timer.waitForTick();
		}
	}

	cleanup();
}

void Application::setResolution(int width, int height)
{
	s_WindowSize = glm::vec2(width, height);
}

void Application::setViewport(float right, float top)
{
	s_Viewport = glm::vec2(right, top);
}

void Application::resize(GLFWwindow* window, int width, int height)
{
	if (!isFullscreen) {
		setResolution(width, height);
	}
}

void Application::exit()
{
	if (!headless)
	{
		glfwSetWindowShouldClose(window, true);
	}
	else {
		running = false;
	}
}

void Application::cleanup()
{
	if (!headless)
	{
		glfwDestroyWindow(window);
		// Terminate GLFW
		glfwTerminate();
		soundManager.clean();
		
		delete this->inputManager;
	}

	netManager.stopConnection();
}
