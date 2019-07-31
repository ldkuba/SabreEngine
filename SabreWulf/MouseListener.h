#pragma once

class MouseListener {
public:
	MouseListener();
	~MouseListener();
	
	virtual void mouseAction(int button, int action) = 0;
};