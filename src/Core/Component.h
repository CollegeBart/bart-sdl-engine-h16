#pragma once

#include "Common.h"

class Component
{
public:

	friend class Engine;

	Component();
	~Component();

	virtual void Update();

private:

	static std::vector<Component*> components;
};

