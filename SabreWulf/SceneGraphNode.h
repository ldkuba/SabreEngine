#pragma once
#include <vector>

template <class T>
class SceneGraphNode {
protected:
	const char* name;

	T* contents;

	SceneGraphNode* parent;
	std::vector<SceneGraphNode*> children;

	std::vector<const char*> tags;

public:
private:

public:
	SceneGraphNode(const char* name, T contents);
	~SceneGraphNode();

	void add(SceneGraphNode* node);
	void remove(SceneGraphNode* node);
	void remove(const char* name);
	void removeAll();

	SceneGraphNode* getChildByName(const char* name);
	SceneGraphNode* getChildByIndex(unsigned int index);
	std::vector<SceneGraphNode*> getChildren();

	bool hasChild(SceneGraphNode* node);
	bool hasChild(const char* name);

	void setName(const char* name);

	void addTag(const char* tag);
	void removeTag(const char* tag);
	bool hasTag(const char* tag);

	const char* getName() const;

	T* getContents() const;
};