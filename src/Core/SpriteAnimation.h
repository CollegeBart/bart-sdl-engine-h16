#pragma once
#include "Sprite.h"
#include "Common.h"
class SpriteAnimation : public Sprite
{
public:
	SpriteAnimation();
	SpriteAnimation(int srcH, int srcW, const char * path, int numFrames);
	SpriteAnimation(int srcH, int srcW, const char * path, float x, float y, int numFrames);
	~SpriteAnimation();

private:
	int numFrames;
	int currFrame;
	int prevFrameTime;
	void Update();
	virtual void Draw();


	
};

