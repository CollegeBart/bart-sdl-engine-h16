#include "Ball.h"

Ball::Ball()
	: Sprite("Images/Ball.png")
{
	b2Filter filter;
	filter.categoryBits = Ball::BALL1_CATEGORY;

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
		case Platform::PLATFORM1_CATEGORY: {
			std::cout << "PLATFORM1_CATEGORY" << std::endl;
		} break;

		case Platform::PLATFORM2_CATEGORY: {
			std::cout << "PLATFORM2_CATEGORY" << std::endl;
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
