#include "StateManager.h"

StateManager::StateManager() {}

StateManager::~StateManager() 
{
	for (int i = 0; i < m_States.size(); i++) {
		m_States[i]->cleanup();
	}
}

void StateManager::registerState(AbstractState* state)
{
	std::unique_ptr<AbstractState> statePtr(state);
	m_States.push_back(std::move(statePtr));
}

void StateManager::setActiveState(int stateId)
{
	for (int i = 0; i < m_States.size(); i++) {
		if (m_States[i]->id == stateId) {
			m_ActiveState = m_States[i].get();
			initState();
		}
	}
}

bool StateManager::checkState()
{
	if (m_ActiveState == nullptr) {
		std::cout << "No active state!" << std::endl;
		return false;
	}

	return true;
}

void StateManager::initState()
{
	if (!checkState()) 
		return;

	m_ActiveState->init();
}

void StateManager::updateState()
{
	if (!checkState())
		return;

	m_ActiveState->update();
}

void StateManager::renderState()
{
	if (!checkState())
		return;

	m_ActiveState->render();
}