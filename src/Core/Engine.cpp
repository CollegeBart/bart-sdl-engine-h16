#include "Engine.h"

// redefinition statique
Engine* Engine::instance = nullptr;

Engine::Engine()
{

}

Engine::~Engine()
{

}

bool Engine::Init() 
{
	return false;
}

void Engine::Start() 
{

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

}

void Engine::Stop() 
{

}
