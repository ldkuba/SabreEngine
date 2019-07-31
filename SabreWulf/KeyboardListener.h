#pragma once

class KeyboardListener {
public:
	KeyboardListener();
	~KeyboardListener();

	virtual void keyAction(int key, int action) = 0;
};