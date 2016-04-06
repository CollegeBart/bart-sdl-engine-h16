#pragma once

#include "Common.h"

class Component
{
public:
	friend class Engine;

	Component();
	~Component();

protected:
	virtual void Start();
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Stop();

private:
	static std::vector<Component*> components;
};

