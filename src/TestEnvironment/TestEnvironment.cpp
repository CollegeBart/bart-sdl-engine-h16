#include "TestEnvironment.h"

TestEnvironment::TestEnvironment()
	: isDoneTen(false)
	, isDoneHundred(false)
{
	// Sprites
	//sprite = new Sprite("Images\\JeSuisRenaud.png");
	scrolling = new BackGroundScroller(230, 250, "Images\\level.png", 1, true);
	renaud = new Renaud();
	testSprite = new Sprite("Images\\course.png", 100, 300);
	
	col = new Collider();
	col->CreateCollider(10, 10, 20, 20, b2_dynamicBody, 0);

	// Fonts
	SDL_Rect* textRect = new SDL_Rect();
	std::stringstream ss;
	ss << std::setw(3) << std::setfill(' ') << 0;
	test = new Font(ss.str().c_str(), textRect);
	
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
