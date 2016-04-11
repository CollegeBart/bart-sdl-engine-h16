#include "Engine.h"

// redefinition statique
Engine* Engine::instance = nullptr;

Engine::Engine()
	: isInitialized(false)
	, isRunning(false)
	, event(0)
	, input(nullptr)
	, resources(nullptr)
{
	event = new SDL_Event();
}

Engine::~Engine()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	delete event;
	delete resources;
	delete input;

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
					input = new Input();
					resources = new Resources(renderer);
					isInitialized = true;
				}
			}
		}
	}
	return isInitialized;
}

void Engine::Run()
{
	Start();

	while (isRunning || GInput->IsKeyReleased(SDL_SCANCODE_ESCAPE)))
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
}

void Engine::Start() 
{
	isRunning = true;

	std::vector<Component*>::iterator iter;
	for (iter = Component::components.begin();
	iter != Component::components.end();
		iter++)
	{
		(*iter)->Start();
	}
}

void Engine::Update() 
{
	std::vector<Component*>::iterator iter;
	for (iter = Component::components.begin(); 
		 iter != Component::components.end();
		 iter++)
	{
		(*iter)->Update();
	}
}

void Engine::Draw() 
{
	SDL_RenderClear(renderer);

	std::vector<Component*>::iterator iter;
	for (iter = Component::components.begin();
	iter != Component::components.end();
		iter++)
	{
		(*iter)->Draw();
	}

	SDL_RenderPresent(renderer);
}

void Engine::Stop() 
{
	std::vector<Component*>::iterator iter;
	for (iter = Component::components.begin();
	iter != Component::components.end();
		iter++)
	{
		(*iter)->Stop();
	}
}
