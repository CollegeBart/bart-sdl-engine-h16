#pragma once

#include "Component.h"
#include "Engine.h"

class Collider :
	public Component
{
public:
	Collider(float posX, float posY, float width, float heigth, b2BodyType bodType, int type);
	virtual ~Collider();

	void CreateCollider(float posX, float posY, float width, float heigth, b2BodyType bodType, int type );
	//Remove a body object
	void DeleteCollider();

	b2Body* GetBody() { return body; }

private:
	float posX, posY, width, heigth;
	b2BodyType bodType;
	int type;
	virtual void Update();
	virtual void Draw();
	b2Body* body;
};
