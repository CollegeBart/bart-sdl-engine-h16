#include "SpriteAnimation.h"



SpriteAnimation::SpriteAnimation()
{
}

SpriteAnimation::SpriteAnimation(int srcH, int srcW, const char * path, int numFrames)
	:Sprite(srcH, srcW, path)
	, numFrames(numFrames)
	, currFrame(0)
	, prevFrameTime(0)
{
}
SpriteAnimation::SpriteAnimation(int srcH, int srcW, const char * path, float x, float y, int numFrames)
	: Sprite(srcH, srcW, path, x, y)
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
	if (GEngine->GetTimer()->GetCurrTime() > (prevFrameTime + (1000/numFrames)))
	{
		std::cout <<"srcRectx = " << srcRect->x << std::endl;
		srcRect->x += srcRect->w;
		currFrame++;
		prevFrameTime = GEngine->GetTimer()->GetCurrTime();
	}
	std::cout <<"currtime = " << GEngine->GetTimer()->GetCurrTime() << std::endl;
	std::cout << "prevframe time = " << prevFrameTime << std::endl;
	std::cout << "curreFrama  = " << currFrame << std::endl;
}

void SpriteAnimation::Draw()
{
	if (isVisible)
	{
		if (texture)
		{
			dstRect->x = x;
			dstRect->y = y;

			SDL_RenderCopy(GRenderer, texture, srcRect, dstRect);
		}
	}
}
