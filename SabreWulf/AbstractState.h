#pragma once

class AbstractState {
public:
	AbstractState(int stateId)
		:id(stateId) {}
	virtual ~AbstractState();

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void cleanup() = 0;

	int id;

private:
	AbstractState();
};