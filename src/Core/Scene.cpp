#include "Scene.h"

Scene::Scene()
{
	Engine::GetInstance()->AddScene(DEFAULT_SCENE_NAME, this);
}

Scene::Scene(const char* sceneName)
{
	Engine::GetInstance()->AddScene(sceneName, this);
}

Scene::~Scene()
{
}

void Scene::Start()
{
	std::vector<Component*>::iterator iter;
	for (iter = components.begin();
	iter != components.end();
		iter++)
	{
		(*iter)->Start();
	}
}

void Scene::Update()
{
	std::vector<Component*>::iterator iter;
	for (iter = components.begin(); 
		 iter != components.end();
		 iter++)
	{
		(*iter)->Update();
	}
}

void Scene::Draw()
{
	std::vector<Component*>::iterator iter;
	for (iter = components.begin();
	iter != components.end();
		iter++)
	{
		(*iter)->Draw();
	}
}

void Scene::Stop()
{
	std::vector<Component*>::iterator iter;
	for (iter = components.begin();
	iter != components.end();
		iter++)
	{
		(*iter)->Stop();
	}
}