#pragma once

#include "Sprite.h"


class SpriteAnimation 
	: public Sprite
{
public:
	SpriteAnimation();
	SpriteAnimation(const char * path, Rekt* srcRect, int numFrames);
	SpriteAnimation(const char * path, Rekt* srcRect, float x, float y, int numFrames);
	~SpriteAnimation();

private:
	int numFrames;
	int currFrame;
	int prevFrameTime;

	void Update();
	virtual void Draw();

	void AnimateUpDown();


	
};

