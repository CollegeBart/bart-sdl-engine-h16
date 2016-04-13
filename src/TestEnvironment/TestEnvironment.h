#pragma once

#include "Engine.h"
#include "Common.h"

#include "Renaud.h"
#include "Font.h"
#include <iomanip>

class TestEnvironment :
	public Component
{
public:
	TestEnvironment();
	~TestEnvironment();

	void Update();

private:
	bool isDoneTen;
	bool isDoneHundred;
	Sprite* sprite;
	Sprite* testSprite;
	Renaud* renaud;
	Font* test;
};

