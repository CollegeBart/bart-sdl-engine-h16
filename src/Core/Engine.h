#pragma once

#define DEFAULT_SCENE_NAME "Default"

#include "Common.h"
#include "IScene.h"

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
	int Run();

	Timer* GetTimer() const { return timer; }
	Input* GetInput() const { return input; }
	SDL_Renderer* GetRenderer() const { return renderer; }
	Resources* GetResources() const { return resources; }
	Physics* GetPhysics() const { return physics; }
	std::string GetCurrentSceneName() const { return currentScene; }

	IScene* GetCurrentScene() { return GetScene(currentScene); }
	IScene* GetScene(std::string sceneName) { return scenes[sceneName]; }

	void AddScene(const char* sceneName, IScene* scene)
	{
		scenes[sceneName] = scene;
	}
	void ChangeCurrentScene(const char* sceneName);
	int GetWidth() { return width; }
	int GetHeight() { return height; }

private:
	void Start();
	void Update();
	void Draw();
	void Stop();

	int width;
	int height;

	bool isInitialized;
	bool isRunning;
	bool changingScene;

	Timer* timer;
	SDL_Event* event;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer;
	Physics* physics;

	Input* input;
	Resources* resources;

	std::string currentScene;
	std::map<std::string, IScene*> scenes;
};

