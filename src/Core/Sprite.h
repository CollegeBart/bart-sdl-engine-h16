#pragma once

#include "Engine.h"
#include "Common.h"

class Sprite :
	public Component
{
public:
	Sprite();
	Sprite(const char* path);
	Sprite(const char* path, float x, float y);
	Sprite(int srcH, int srcW, const char* path, float x, float y);
	Sprite(int srcH, int srcW, const char* path);
	virtual ~Sprite();

	void SetTexture(const char* path);

protected:
	float x, y;
	bool isVisible;
	SDL_Rect* dstRect;
	SDL_Rect* srcRect;
	SDL_Texture* texture;
	
	virtual void Update();
	virtual void Draw();
	void SetTexture(SDL_Texture* tex);

private:
	
};

