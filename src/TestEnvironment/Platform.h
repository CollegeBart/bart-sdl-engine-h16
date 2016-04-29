#pragma once

#include "Sprite.h"
#include "CollisionCategory.h"

class Platform
	: public Sprite
{
public:
	Platform();
	~Platform();

protected:
	void OnCollisionEnter(b2Fixture* fixture);
	void OnCollisionLeave(b2Fixture* fixture);
};

