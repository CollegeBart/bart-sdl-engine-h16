#include "Sprite.h"

Sprite::Sprite()
	: x(0.f), y(0.f)
	, isVisible(true)
	, texture(nullptr)
	, dstRect(nullptr)
	, srcRect(nullptr)
	, isFullScreen(false)
{
	dstRect = new SDL_Rect();
	srcRect = new SDL_Rect();
	dstRect->x = x;
	dstRect->y = y;
}

Sprite::Sprite(float x, float y)
	: x(x), y(y)
	, isVisible(true)
	, texture(nullptr)
	, dstRect(nullptr)
	, srcRect(nullptr)
	, isFullScreen(false)
{
	dstRect = new SDL_Rect();
	srcRect = new SDL_Rect();
	srcRect->h = 0;
	srcRect->w = 0;
	srcRect->x = 0;
	srcRect->y = 0;
	dstRect->x = x;
	dstRect->y = y;
}

Sprite::Sprite(const char * path)
	: x(0.f), y(0.f)
	, isVisible(true)
	, texture(nullptr)
	, dstRect(nullptr)
	, srcRect(nullptr)
	, isFullScreen(false)
{
	dstRect = new SDL_Rect();
	srcRect = new SDL_Rect();
	dstRect->x = x;
	dstRect->y = y;
	SetTexture(path);
}

Sprite::Sprite(const char * path, float x, float y)
	: x(x), y(y)
	, isVisible(true)
	, texture(nullptr)
	, dstRect(nullptr)
	, srcRect(nullptr)
	, isFullScreen(false)
{
	dstRect = new SDL_Rect();
	srcRect = new SDL_Rect();
	srcRect->h = 0;
	srcRect->w = 0;
	srcRect->x = 0;
	srcRect->y = 0;
	dstRect->x = x;
	dstRect->y = y;
	SetTexture(path);	
}
Sprite::Sprite(int srcH, int srcW, const char * path, float x, float y)
	: x(x), y(y)
	, isVisible(true)
	, texture(nullptr)
	, dstRect(nullptr)
	, srcRect(nullptr)
	, isFullScreen(false)
{
	dstRect = new SDL_Rect();
	srcRect = new SDL_Rect();
	dstRect->x = x;
	dstRect->y = y;
	srcRect->x = 0;
	srcRect->y = 0;
	srcRect->h = srcH;
	srcRect->w = srcW;
	SetTexture(path);
}

Sprite::Sprite(int srcH, int srcW, const char * path)
	: x(0.f), y(0.f)
	, isVisible(true)
	, texture(nullptr)
	, dstRect(nullptr)
	, srcRect(nullptr)
	, isFullScreen(false)
{
	dstRect = new SDL_Rect();
	srcRect = new SDL_Rect();
	dstRect->x = x;
	dstRect->y = y;
	srcRect->h = srcH;
	srcRect->w = srcW;
	srcRect->x = 0;
	srcRect->y = 0;
	SetTexture(path);
}

Sprite::Sprite(int srcH, int srcW, const char * path, bool fullScreen)
	: x(0.f), y(0.f)
	, isVisible(true)
	, texture(nullptr)
	, dstRect(nullptr)
	, srcRect(nullptr)
	, isFullScreen(fullScreen)
{
	dstRect = new SDL_Rect();
	srcRect = new SDL_Rect();
	dstRect->x = x;
	dstRect->y = y;
	srcRect->h = srcH;
	srcRect->w = srcW;
	srcRect->x = 0;
	srcRect->y = 0;
	SetTexture(path);
}

Sprite::~Sprite()
{
	delete dstRect;
	delete srcRect;
}

void Sprite::SetTexture(SDL_Texture * tex)
{
	this->texture = tex;

	if (dstRect != nullptr)
	{
		SDL_QueryTexture(tex, 0, 0, &dstRect->w, &dstRect->h);
		if (srcRect->h == 0 && srcRect->w == 0)
		{
			SDL_QueryTexture(tex, 0, 0, &srcRect->w, &srcRect->h);
		}
		else
		{
			dstRect->h = srcRect->h;
			dstRect->w = srcRect->w;
		}
		
	}
	
	
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
			dstRect->x = x;
			dstRect->y = y;

			if (!isFullScreen)
			{
				SDL_RenderCopy(GRenderer, texture, srcRect, dstRect);
			}
			else
				SDL_RenderCopy(GRenderer, texture, srcRect, 0);
		}
	}
}


