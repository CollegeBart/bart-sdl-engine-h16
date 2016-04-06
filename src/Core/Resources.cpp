#include "Resources.h"

Resources::Resources()
	: renderer(nullptr)
{

}

Resources::Resources(SDL_Renderer * renderer)
	: renderer(renderer)
{

}

Resources::~Resources()
{

}

SDL_Texture * Resources::GetTexture(const char * path)
{
	if (textures[path] == nullptr)
	{
		if (LoadTexture(path))
		{
			return textures[path];
		}
	}
	return textures[path];
}

bool Resources::LoadTexture(const char * path)
{
	SDL_Texture* image = IMG_LoadTexture(renderer, path);
	if (nullptr == image)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
		return false;
	}
	textures[path] = image;
	return true;
}
