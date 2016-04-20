#include "TestEnvironment.h"

TestEnvironment::TestEnvironment()
	: isDoneTen(false)
	, isDoneHundred(false)
{
	// Sprites
	sprite = new Sprite("Images\\JeSuisRenaud.png");
	//scrolling = new BackGroundScroller(230, 250, "Images\\level.png", 1, true);
	renaud = new Renaud();
	//testSprite = new Sprite("Images\\course.png", 100, 300);

	// Fonts
	std::stringstream ss;
	ss << std::setw(3) << std::setfill(' ') << 0;
	test = new Font(ss.str().c_str(), 0.0f, 0.0f);
}

TestEnvironment::~TestEnvironment()
{
	delete sprite;
	delete renaud;
	delete test;
}

void TestEnvironment::Start()
{
	Game::Start();
}

void TestEnvironment::Update()
{
	Game::Update();

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

void TestEnvironment::Draw()
{
	Game::Draw();
}

void TestEnvironment::Stop()
{
	Game::Stop();
}
