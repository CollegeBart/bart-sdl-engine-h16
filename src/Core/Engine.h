#pragma once

#include "Common.h"
#include "Resources.h"

class Engine
{

#pragma region SINGLETON
public:
	static Engine* GetInstance()
	{
		if (instance == nullptr)
			instance = new Engine();
		return instance;
	}

private:
	Engine();
	~Engine();

	static Engine* instance;
#pragma endregion

public:
	bool Init();
	bool Init(const char* title, int width, int height);
	void Run();

	SDL_Renderer* GetRenderer() { return renderer; }
	Resources* GetResources() { return resources; }
	
private:
	void Start();
	void Update();
	void Draw();
	void Stop();

	bool isInitialized;
	bool isRunning;

	SDL_Event* event;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer;

	Resources* resources;
};

