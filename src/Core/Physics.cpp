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
}

void Physics::Step()
{
	world.Step(timeStep, velocityIterations, positionIterations);
}
