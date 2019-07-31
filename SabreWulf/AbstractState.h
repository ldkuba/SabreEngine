#pragma once
#include "Application.h"
#include "KeyboardListener.h"
#include "MouseListener.h"
#include "Scene.h"

class AbstractState : public KeyboardListener, public MouseListener {
protected:
	Scene* scene;
	Application* app;

private:
public:
	AbstractState(Application* application);
	~AbstractState();
	
	//Called by the engine
	void initInternal();
	void renderInternal();
	void updateInternal();

	//Overridable, called by the Internal counterparts
	virtual void init() = 0;
	virtual void render() = 0;
	virtual void update() = 0;

	virtual void deactivate() = 0;
	inline Scene* getScene() const { return this->scene; };
};