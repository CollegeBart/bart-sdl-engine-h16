#pragma once

#include "Common.h"
#include "Engine.h"
#include "IScene.h"

class Component
{
public:
	friend class Engine;

	Component();
	Component(const char* sceneName);
	~Component();

protected:
	virtual void Start();
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Stop();

	
};

