#include "SceneGraphNode.h"
#include <algorithm>
#include <iostream>

template <class T>
SceneGraphNode<T>::SceneGraphNode(const char* name, T contents)
{
	this->name = name;
	this->contents = contents;
}

template <class T>
SceneGraphNode<T>::~SceneGraphNode()
{
	delete contents;

	for (SceneGraphNode* child : this->children)
	{
		delete child;
	}
}

template <class T>
void SceneGraphNode<T>::add(SceneGraphNode* node)
{
	node->parent = this;
	this->children.push_back(node);
}

template <class T>
void SceneGraphNode<T>::remove(SceneGraphNode* node)
{
	if (hasChild(node))
	{
		node->parent = nullptr;
		children.erase(std::remove(children.begin(), children.end(), node), children.end());
	}
}

template <class T>
void SceneGraphNode<T>::remove(const char* name)
{
	auto child = getChildByName(name);

	if (child != nullptr)
	{
		remove(child);
	}
	else
	{
		std::cerr << "Child " << name << " not found";
	}
}

template <class T>
void SceneGraphNode<T>::removeAll()
{
	for (SceneGraphNode* child : children)
	{
		remove(child);
	}
}

template <class T>
SceneGraphNode* SceneGraphNode<T>::getChildByName(const char* name)
{
	std::vector<SceneGraphNode*>::iterator it;
	for (it = children.begin(); it != children.end(); ++it)
	{
		if (strcmp(name, (*it)->getName()) == 0)
		{
			return *it;
		}
	}

	return nullptr;
}

template <class T>
SceneGraphNode* SceneGraphNode<T>::getChildByIndex(unsigned int index)
{
	if (index < 0 || index > children.size())
	{
		return nullptr;
	}

	return children[index];
}

template <class T>
std::vector<SceneGraphNode*> SceneGraphNode<T>::getChildren()
{
	return children;
}

template <class T>
bool SceneGraphNode<T>::hasChild(SceneGraphNode* node)
{
	if (getChildByName(node->getName()) != nullptr)
	{
		return true;
	}

	return false;
}

template <class T>
bool SceneGraphNode<T>::hasChild(const char* name)
{
	if (getChildByName(name) != nullptr)
	{
		return true;
	}

	return false;
}

template <class T>
void SceneGraphNode<T>::setName(const char* name)
{
	this->name = name;
}

template <class T>
void SceneGraphNode<T>::addTag(const char* tag)
{
	if (!hasTag(tag))
	{
		tags.push_back(tag);
	}
}

template <class T>
void SceneGraphNode<T>::removeTag(const char* name)
{
	tags.erase(std::remove(tags.begin(), tags.end(), name), tags.end());
}

template <class T>
bool SceneGraphNode<T>::hasTag(const char* tag)
{
	for (auto it = tags.begin(); it != tags.end(); ++it)
	{
		if (strcmp(tag, *it) == 0)
		{
			return true;
		}
	}

	return false;
}

template <class T>
const char* SceneGraphNode<T>::getName() const
{
	return this->name;
}

template <class T>
T* getContents() const 
{
	return this->contents;
}