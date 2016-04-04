#include "Engine.h"

// redefinition statique
Engine* Engine::instance = nullptr;

Engine::Engine()
	: isInitialized(false)
	, isRunning(false)
{

}

Engine::~Engine()
{
	SDL_FreeSurface(image);
	SDL_DestroyWindow(window);
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
				printf("Window could not be created! SDL_Error", SDL_GetError());
			}
			else
			{
				screen = SDL_GetWindowSurface(window);
				isInitialized = true;
			}
		}
	}
	return isInitialized;
}

void Engine::Run()
{
	Start();

	while (isRunning)
	{
	
		Update();
	
		//if (keyPressed != 'esc')
		//	isRunning = false;
	}

	Stop();
}

void Engine::Start() 
{
	isRunning = true;

	//std::vector<Component*>::iterator iter;
	//for (iter = Component::components.begin();
	//iter != Component::components.end();
	//	iter++)
	//{
	//	(*iter)->Start();
	//}
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
	//std::vector<Component*>::iterator iter;
	//for (iter = Component::components.begin();
	//iter != Component::components.end();
	//	iter++)
	//{
	//	(*iter)->Draw();
	//}
}

void Engine::Stop() 
{
	//std::vector<Component*>::iterator iter;
	//for (iter = Component::components.begin();
	//iter != Component::components.end();
	//	iter++)
	//{
	//	(*iter)->Stop();
	//}

	
}
