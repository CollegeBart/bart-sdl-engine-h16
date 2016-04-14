#pragma once
#include"Common.h"
#include "SpriteAnimation.h"
class BackGroundScroller:
	public Sprite
{
public:
	BackGroundScroller();
	BackGroundScroller(int srcH, int srcW, const char* path, float speed, bool isAutoScrolling);
	BackGroundScroller(int srcH, int srcW, const char* path, float speed, float scrollSpeed, bool isAutoScrolling);
	~BackGroundScroller();


private:
	float normalSpeed;
	float scrollSpeed;
	int prevFrameTime;
	bool isAutoScrolling;

	void Update();






};

