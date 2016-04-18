#pragma once
#include "Common.h"
#include "Engine.h"
#include "IScene.h"

class Scene : public IScene
{
public:
	Scene();
	~Scene();

	Scene(const char* sceneName)
	{
		Engine::GetInstance()->AddScene(sceneName, this);
	}

	void AddComponent(Component* c)
	{
		components.push_back(c);
	}

	std::vector<Component*> components;
};
