#include "GameObject.h"

GameObject::GameObject() :
	lifetime{ -1 }
{

}

GameObject::GameObject(unsigned int lifetime) :
	lifetime{ lifetime }
{

}

GameObject::~GameObject() {}

void GameObject::setLifetime(unsigned int lifetime)
{
	this->lifetime = lifetime;
}

unsigned int GameObject::getLifetime()
{
	return this->lifetime;
}

void GameObject::update(int deltaTime)
{
	this->lifetime -= deltaTime;
}

void GameObject::render(Renderer renderer)
{
	//Rendering components
}