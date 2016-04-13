#include "TextManager.h"



TextManager::TextManager()
	: Sprite()
	, message_rect(nullptr)
	, sans(nullptr)
{
	message_rect = new SDL_Rect();
	sans = TTF_OpenFont("Sans.ttf", 24);
	white = { 255, 255, 255 };
	message_rect->h = 0;
	message_rect->w = 0;
	message_rect->x = 0;
	message_rect->y = 0;
	
}


TextManager::~TextManager()
{
	delete message_rect;
}

void TextManager::SetsurfaceMessage(const char* message)
{
	surfaceMessage = TTF_RenderText_Solid(sans, message, white);
	this->message = SDL_CreateTextureFromSurface(GRenderer, surfaceMessage);
	std::cout << message << std::endl;
}

void TextManager::Draw()
{
	SDL_RenderCopy(GRenderer, message, NULL, message_rect);
}

void TextManager::Update()
{
	SetsurfaceMessage("TEST");
}
