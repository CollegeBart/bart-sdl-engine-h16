#pragma once

#include "Component.h"

class Collider :
	public Component
{
public:
	Collider();
	virtual ~Collider();
	b2Body* GetBody() { return body; }

private:
	b2Body* body;
};
