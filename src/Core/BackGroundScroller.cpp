#include "BackGroundScroller.h"



BackGroundScroller::BackGroundScroller()
	: Sprite()
	, normalSpeed(0)
	, scrollSpeed(0)
	, prevFrameTime(0)
	, isAutoScrolling(false)
{
}

BackGroundScroller::BackGroundScroller(int srcH, int srcW, const char * path, float speed, bool isAutoScrolling)
	: Sprite(srcH, srcW, path, true)
	, normalSpeed(speed)
	, prevFrameTime(0)
	, isAutoScrolling(isAutoScrolling)
{
}

BackGroundScroller::BackGroundScroller(int srcH, int srcW, const char * path, float speed, float scrollSpeed, bool isAutoScrolling)
	: Sprite(srcH, srcW, path, true)
	, normalSpeed(speed)
	, scrollSpeed(scrollSpeed)
	, prevFrameTime(0)
	, isAutoScrolling(isAutoScrolling)
{
}


BackGroundScroller::~BackGroundScroller()
{
}

void BackGroundScroller::Update()
{
	if (isAutoScrolling)
	{
		if (GTimer->GetCurrTime() > (prevFrameTime + 100))
		{
			srcRect->x += normalSpeed;
			prevFrameTime = GTimer->GetCurrTime();
		}
	}
	else
	{	// Detect if player is at X in screen make image scroll to the right
		if (true)
		{
			srcRect->x += normalSpeed;
		}
		// Else if at oposite X scroll to the left
		else if (true)
		{
			srcRect->x -= normalSpeed;
		}
	}


}
