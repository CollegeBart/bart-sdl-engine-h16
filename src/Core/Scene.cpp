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

	// Marc Dallaire - 2016/04/20
	// Ajout de nouveaux components au runtime.
	if (!newComponents.empty())
	{
		std::vector<Component*>::iterator iter;

		for (iter = newComponents.begin();
		iter != newComponents.end();
			iter++)
		{
			components.push_back((*iter));
		}

		// Vider le tableau après leur ajout au tableau principal.
		newComponents.clear();
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