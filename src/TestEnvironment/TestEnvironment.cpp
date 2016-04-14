#include "TestEnvironment.h"

TestEnvironment::TestEnvironment()
	: isDoneTen(false)
	, isDoneHundred(false)
{
	// Sprites
	//sprite = new Sprite("Images\\JeSuisRenaud.png");
	scrolling = new BackGroundScroller(230, 250, "Images\\level.png", 2, true);
	renaud = new Renaud();
	testSprite = new Sprite("Images\\course.png", 100, 300);
	


	// Fonts
	SDL_Rect* textRect = new SDL_Rect();
	std::stringstream ss;
	ss << std::setw(3) << std::setfill(' ') << 0;
	test = new Font(ss.str().c_str(), textRect);
	

	//b2Vec2 gravity(0.0f, -10.0f);
	//b2World world(gravity);
	
	//b2BodyDef myBodyDef;
	//myBodyDef.type = b2_dynamicBody;
	//myBodyDef.position.Set(0, 20);
	//myBodyDef.angle = 0;
	
	//b2Body* myBody;
	
	//myBody = world.CreateBody(&myBodyDef);
	//b2PolygonShape boxShape;
	//boxShape.SetAsBox(1, 1);
	
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
	// TIMER 
	std::stringstream ss;
	ss << std::setw(3) << std::setfill(' ') << GTimer->GetTimeInSeconds();
	test->SetText(ss.str().c_str());
}
