#pragma once
#include <map>

class Component;

class IScene
{
public:
	virtual void AddComponent(Component* component) = 0;
};