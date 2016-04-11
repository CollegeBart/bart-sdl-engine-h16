#pragma once

#include "Engine.h"
#include "Common.h"

class Sprite :
	public Component
{
public:
	Sprite();
	Sprite(const char* path);
	Sprite(const char* path, float x, float y);
	virtual ~Sprite();

	void SetTexture(const char* path);

protected:
	virtual void Update();
	virtual void Draw();

private:
	void SetTexture(SDL_Texture* tex);

	float x, y;
	bool isVisible;
	SDL_Rect rect;
	SDL_Texture* texture;
};

