#include "TestEnvironment.h"

TestEnvironment::TestEnvironment()
	: isDoneTen(false)
	, isDoneHundred(false)
{
	// Sprites
	//sprite = new Sprite("Images\\JeSuisRenaud.png");
	renaud = new Renaud();
	testSprite = new Sprite("Images\\course.png", 100.0f, 300.0f);
	col = new Collider(10.f, 10.f, 20.f, 20.f, b2_dynamicBody, 0);
	
	// Fonts
	std::stringstream ss;
	ss << std::setw(3) << std::setfill(' ') << 0;
	test = new Font(ss.str().c_str(), 0.f, 0.f);

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
	//Font10 delete tous les news (� l'exception du textRect because bugs if done)
	//delete scrolling;

	// Marc Dallaire - 2016/04/27
	// Test pour la destruction de components au runtime.
	//delete renaud;
	//delete testSprite;
	//delete col;
	delete test;
	//delete newSprite1;
	delete newSprite2;
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

	// Marc Dallaire - 2016/04/20
	// Test pour l'ajout de components au runtime.
	if (!newSpriteAdded && GTimer->GetTimeInSeconds() == 5)
	{
		newSpriteAdded = true;
		
		newSprite1 = new SpriteAnimation("Images\\course.png", new Rekt(0.f, 0.f, 100.f, 100.f), 100.0f, 100.0f, 6);
		newSprite1->FlipH();

		newSprite2 = new SpriteAnimation("Images\\course.png", new Rekt(0.f, 0.f, 100.f, 100.f), 200.0f, 200.0f, 6);
		//Font10 --> SetAnimSpeed - 2016/04/25
		//init at 1000, less is faster.
		newSprite2->SetAnimSpeed(500);

		//Font10 --> SetNumFrame - 2016/04/27
		// variable d�j� dans le constructeur, mais ajustable via le setter ci-dessous
		// � SetNumFrame(1), l'anim ne jouera que la premi�re frame (idle)
		newSprite2->SetNumFrame(6);

		//SpriteAnimation(const char * path, Rekt* srcRect, float x, float y, int numFrames);

	}

	// Marc Dallaire - 2016/04/27
	// Test pour la destruction de components au runtime.
	if (GTimer->GetTimeInSeconds() == 10)
	{
		GEngine->GetCurrentScene()->DeleteComponent(renaud);
		GEngine->GetCurrentScene()->DeleteComponent(testSprite);
		GEngine->GetCurrentScene()->DeleteComponent(col);
		//GEngine->GetCurrentScene()->DeleteComponent(test);
		GEngine->GetCurrentScene()->DeleteComponent(newSprite1);
		//GEngine->GetCurrentScene()->DeleteComponent(newSprite2);
		Game::Update();
	}


}
