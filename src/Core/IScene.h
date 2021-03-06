#pragma once
#include <map>

class Component;

class IScene
{
	friend class Engine;

public:
	virtual void AddComponent(Component* component) = 0;

	// Marc Dallaire - 2016/04/27
	// Ajout de la destruction d'un Component.
	virtual void DeleteComponent(Component* component) = 0;

protected:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Stop() = 0;

};