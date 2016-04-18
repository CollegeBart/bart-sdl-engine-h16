#pragma once

#include "Component.h"
#include "Engine.h"

class Collider :
	public Component
{
public:
	Collider();
	virtual ~Collider();

	void CreateCollider(float posX, float posY, float width, float heigth, b2BodyType bodType, int type );
	//Remove a body object
	void DeleteCollider();

	b2Body* GetBody() { return body; }

private:
	virtual void Update();
	virtual void Draw();
	b2Body* body;
};
