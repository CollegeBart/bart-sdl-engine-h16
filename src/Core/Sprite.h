#pragma once

#include "Component.h"
#include "Engine.h"

class Sprite :
	public Component
{
public:
	Sprite();
	Sprite(float x, float y);
	Sprite(const char* path);
	Sprite(const char* path, float x, float y);
	Sprite(int srcH, int srcW, const char* path, float x, float y);
	Sprite(int srcH, int srcW, const char* path);
	Sprite(int srcH, int srcW, const char* path, bool fullScreen);
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
	bool isFullScreen;
};

