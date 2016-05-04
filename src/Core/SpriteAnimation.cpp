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
	, isFlippedH(false)
	, isFlippedV(false)
{
}

SpriteAnimation::SpriteAnimation(const char * path, Rekt* srcRect, float x, float y, int numFrames)
	: Sprite(path, srcRect, x, y)
	, numFrames(numFrames)
	, currFrame(0.0f)
	, prevFrameTime(0.0f)
	, animSpeed(1000)
	, isFlippedH(false)
	, isFlippedV(false)
{
}

SpriteAnimation::SpriteAnimation(const char * sceneName, const char * path, Rekt * srcRect, float x, float y, int numFrames)
	: Sprite(sceneName, path, srcRect, x, y)
	, numFrames(numFrames)
	, currFrame(0.0f)
	, prevFrameTime(0.0f)
	, animSpeed(1000)
	, isFlippedH(false)
	, isFlippedV(false)
{
}

SpriteAnimation::~SpriteAnimation()
{

}


void SpriteAnimation::Update()
{
	if (numFrames != 1)
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
	else
	{
		srcRect->x = 0;
		currFrame = 0;
	}
}

void SpriteAnimation::Draw()
{
	SDL_RendererFlip flipFlag;

	if (isVisible)
	{
		if (texture)
		{
			dstRect->x = x;
			dstRect->y = y;

			// Marc Dallaire - 2016/04/26
			// Ajout d'une fonction pour virer les sprites horizontalement.
			if (isFlippedH)
				flipFlag = SDL_FLIP_HORIZONTAL;
			else if (isFlippedV)
				flipFlag = SDL_FLIP_VERTICAL;
			else
				flipFlag = SDL_FLIP_NONE;

			//SDL_RenderCopy(GRenderer, texture, &srcRect->GetRect(), &dstRect->GetRect());
			SDL_RenderCopyEx(GRenderer, texture, &srcRect->GetRect(), &dstRect->GetRect(), NULL, NULL, flipFlag);
		}
	}
}

void SpriteAnimation::AnimateUpDown()
{

}



