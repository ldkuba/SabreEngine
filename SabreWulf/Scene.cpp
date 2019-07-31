#include "Scene.h"
#include "Application.h"

Scene::Scene(Application* app)
{
	this->app = app;	
}

Scene::~Scene()
{
	delete camera;
	delete renderer2D;
	delete renderer3D;
}

void Scene::init()
{
	rootNode = new SceneGraphNode<GameObject>("RootNode", new GameObject());

	if (!app->isHeadless())
	{
		camera = new Camera();
		renderer2D = new Renderer2D();
		renderer3D = new Renderer3D(camera);
	}
}

void Scene::update(int deltaTime)
{
	updateNode(rootNode, deltaTime);
}

//Recursive traversal of scene graph for updating
void Scene::updateNode(SceneGraphNode<GameObject>* node, int deltaTime)
{
	node->getContents()->update(deltaTime);

	if(node->getContents())
	
	for (SceneGraphNode<GameObject>* child : node->getChildren())
	{
		updateNode(child, deltaTime);
	}
}
 
void Scene::render()
{
	renderer2D->init(camera);

	renderNode(rootNode);

	renderer2D->drawAll();
}

//Recursive traversal of scene graph for rendering
void Scene::renderNode(SceneGraphNode<GameObject>* node)
{
	node->getContents()->render(renderer2D, renderer3D);

	for (SceneGraphNode<GameObject>* child : node->getChildren())
	{
		renderNode(child);
	}
}