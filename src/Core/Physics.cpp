#include "Physics.h"

Physics::Physics()
	: gravity(0.0f, -9.81f)
	, world(gravity)
	, velocityIterations(6)
	, positionIterations(2)
	, timeStep(1.0f / 60.0f)
{
	listener = new b2ContactListener();
	world.SetContactListener(listener);
}

Physics::~Physics()
{
	bodies.clear();
}

void Physics::Step()
{
	//Call to the "world" object to "update" 
	world.Step(timeStep, velocityIterations, positionIterations);
}
//Taken from Box2D manual "Body creation"
b2Body* Physics::CreateBody(int x, int y, b2BodyType type)
{
	//A body needs a definition
	b2BodyDef def;

	//The body X and Y position
	def.position.x = (float)x;
	def.position.y = (float)y;
	//The body type
	def.type = type;
	//Call to the "world" object to create a "body"
	return world.CreateBody(&def);
}

//Taken from Box2D manual "safely remove body"
void Physics::DestroyBody(b2Body* body)
{
	//Start with the first body in the list
	std::vector<b2Body*>::iterator it = bodies.begin();
	//As long as we have not reached the last body from the list
	while (it != bodies.end())
	{
		if ((*it) == body)
		{
			//Call to the "world" object to destroy the body
			world.DestroyBody(body);
			it = bodies.erase(it);
			break;
		} it++;
	}
}
