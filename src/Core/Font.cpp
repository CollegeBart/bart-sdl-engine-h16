#include "Font.h"

Font::Font()
	: Sprite()
	, font(nullptr)
{
	font = TTF_OpenFont("Fonts\\PressStart2P.ttf", 12);
	white = { 255, 255, 255 };
}

Font::Font(const char* text)
	: Sprite()
	, font(nullptr)
{
	font = TTF_OpenFont("Fonts\\PressStart2P.ttf", 12);
	white = { 255, 255, 255 };

	SetText(text);
}

Font::Font(const char* text, float x, float y)
	: Sprite(nullptr, x, y)
	, font(nullptr)
{
	font = TTF_OpenFont("Fonts\\PressStart2P.ttf", 12);
	white = { 255, 255, 255 };

	this->dstRect = dstRect;
	
	SetText(text);
}

Font::Font(const char * sceneName, const char * text)
	: Sprite(sceneName, 1)
	, font(nullptr)
{
	font = TTF_OpenFont("Fonts\\PressStart2P.ttf", 24);
	white = { 255, 255, 255 };

	
	SetText(text);
}

Font::~Font()
{
	TTF_CloseFont(font);
}

void Font::SetText(const char* text)
{
	surfaceMessage = TTF_RenderText_Solid(font, text, white);
	SetTexture(SDL_CreateTextureFromSurface(GRenderer, surfaceMessage));
}
