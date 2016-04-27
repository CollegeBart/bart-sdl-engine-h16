#include "Scene.h"

Scene::Scene()
{
	GEngine->AddScene(DEFAULT_SCENE_NAME, this);

	// Initialize physics.
	GPhysics->SetContactListener(
		new Collider::CollisionListener());
}

Scene::Scene(const char* sceneName)
{
	GEngine->AddScene(sceneName, this);

	// Initialize physics.
	GPhysics->SetContactListener(
		new Collider::CollisionListener());
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
		// Marc Dallaire - 2016/04/26
		// Ajout du Start() pour les nouveaux components créés au runtime. (Semble pas changer grand chose...)
		if (!(*iter)->GetIsNew())
		{
			(*iter)->Start();
		}

		(*iter)->Update();
	}

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

// Marc Dallaire - 2016/04/27
// Ajout de la destruction d'un Component.
void Scene::DeleteComponent(Component* c)
{
	std::vector<Component*>::iterator iter = find(components.begin(), components.end(), c);

	if (iter != components.end())
	{
		delete (*iter);
		components.erase(iter);
		Update();
	}
}

