#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "AbstractState.h"

class StateManager {
public:
	StateManager();
	~StateManager();

	void registerState(AbstractState* state);
	
	void setActiveState(int stateId);

	void initState();
	void updateState();
	void renderState();

private:
	bool checkState();

	std::vector<std::unique_ptr<AbstractState>> m_States;
	AbstractState* m_ActiveState;
};