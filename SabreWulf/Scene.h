#pragma once
#include "GameObject.h"
#include "SceneGraphNode.h"

class Scene {
private:
	SceneGraphNode<GameObject> *rootNode; //GameObject
	// GuiObject* rootGuiNode; //GUI Object //- TODO

	Renderer2D* renderer2D;
	Renderer3D* renderer3D;
	Camera* camera;

	Application* app;

public:
private:
	void updateNode(SceneGraphNode<GameObject>* node, int deltaTime);
	void renderNode(SceneGraphNode<GameObject>* node);
public:
	Scene(Application* app);
	~Scene();
	void init();
	
	void update(int deltaTime);
	void render();

	inline Camera getCamera() { return this->camera; };
	inline Renderer2D getRenderer2D() { return this->camera; };
	inline Renderer3D getRenderer3D() { return this->camera; };

};