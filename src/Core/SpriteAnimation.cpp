#include "SpriteAnimation.h"

SpriteAnimation::SpriteAnimation()
{
}

SpriteAnimation::SpriteAnimation(const char * path, Rekt* srcRect, int numFrames)
	: Sprite(path, srcRect, nullptr)
	, numFrames(numFrames)
	, currFrame(0)
	, prevFrameTime(0)
{
}

SpriteAnimation::SpriteAnimation(const char * path, Rekt* srcRect, float x, float y, int numFrames)
	: Sprite(path, srcRect, x, y)
	, numFrames(numFrames)
	, currFrame(0)
	, prevFrameTime(0)
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
	if (GTimer->GetCurrTime() > (prevFrameTime + (1000/numFrames)))
	{
		srcRect->x += srcRect->w;
		currFrame++;
		prevFrameTime = GTimer->GetCurrTime();
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
