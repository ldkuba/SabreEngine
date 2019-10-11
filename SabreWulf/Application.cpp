#include "Application.h"

Application::Application(AppSettings settings)
{
	m_Settings = settings;

	initialize();
}

Application::~Application()
{
	cleanup();
}

void Application::initialize()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// glfw window creation
	// --------------------
	m_Window = glfwCreateWindow(m_Settings.width, m_Settings.height, m_Settings.name.c_str(), NULL, NULL);
	if (m_Window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}

	glfwSetWindowUserPointer(m_Window, this);
	glfwMakeContextCurrent(m_Window);
	
	glfwSetFramebufferSizeCallback(m_Window, Application::s_resizeCallback);
	glfwSetErrorCallback(Application::s_errorCallback);

	// glew: load all OpenGL function pointers
	// ---------------------------------------
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return;
	}
}

void Application::run()
{
	// render loop
	// -----------
	while (!glfwWindowShouldClose(m_Window))
	{
		// update
		stateManager.updateState();

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		stateManager.renderState();

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	cleanup();
}

void Application::s_resizeCallback(GLFWwindow* window, int width, int height)
{
	Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));
	app->resizeCallback(window, width, height);
}

void Application::resizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Application::s_errorCallback(int error, const char* description)
{
	std::cout << "Error " << error << ": " << description << std::endl;
}

void Application::cleanup()
{
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}