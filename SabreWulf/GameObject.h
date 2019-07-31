#pragma once
#include "SceneGraphNode.h"

class GameObject {
private:
	// -1 - indefinite lifetime, >0 - lifetime in ticks
	int lifetime;

	// Components (all possible)


public:
private:

public:
	GameObject();
	GameObject(unsigned int lifetime);
	~GameObject();

	void setLifetime(unsigned int lifetime);
	unsigned int getLifetime();

	virtual void update(int deltaTime);

	void render(Renderer2D renderer2D, Renderer3D renderer3D);
};