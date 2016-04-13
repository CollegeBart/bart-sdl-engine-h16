#pragma once
#include "Common.h"
#include "Engine.h"
#include "Sprite.h"
class TextManager : public Sprite
{
public:
	TextManager();
	~TextManager();
	void SetsurfaceMessage(const char* message);
	
	void Draw();
	void Update();

private:
	TTF_Font* sans; 
	SDL_Color white; 
	SDL_Surface* surfaceMessage; 
	SDL_Texture* message; 
	SDL_Rect* message_rect;
};

