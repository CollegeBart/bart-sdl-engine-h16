#pragma once

#include "Engine.h"
#include "Common.h"

#include "Renaud.h"
#include "Font.h"

class TestEnvironment :
	public Component
{
public:
	TestEnvironment();
	~TestEnvironment();

	void Update();

private:
	Sprite* sprite;
	Renaud* renaud;
	Font* test;
};

