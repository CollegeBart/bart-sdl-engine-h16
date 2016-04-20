#pragma once

#include "Game.h"
#include "Renaud.h"
//#include "BackGroundScroller.h"
#include "Font.h"
#include <iomanip>

class TestEnvironment :
	public Game
{
public:
	TestEnvironment();
	~TestEnvironment();

protected:
	void Start();
	void Update();
	void Draw();
	void Stop();

private:
	bool isDoneTen;
	bool isDoneHundred;
	Sprite* sprite;
	Sprite* testSprite;
	Renaud* renaud;
	//BackGroundScroller* scrolling;
	Font* test;
};

