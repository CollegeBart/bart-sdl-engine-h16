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

	Timer* GetTimer() { return timer; }
	Input* GetInput() { return input; }
	SDL_Renderer* GetRenderer() { return renderer; }
	Resources* GetResources() { return resources; }
	Physics* GetPhysics() { return physics; }
	std::string GetCurrentSceneName() { return currentScene; }

	IScene* GetCurrentScene() { return GetScene(currentScene); }
	IScene* GetScene(std::string sceneName) { return scenes[sceneName]; }

	void AddScene(const char* sceneName, IScene* scene)
	{
		scenes[sceneName] = scene;
	}
	void ChangeCurrentScene(const char* sceneName)
	{
		if (scenes[sceneName] == nullptr)
		{
			std::cout << "Error! Scene name \"" << sceneName << "\" does not exist." << std::endl;
		}
		else
			currentScene = sceneName;
		
	}

private:
	void Start();
	void Update();
	void Draw();
	void Stop();

	bool isInitialized;
	bool isRunning;

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

