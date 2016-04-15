#include "Physics.h"

Physics::Physics()
	: gravity(0.0f, -9.81f)
	, world(gravity)
	, velocityIterations(6)
	, positionIterations(2)
	, timeStep(1.0f / 60.0f)
{

}

Physics::~Physics()
{
	bodies.clear();
}

void Physics::SetContactListener(b2ContactListener* listener) 
{ 
	world.SetContactListener(listener); 
}

void Physics::Step()
{
	world.Step(timeStep, velocityIterations, positionIterations);
}

void Physics::DestroyBody(b2Body* body)
{
	std::vector<b2Body*>::iterator it = bodies.begin();
	while (it != bodies.end())
	{
		if ((*it) == body)
		{
			world.DestroyBody(body);
			it = bodies.erase(it);
			break;
		} it++;
	}
}
