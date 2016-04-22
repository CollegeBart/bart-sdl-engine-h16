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
		components.push_back(c);
	}

protected:
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Stop();

private:
	std::vector<Component*> components;
	
	// Marc Dallaire - 2016/04/20
	// Tableau secondaire pour l'ajout de components au runtime.
	std::vector<Component*> newComponents;

};
