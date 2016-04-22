#pragma once

#include "Engine.h"
#include "Common.h"
#include "Collider.h"
#include "Renaud.h"
#include "BackGroundScroller.h"
#include "Font.h"
#include <iomanip>
#include "Game.h"

class TestEnvironment :
	public Game
{
public:
	TestEnvironment();
	~TestEnvironment();

	void Update();

private:
	Sprite* sprite;
	Sprite* testSprite;
	Renaud* renaud;
	Mix_Music* music;
	//BackGroundScroller* scrolling;
	Font* test;
	Collider* col;
	// Marc Dallaire - 2016/04/20
	// Test pour l'ajout de components au runtime.
	SpriteAnimation* newSprite1;
	SpriteAnimation* newSprite2;
	bool newSpriteAdded = false;
	bool isDoneTen;
	bool isDoneHundred;
	// Byte allignment
	bool spacer2;

};

