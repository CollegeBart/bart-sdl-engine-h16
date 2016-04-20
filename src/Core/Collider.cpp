#include "Collider.h"



Collider::Collider(float _posX, float _posY, float _width, float _heigth, b2BodyType _bodType, int _type)
	: posX(_posX)
	, posY(_posY)
	, width(_width)
	, heigth(_heigth)
	, bodType (_bodType)
	, type(_type)
{
	CreateCollider(_posX, _posY, _width, _heigth, _bodType, _type);
}


Collider::~Collider()
{
}

void Collider::CreateCollider(float posX, float posY, float width, float heigth, b2BodyType bodType, int type)
{
	DeleteCollider();
	body = GPhysics->CreateBody(posX, posY, bodType);
	switch (type)
	{
		case 0:
		{
			b2PolygonShape s;
			s.SetAsBox(width, heigth);
			body->CreateFixture(&s, 1.f);
		}
	}
	body->SetSleepingAllowed(false);
	body->SetUserData(this);
}

//Taken from Box2d manual and BartSDLEngine_H14
//Destroy a body object
void Collider::DeleteCollider()
{
	if (body != NULL)
	{
		GPhysics->DestroyBody(body);
		body = NULL;
	}
}

void Collider::Update()
{}

void Collider::Draw()
{}