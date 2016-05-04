#pragma once

#include "Common.h"
#include "Collider.h"
#include "Engine.h"

class Component
	: public Collider
{
public:
	friend class Scene;

	Component();
	Component(const char* sceneName);
	virtual ~Component();

	bool GetIsNew() { return isNew; }

protected:
	virtual void Start();
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Stop();

private:
	bool isNew;
};

