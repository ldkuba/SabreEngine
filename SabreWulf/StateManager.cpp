#include "StateManager.h"
#include <algorithm>

StateManager::StateManager(Application* app)
	: app{ app }
{

}

StateManager::~StateManager()
{
	for (AbstractState* state : registeredStates)
	{
		delete state;
	}
}

bool StateManager::isRegistered(AbstractState* state)
{
	return (std::find(registeredStates.begin(), registeredStates.end(), state) != registeredStates.end());	
}

void StateManager::addState(AbstractState* state)
{
	if (!isRegistered(state))
	{
		registeredStates.push_back(state);
	}
}

void StateManager::updateState()
{
	activeState->update();
}

void StateManager::renderState()
{
	activeState->render();
}

void StateManager::setCurrentState(AbstractState* state)
{
	if (isRegistered(state))
	{
		if (activeState != nullptr)
		{
			if (!app->isHeadless())
			{
				app->getInputManager()->removeKeyboardListener(activeState);
				app->getInputManager()->removeMouseListener(activeState);
			}

			activeState->deactivate();
		}

		state->initInternal();
		activeState = state;

		if (!app->isHeadless())
		{
			app->getInputManager()->addKeyboardListener(activeState);
			app->getInputManager()->addMouseListener(activeState);
		}
	}
}