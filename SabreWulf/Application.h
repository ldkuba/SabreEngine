#pragma once
#include "vulkan\vulkan.h"
#include <glm\glm.hpp>
#include <GLFW\glfw3.h>
#include "InputManager.h"

struct ApplicationSettings {
public:
	unsigned int width;
	unsigned int height;
	unsigned int vsyncInterval;
	const char* name;
	bool fullscreen;
	bool headless;
	bool networkType;
};

class Application
{
	// Members
	
public:
	static glm::vec2 s_WindowSize;
	static glm::vec2 s_Viewport;

protected:
	NetworkManager* netManager;
	StateManager* stateManager;
	InputManager* inputManager;
	AssetManager* assetManager;
	SoundManager* soundManager;
	Timer* timer;
	
	bool headless;
	bool isFullscreen;

	GLFWwindow* window;

private:
	bool running = true;

	// Methods

public:
	Application(ApplicationSettings settings);
	~Application();

	inline bool isHeadless() { return this->isHeadless; }
	inline GLFWwindow* getWindow() { return this->window; }
	inline StateManager* getStateManager() { return this->stateManager; }
	inline InputManager* getInputManager() { return this->inputManager; }
	inline AssetManager* getAssetManager() { return this->assetManager; }
	inline Timer* getTimer() { return this->timer; }
	inline SoundManager* getSoundManager() { return this->soundManager; }
	inline NetworkManager getNetworkManager() { return this->netManager; }

	void setResolution(int width, int height);
	void setViewport(float right, float top);
	void resize(GLFWwindow* window, int width, int height);

	void run();
	void exit();

	void error_callback(int error, const char* description);

protected:
	void initialise(unsigned int width, unsigned int height, unsigned int vsyncInterval, const char* name, bool fullscreen);
	void cleanup();
};