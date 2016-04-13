#pragma once

#include "Common.h"

class Physics
{
public:
	Physics();
	~Physics();

	void Step();

private:
	b2Vec2 gravity;
	b2World world;
	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;
};

