#include "Sprite.h"

Sprite::Sprite()
	: x(0.f), y(0.f)
	, isVisible(true)
	, texture(nullptr)
	, srcRect(nullptr)
{
}

Sprite::Sprite(const char * path)
	: x(0.f), y(0.f)
	, isVisible(true)
	, texture(nullptr)
	, srcRect(nullptr)
{
	SetTexture(path);
}

Sprite::Sprite(const char * path, float x, float y)
	: x(x), y(y)
	, isVisible(true)
	, texture(nullptr)
	, srcRect(nullptr)
{
	SetTexture(path);
}
Sprite::Sprite(int srcH, int srcW, const char * path, float x, float y)
	: x(x), y(y)
	, isVisible(true)
	, texture(nullptr)
{
	srcRect->x = srcH;
	srcRect->y = srcW;
	SetTexture(path);
}

Sprite::Sprite(int srcH, int srcW, const char * path)
	: x(0.f), y(0.f)
	, isVisible(true)
	, texture(nullptr)
{
	srcRect->x = srcH;
	srcRect->y = srcW;
	SetTexture(path);
}

Sprite::~Sprite()
{
}

void Sprite::SetTexture(SDL_Texture * tex)
{
	this->texture = tex;

	SDL_QueryTexture(tex, 0, 0, &rect->w, &rect->h);
}

void Sprite::SetTexture(const char * path)
{
	SetTexture(
		GResources->GetTexture(path));
}

void Sprite::Update()
{
}

void Sprite::Draw()
{
	if (isVisible)
	{
		if (texture)
		{
			rect->x = x;
			rect->y = y;

			SDL_RenderCopy(GRenderer, texture, srcRect, rect);
		}
	}
}


