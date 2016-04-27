#pragma once

#include "Engine.h"
#include "Component.h"

class Scene : public IScene
{
public:
	Scene();
	Scene(const char* sceneName);

	~Scene();

	void AddComponent(Component* c)
	{
		newComponents.push_back(c);
	}

	// Marc Dallaire - 2016/04/27
	// Ajout de la destruction d'un Component.
	void DeleteComponent(Component* c);

protected:
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Stop();

private:
	std::vector<Component*> components;
	std::vector<Component*> newComponents;

};
