#pragma once

#include "Sprite.h"


class SpriteAnimation 
	: public Sprite
{
public:
	SpriteAnimation();
	SpriteAnimation(const char * path, Rekt* srcRect, int numFrames);
	SpriteAnimation(const char * path, Rekt* srcRect, float x, float y, int numFrames);
	void SetAnimSpeed(int speed) { animSpeed = speed; }
	~SpriteAnimation();

private:
	int numFrames;
	int currFrame;
	int prevFrameTime;
	int animSpeed;

	void Update();
	virtual void Draw();

	void AnimateUpDown();


	
};

