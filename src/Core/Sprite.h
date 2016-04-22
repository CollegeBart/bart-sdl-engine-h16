#pragma once

#include "Component.h"

class Sprite :
	public Component
{
public:
	Sprite();
	Sprite(const char* path, float x = 0.0f, float y = 0.0f);
	Sprite(const char* path, Rekt* src, Rekt* dst);
	Sprite(const char* path, Rekt* src, float x, float y);

	Sprite(const char* sceneName, const char* path, float x = 0.0f, float y = 0.0f);
	Sprite(const char* sceneName, const char* path, Rekt* src, Rekt* dst);
	Sprite(const char* sceneName, const char* path, Rekt* src, float x, float y);

	virtual ~Sprite();
	
	
	void SetIsFullscreen(bool isFullscreen) { this->isFullScreen = isFullscreen; }
	void SetTexture(const char* path);
	
	float GetX() { return x; }
	float GetY() { return y; }
	void SetX(float x) { this->x = x; }
	void SetY(float y) { this->y = y; }
	Rekt* GetDstRect() { return dstRect; }
	Rekt* GetSrcRect() { return srcRect; }

	
	

protected:
	Rekt* dstRect;
	Rekt* srcRect;
	SDL_Texture* texture;
	float x, y;
	bool isVisible;
	// Byte allignment
	bool spacer1;
	bool spacer2;
	bool spacer3;


	virtual void Update();
	virtual void Draw();
	void SetTexture(SDL_Texture* tex);

private:
	bool isFullScreen;
};

