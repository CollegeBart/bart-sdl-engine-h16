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


	void SetAnimSpeed(int speed) { animSpeed = speed; }
	void SetNumFrame(int frameNumber) { numFrames = frameNumber; }
	int GetNumFrame() { return numFrames; }



	// Marc Dallaire - 2016/04/26
	// Ajout d'une fonction pour virer les sprites horizontalement.
	void FlipH() { isFlippedH = !isFlippedH; }

private:
	int numFrames;
	int currFrame;
	int prevFrameTime;
	int animSpeed;

	bool isFlippedH;

	virtual void Draw();

	void AnimateUpDown();

protected:

	void Update();
	
};

