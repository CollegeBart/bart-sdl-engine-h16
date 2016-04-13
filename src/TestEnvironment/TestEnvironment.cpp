#include "TestEnvironment.h"

TestEnvironment::TestEnvironment()
{
	// Sprites
	sprite = new Sprite("Images\\JeSuisRenaud.png");
	renaud = new Renaud();

	// Fonts
	SDL_Rect* textRect = new SDL_Rect();
	test = new Font("#define RENAUD as NULL", textRect);

	//b2Vec2 gravity(0.0f, -10.0f);
	//b2World world(gravity);
	//
	//b2BodyDef myBodyDef;
	//myBodyDef.type = b2_dynamicBody;
	//myBodyDef.position.Set(0, 20);
	//myBodyDef.angle = 0;
	//
	//b2Body* myBody;
	//
	//myBody = world.CreateBody(&myBodyDef);
	//b2PolygonShape boxShape;
	//boxShape.SetAsBox(1, 1);
	//
	//b2FixtureDef boxFixtureDef;
	//boxFixtureDef.shape = &boxShape;
	//boxFixtureDef.density = 1;
	//myBody->CreateFixture(&boxFixtureDef);
}

TestEnvironment::~TestEnvironment()
{
	delete renaud;
}

void TestEnvironment::Update()
{
	#pragma region Input Tests
	if (GInput->IsKeyPressed(SDL_SCANCODE_RETURN))
	{
		std::cout << "Pressed!" << std::endl;
	}

	if (GInput->IsKeyReleased(SDL_SCANCODE_RETURN))
	{
		std::cout << "Released!" << std::endl;
	}

	if (GInput->IsKeyHeld(SDL_SCANCODE_RETURN))
	{
		std::cout << "Held!" << std::endl;
	}
	#pragma endregion
	
	std::string s = std::to_string(GTimer->GetTimeInSeconds());
	char const *pchar = s.c_str();
	test->SetText(pchar);
}
