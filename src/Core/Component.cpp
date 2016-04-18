#include "Component.h"

//std::vector<Component*> Component::components;

Component::Component()
{
	//components.push_back(this);
	GEngine->GetCurrentScene()->AddComponent(this);
}

Component::Component(const char * sceneName)
{
	GEngine->GetScene(sceneName)->AddComponent(this);
}

Component::~Component()
{
}

void Component::Start()
{
}

void Component::Update()
{
}

void Component::Draw()
{
}

void Component::Stop()
{
}
