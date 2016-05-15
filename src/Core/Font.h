#pragma once

#include "Engine.h"
#include "Sprite.h"

class Font 
	: public Sprite
{
public:
	enum ColorFont {CLR_WHITE, CLR_BLACK, CLR_RED, CLR_GREEN, CLR_BLUE, CLR_YELLOW, CLR_COUNT};

	Font();
	Font(const char* text);
	Font(const char* text, float x, float y);
	Font(const char* sceneName, const char* text);
	~Font();
	SDL_Surface* GetSurfaceMessage() { return surfaceMessage; }

	void SetText(const char* text);
	void SetText(const char* text, const Font::ColorFont colorCode);

private:
	TTF_Font* font; 
	SDL_Color white; 
	SDL_Surface* surfaceMessage; 
	SDL_Texture* message; 

	const SDL_Color ColorCodes[CLR_COUNT] = 
	{	{255, 255, 255},
		{0, 0, 0},
		{255, 0, 0},
		{0, 255, 0},
		{0, 0, 255},
		{255, 255, 0} 
	};


};
