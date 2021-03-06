#pragma once

#include "Common.h"
#include "Engine.h"

class Collider 
{
public:
	enum ColliderType
	{
		SQUARE_COLLIDER = 0,
		SPHERE_COLLIDER = 1,
		PLAYER_COLLIDER = 2,
		TYPE_NUM
	};

	Collider();
	virtual ~Collider();

	void Update(unsigned int t);

	void CreateCollider(ColliderType type, float mass = 0.f);
	void DeleteCollider();

	void SetRotationFixed()
	{
		if (body) {
			b2MassData md;
			body->GetMassData(&md);

			md.I = 0.0f;
			body->SetMassData(&md);
		}
	}

	b2Body* GetBody() const {
		return body;
	}

	// custom collider contact listener
	class CollisionListener 
		: public b2ContactListener
	{
		void BeginContact(b2Contact* contact) {
			void* ud = contact->GetFixtureA()->GetBody()->GetUserData();
			if (ud)
			{
				// check fixtureA collision
				static_cast<Collider*>(ud)->OnCollisionEnter(
					contact->GetFixtureB()
					);
			}

			ud = contact->GetFixtureB()->GetBody()->GetUserData();
			if (ud)
			{
				// check fixtureB collision
				static_cast<Collider*>(ud)->OnCollisionEnter(
					contact->GetFixtureA()
					);
			}
		}

		void EndContact(b2Contact* contact) {
			void* ud = contact->GetFixtureA()->GetBody()->GetUserData();
			if (ud)
			{
				// check fixtureA collision
				static_cast<Collider*>(ud)->OnCollisionLeave(
					contact->GetFixtureB()
					);
			}

			ud = contact->GetFixtureB()->GetBody()->GetUserData();
			if (ud)
			{
				// check fixtureB collision
				static_cast<Collider*>(ud)->OnCollisionLeave(
					contact->GetFixtureA()
					);
			}
		}
	};

protected:
	virtual void OnCollisionEnter(b2Fixture* fixture) {}
	virtual void OnCollisionLeave(b2Fixture* fixture) {}

	b2Body* body;
	Rekt* dstRect;
	float rotation;
	
};