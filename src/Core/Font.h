#pragma once

#include "Engine.h"
#include "Sprite.h"

class Font 
	: public Sprite
{
public:
	Font();
	Font(const char* text);
	Font(const char* text, SDL_Rect* dstRect);
	~Font();
	SDL_Surface* GetSurfaceMessage() { return surfaceMessage; }

	void SetText(const char* text);

private:

	TTF_Font* font; 
	SDL_Color white; 
	SDL_Surface* surfaceMessage; 
	SDL_Texture* message; 
};

