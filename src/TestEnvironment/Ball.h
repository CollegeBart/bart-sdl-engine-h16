#pragma once

#include "Sprite.h"
#include "Platform.h"

class Ball
	: public Sprite
{
public:
	enum BallCategories
	{
		BALL1_CATEGORY = 0x0001,
		BALL2_CATEGORY = 0x0002
	};

	Ball();
	~Ball();

protected:
	void OnCollisionEnter(b2Fixture* fixture);
	void OnCollisionLeave(b2Fixture* fixture);
};

