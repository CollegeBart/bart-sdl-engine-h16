#pragma once

//#include "Common.h"
#include "Engine.h"

class Component
{
public:
	friend class Scene;

	Component();
	Component(const char* sceneName);
	~Component();

	bool GetIsNew() { return isNew; }

protected:
	virtual void Start();
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Stop();

private:
	bool isNew;
};

