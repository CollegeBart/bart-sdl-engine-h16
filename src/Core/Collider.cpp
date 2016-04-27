#include "Collider.h"

Collider::Collider() 
	: body(NULL)
	, dstRect(nullptr)
{
	dstRect = new Rekt();
}

Collider::~Collider()
{
	DeleteCollider();
}

void Collider::Update(unsigned int t)
{
	if (body != nullptr)
	{
		dstRect->x = (int)body->GetPosition().x - (dstRect->w * 0.5f);
		dstRect->y = (int)body->GetPosition().y - (dstRect->h * 0.5f);
		rotation = glm::degrees(body->GetAngle());
	}
}

void Collider::CreateCollider(ColliderType type, float mass)
{
	DeleteCollider();
	body = GPhysics->CreateBody(dstRect->x + (dstRect->w * 0.5f), dstRect->y + (dstRect->h * 0.5f),
		(mass == 0.f) ? b2_staticBody : b2_dynamicBody
		);

	switch (type)
	{
	case SQUARE_COLLIDER:
	{
		b2PolygonShape s;
		s.SetAsBox
			(
				float(dstRect->w * 0.5f),
				float(dstRect->h * 0.5f)
				);

		body->CreateFixture(&s, 1.f);
	} break;

	case SPHERE_COLLIDER:
	{
		b2CircleShape s;
		s.m_radius = (dstRect->w > dstRect->h)
			? float(dstRect->w * 0.5f)
			: float(dstRect->h * 0.5f);

		body->CreateFixture(&s, 1.f);
	} break;

	case PLAYER_COLLIDER:
	{
		{
			b2PolygonShape s;
			s.SetAsBox
				(
					6.f,
					4.f
					);

			body->CreateFixture(&s, 1.f);
		}
		{
			b2CircleShape s;
			s.m_radius = 4.f;
			s.m_p.y = 7.f;

			body->CreateFixture(&s, 1.f);
		}
	} break;

	default:
	{
	} break;
	}

	body->SetSleepingAllowed(false);
	body->SetUserData(this);
}

void Collider::DeleteCollider()
{
	if (body != NULL)
	{
		GPhysics->DestroyBody(body);
		body = NULL;
	}
}