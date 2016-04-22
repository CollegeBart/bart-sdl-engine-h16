#include "Component.h"

Component::Component()
{
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
