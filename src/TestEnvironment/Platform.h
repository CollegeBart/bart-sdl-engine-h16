#pragma once

#include "Sprite.h"
#include "Ball.h"

class Platform
	: public Sprite
{
public:
	enum PlatformCategories
	{
		PLATFORM1_CATEGORY = 0x0001,
		PLATFORM2_CATEGORY = 0x0002
	};

	Platform();
	~Platform();

protected:
	void OnCollisionEnter(b2Fixture* fixture);
	void OnCollisionLeave(b2Fixture* fixture);
};

