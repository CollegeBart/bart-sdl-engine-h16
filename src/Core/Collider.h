#pragma once

#include "Component.h"
#include "Engine.h"

class Collider :
	public Component
{
public:
	Collider();
	virtual ~Collider();

	//Will be able to add more shapes for collider (like sphere polygon, etc)
	enum ColliderType
	{
		SQUARE_COLLIDER = 0,
	};


	//Remove a body object
	void DeleteCollider();

	b2Body* GetBody() { return body; }

private:
	b2Body* body;
};
