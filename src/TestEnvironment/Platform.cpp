#include "Platform.h"

Platform::Platform()
	: Sprite("Images/Platform.png", 20, 500)
{
	b2Filter filter;
	filter.categoryBits = Platform::PLATFORM1_CATEGORY;

	CreateCollider(Collider::SQUARE_COLLIDER, 0.0f);
	GetBody()->GetFixtureList()[0].SetFilterData(filter);
}

Platform::~Platform()
{
}

void Platform::OnCollisionEnter(b2Fixture * fixture)
{
	std::cout << "Collision" << std::endl;
	if (GetBody()->GetFixtureList()[0].GetFilterData().categoryBits !=
		fixture->GetFilterData().categoryBits)
	{
		switch (fixture->GetFilterData().categoryBits)
		{
		case Ball::BALL1_CATEGORY: {
			std::cout << "BALL1_CATEGORY" << std::endl;
		} break;

		case Ball::BALL2_CATEGORY: {
			std::cout << "BALL2_CATEGORY" << std::endl;
		} break;

		default:
		{
		} break;
		}
	}
}

void Platform::OnCollisionLeave(b2Fixture * fixture)
{
}
