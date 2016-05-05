#pragma once

#include "Common.h"

class Physics
{
public:
	Physics();
	~Physics();

	b2World* GetWorld()
	{
		return &world;
	}

	void SetContactListener(b2ContactListener* listener) {
		world.SetContactListener(listener);
	}

	void Step(float step = 1.0f / 60.0f, int vit = 6, int pit = 2)
	{
		world.Step(step, vit, pit);
		world.Step(step, vit, pit);
		world.Step(step, vit, pit);
		world.Step(step, vit, pit);
		world.ClearForces();
	}

	b2Body* CreateBody(int x, int y, b2BodyType type);
	void DestroyBody(b2Body* body);

private:
	std::vector<b2Body*> bodies;
	b2World world;
};