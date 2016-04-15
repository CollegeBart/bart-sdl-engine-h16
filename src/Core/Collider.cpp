#include "Collider.h"



Collider::Collider()
{
}


Collider::~Collider()
{
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