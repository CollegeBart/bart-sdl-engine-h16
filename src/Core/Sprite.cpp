#include "Sprite.h"

Sprite::Sprite()
	: Component(DEFAULT_SCENE_NAME)
	, x(0.f), y(0.f)
	, isVisible(false)
	, texture(nullptr)
	, dstRect(nullptr)
	, srcRect(nullptr)
	, isFlippedH(false)
{
}

Sprite::Sprite(const char * path, float x, float y)
	: Component(DEFAULT_SCENE_NAME)
	, x(x), y(y)
	, isVisible(true)
	, texture(nullptr)
	, dstRect(nullptr)
	, srcRect(nullptr)
	, isFullScreen(false)
	, isFlippedH(false)
{
	srcRect = new Rekt();
	dstRect = new Rekt();
	dstRect->x = x;
	dstRect->y = y;

	if (path != nullptr)
	{
		SetTexture(path);
		if (texture) 
		{
			int* w = new int();
			int* h = new int();
			
			SDL_QueryTexture(texture, 0, 0, w, h);

			dstRect->w = (const float)*w;
			dstRect->h = (const float)*h;

			delete w;
			delete h;
		}
	}
}

Sprite::Sprite(const char * path, Rekt * src, Rekt * dst)
	: Component(DEFAULT_SCENE_NAME)
	, x(dst->x), y(dst->y)
	, isVisible(true)
	, texture(nullptr)
	, srcRect(src)
	, dstRect(dst)
	, isFlippedH(false)
{
	if (path != nullptr)
	{
		SetTexture(path);
	}
}

Sprite::Sprite(const char * path, Rekt * src, float x, float y)
	: Component(DEFAULT_SCENE_NAME)
	, x(x), y(y)
	, isVisible(true)
	, texture(nullptr)
	, srcRect(src)
	, dstRect(nullptr)
	, isFlippedH(false)
{
	dstRect = new Rekt();
	dstRect->x;
	dstRect->y;

	if (path != nullptr)
	{
		SetTexture(path);
	}
}

Sprite::Sprite(const char * sceneName, const char * path, float x, float y)
	: Component(sceneName)
	, x(x), y(y)
	, isVisible(true)
	, texture(nullptr)
	, srcRect(nullptr)
	, dstRect(nullptr)
	, isFlippedH(false)
{
	dstRect = new Rekt();
	srcRect = new Rekt();
	dstRect->x = x;
	dstRect->y = y;

	if (path != nullptr)
	{
		SetTexture(path);
		if (texture)
		{
			int* w = new int();
			int* h = new int();

			SDL_QueryTexture(texture, 0, 0, w, h);

			dstRect->w = (const float)*w;
			dstRect->h = (const float)*h;

			delete w;
			delete h;
		}
	}
}

Sprite::Sprite(const char * sceneName, const char * path, Rekt * src, Rekt * dst)
	: Component(sceneName)
	, x(dst->x), y(dst->y)
	, isVisible(true)
	, texture(nullptr)
	, srcRect(src)
	, dstRect(dst)
	, isFlippedH(false)
{
	if (path != nullptr)
	{
		SetTexture(path);
	}
}

Sprite::Sprite(const char * sceneName, const char * path, Rekt * src, float x, float y)
	: Component(sceneName)
	, x(x), y(y)
	, isVisible(true)
	, texture(nullptr)
	, srcRect(src)
	, dstRect(nullptr)
	, isFlippedH(false)
{
	dstRect = new Rekt();
	dstRect->x;
	dstRect->y;

	if (path != nullptr)
	{
		SetTexture(path);
	}
}

Sprite::~Sprite()
{
	delete srcRect;
	delete dstRect;
}

void Sprite::SetTexture(SDL_Texture * tex)
{
	this->texture = tex;

	if (dstRect != nullptr)
	{
		if (srcRect->h == 0 && srcRect->w == 0)
		{
			int* w = new int();
			int* h = new int();

			SDL_QueryTexture(texture, 0, 0, w, h);

			dstRect->w = (const float)*w;
			dstRect->h = (const float)*h;

			delete w;
			delete h;
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
	SetTexture(GResources->GetTexture(path));
}

void Sprite::Update()
{
}

void Sprite::Draw()
{
	SDL_RendererFlip flipFlag;

	if (isVisible)
	{
		if (texture)
		{
			dstRect->x = x;
			dstRect->y = y;

			// Marc Dallaire - 2016/04/26
			// Ajout d'une fonction pour virer les sprites horizontalement.
			if (isFlippedH)
				flipFlag = SDL_FLIP_HORIZONTAL;
			else
				flipFlag = SDL_FLIP_NONE;

			if (!isFullScreen)
			{
				if (srcRect->w == 0 || srcRect->h == 0)
				{
					//SDL_RenderCopy(GRenderer, texture, nullptr, &dstRect->GetRect());
					SDL_RenderCopyEx(GRenderer, texture, nullptr, &dstRect->GetRect(), NULL, NULL, flipFlag);
				}
				else
				{
					//SDL_RenderCopy(GRenderer, texture, &srcRect->GetRect(), &dstRect->GetRect());
					SDL_RenderCopyEx(GRenderer, texture, &srcRect->GetRect(), &dstRect->GetRect(), NULL, NULL, flipFlag);
				}
			}
			else
				//SDL_RenderCopy(GRenderer, texture, &srcRect->GetRect(), 0);
				SDL_RenderCopyEx(GRenderer, texture, &srcRect->GetRect(), 0, NULL, NULL, flipFlag);
		}
	}
}


