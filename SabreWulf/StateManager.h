#pragma once
#include "Application.h"
#include "AbstractState.h"

class StateManager {
private:
	Application* app;
	std::vector<AbstractState*> registeredStates;
	AbstractState* activeState;
public:
private:
	bool isRegistered(AbstractState* state);
public:
	StateManager(Application* app);
	~StateManager();

	void addState(AbstractState* state);
	
	void updateState();
	void renderState();

	inline std::vector<AbstractState*> getStates() const { return this->registeredStates; };
	void setCurrentState(AbstractState* state);
};