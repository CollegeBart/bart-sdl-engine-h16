#include "Ball.h"

Ball::Ball()
	: Sprite("Images/Ball.png")
{
	b2Filter filter;
	filter.categoryBits = BALL_CATEGORY;

	CreateCollider(Collider::SPHERE_COLLIDER, 1.0f);
	GetBody()->GetFixtureList()[0].SetFilterData(filter);
}

Ball::~Ball()
{

}

void Ball::OnCollisionEnter(b2Fixture * fixture)
{
	std::cout << "Collision" << std::endl;
	if (GetBody()->GetFixtureList()[0].GetFilterData().categoryBits !=
		fixture->GetFilterData().categoryBits)
	{
		switch (fixture->GetFilterData().categoryBits)
		{
		case PLATFORM_CATEGORY: {
			std::cout << "PLATFORM_CATEGORY" << std::endl;
		} break;

		case BALL_CATEGORY: {
			std::cout << "BALL_CATEGORY" << std::endl;
		} break;

		default:
		{
		} break;
		}
	}
}

void Ball::OnCollisionLeave(b2Fixture * fixture)
{

}
