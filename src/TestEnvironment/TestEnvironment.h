#pragma once

#include "Engine.h"
#include "Common.h"
#include "Collider.h"
#include "Renaud.h"
#include "BackGroundScroller.h"
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
	BackGroundScroller* scrolling;
	Font* test;
	Collider* col;

	// Marc Dallaire - 2016/04/20
	// Test pour l'ajout de components au runtime.
	SpriteAnimation* newSprite1;
	SpriteAnimation* newSprite2;
	bool newSpriteAdded = false;

};

