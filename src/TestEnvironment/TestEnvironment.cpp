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
	
	col = new Collider(10, 10, 20, 20, b2_dynamicBody, 0);
	

	// Fonts
	SDL_Rect* textRect = new SDL_Rect();
	std::stringstream ss;
	ss << std::setw(3) << std::setfill(' ') << 0;
	test = new Font(ss.str().c_str(), textRect);

	// Music
	music = Mix_LoadMUS("Music\\theme.wav");
	if (music == NULL)
	{
		std::cout << Mix_GetError() << std::endl;
	}
	Mix_PlayMusic(music, 1);
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

	// Marc Dallaire - 2016/04/20
	// Test pour l'ajout de components au runtime.
	if (!newSpriteAdded)
	{
		newSpriteAdded = true;
		newSprite1 = new SpriteAnimation(100, 100, "Images\\course.png", 100.0f, 100.0f, 6);
		newSprite2 = new SpriteAnimation(100, 100, "Images\\course.png", 200.0f, 200.0f, 6);
	}

}
