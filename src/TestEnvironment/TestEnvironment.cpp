#include "TestEnvironment.h"

TestEnvironment::TestEnvironment()
{
}

TestEnvironment::~TestEnvironment()
{
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
}
