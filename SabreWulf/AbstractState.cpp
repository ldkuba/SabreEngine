#include "AbstractState.h"

AbstractState::AbstractState(Application* application)
	: app{ application }
{
	scene = new Scene(application);
}

AbstractState::~AbstractState() 
{
	delete scene;
}

void AbstractState::initInternal()
{
	scene->init();
	this->init();
}

void AbstractState::renderInternal()
{
	if (!app->isHeadless())
	{
		scene->render();
	}

	this->render();
}

void AbstractState::updateInternal()
{
	scene->update();
	this->update();
}