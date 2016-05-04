#include "Engine.h"

// redefinition statique
Engine* Engine::instance = nullptr;

Engine::Engine()
	: isInitialized(false)
	, isRunning(false), changingScene(false)
	, event(0)
	, input(nullptr)
	, resources(nullptr)
	, currentScene(DEFAULT_SCENE_NAME)
{
	timer = new Timer();
	event = new SDL_Event();
	physics = new Physics();
}

Engine::~Engine()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	TTF_Quit();

	delete event;
	delete resources;
	delete input;
	delete timer;
	delete physics;
	SDL_Quit();
}

bool Engine::Init() 
{
	return Init("", SCREEN_WIDTH_DEFAULT, SCREEN_HEIGHT_DEFAULT);
}

bool Engine::Init(const char* title, int width, int height)
{
	if (!isInitialized)
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			std::stringstream ss;
			ss << TITLE_DEFAULT << title;

			window = SDL_CreateWindow(
				ss.str().c_str(), SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, width, height,
				SDL_WINDOW_SHOWN);

			if (window == nullptr)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			}
			else
			{
				renderer = SDL_CreateRenderer(window, -1,
					SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

				if (renderer == nullptr)
				{
					printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
				}
				else
				{
					if (TTF_Init() == -1)
					{
						printf("TTF_Init() Failed: SDL_Error: %s\n", TTF_GetError());
					}
					else
					{
						input = new Input();
						resources = new Resources(renderer);
					}

					if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
					{
						printf("Mix_OpenAudio() Failed: SDL_Error: %s\n", Mix_GetError());
					}
					else
					{
						Mix_Init(0);
					}

					isInitialized = true;
				}
			}
		}
	}
	return isInitialized;
}

int Engine::Run()
{
	Start();

	while (isRunning)
	{
		while (SDL_PollEvent(event) != 0)
		{
			// Update the input system
			input->Poll(*event);
		
			// Process current event
			switch (event->type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;
			default:
				break;
			}

			// Quit if escape key is pressed
			if (GInput->IsKeyReleased(SDL_SCANCODE_ESCAPE))
			{
				isRunning = false;
			}
		}
		Update();
		Draw();
	}

	Stop();

	return 0;
}

void Engine::ChangeCurrentScene(const char * sceneName)
{
	if (scenes[sceneName] == nullptr)
	{
		std::cout << "Error! Scene name \"" << sceneName << "\" does not exist." << std::endl;
	}
	else
	{
		scenes[currentScene]->Stop();
		currentScene = sceneName;
		scenes[currentScene]->Start();
	}
}

void Engine::Start()
{
	isRunning = true;

	scenes[currentScene]->Start();

	timer->ResetTimer();
	timer->StartTimer();
}

void Engine::Update() 
{
	changingScene = false;
	scenes[currentScene]->Update();

	timer->Tick();
	if (!changingScene)
	{
		physics->Step();
	}
}

void Engine::Draw() 
{
	SDL_RenderClear(renderer);
	
	scenes[currentScene]->Draw();

	SDL_RenderPresent(renderer);
}

void Engine::Stop() 
{
	scenes[currentScene]->Stop();
}
