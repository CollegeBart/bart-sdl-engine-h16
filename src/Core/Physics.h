#pragma once

#include "Common.h"

class Physics
{
public:
	Physics();
	~Physics();

	//Step is the physics "update"
	void Step();
	//Physics use a "world" object responsible for body creation
	b2World GetWorld() { return world; }
	//Fonction to create a "body" object
	b2Body* CreateBody(int posX, int posY, b2BodyType bodyType);
	//Destroy a body object
	void DestroyBody(b2Body* body);
private:
	b2Vec2 gravity;
	b2ContactListener* listener;
	b2World world;
	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;
	std::vector<b2Body*> bodies;
};

