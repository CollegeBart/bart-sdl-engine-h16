#include "SpriteAnimation.h"

SpriteAnimation::SpriteAnimation()
{
}

SpriteAnimation::SpriteAnimation(const char * path, Rekt* srcRect, int numFrames)
	: Sprite(path, srcRect, nullptr)
	, numFrames(numFrames)
	, currFrame(0.0f)
	, prevFrameTime(0.0f)
	, animSpeed(1000)
{
}

SpriteAnimation::SpriteAnimation(const char * path, Rekt* srcRect, float x, float y, int numFrames)
	: Sprite(path, srcRect, x, y)
	, numFrames(numFrames)
	, currFrame(0.0f)
	, prevFrameTime(0.0f)
	, animSpeed(1000)
{
}

SpriteAnimation::~SpriteAnimation()
{

}

void SpriteAnimation::Update()
{
	if (currFrame >= numFrames)
	{
		srcRect->x = 0;
		currFrame = 0;
	}
	
	if (GTimer->GetCurrTime() > (prevFrameTime + (animSpeed/numFrames)))
	{
		srcRect->x += srcRect->w;
		currFrame++;
		prevFrameTime = (int)GTimer->GetCurrTime();
	}
}

void SpriteAnimation::Draw()
{
	if (isVisible)
	{
		if (texture)
		{
			dstRect->x = x;
			dstRect->y = y;

			SDL_RenderCopy(GRenderer, texture, &srcRect->GetRect(), &dstRect->GetRect());
		}
	}
}

void SpriteAnimation::AnimateUpDown()
{

}
