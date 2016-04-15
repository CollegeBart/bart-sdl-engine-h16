#pragma once

#include "Common.h"

class Physics
{
public:
	Physics();
	~Physics();

	void Step();
	b2World GetWorld() { return world; }
	void SetContactListener(b2ContactListener* listener);
	b2Body* CreateBody(int x, int y, b2BodyType type);
	void DestroyBody(b2Body* body);
private:
	b2Vec2 gravity;
	b2World world;
	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;
	std::vector<b2Body*> bodies;
};

