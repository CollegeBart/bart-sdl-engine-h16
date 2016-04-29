#pragma once

#include "Sprite.h"
#include "CollisionCategory.h"

class Ball
	: public Sprite
{
public:
	Ball();
	~Ball();

protected:
	void OnCollisionEnter(b2Fixture* fixture);
	void OnCollisionLeave(b2Fixture* fixture);
};

