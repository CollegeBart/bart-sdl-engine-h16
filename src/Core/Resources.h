#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <map>

class Resources
{
public:
	Resources();
	Resources(SDL_Renderer* renderer);
	
	~Resources();

	SDL_Texture* GetTexture(const char* path);

private:
	SDL_Renderer* renderer;

	bool LoadTexture(const char* path);
	bool LoadFont(const char* path);

	std::map<const char*, SDL_Texture*> textures;
};

