#include "Component.h"

Component::Component()
	: isNew(true)
{
	GEngine->GetCurrentScene()->AddComponent(this);
}

Component::Component(const char * sceneName)
	: isNew(true)
{
	GEngine->GetScene(sceneName)->AddComponent(this);
}

Component::~Component()
{
}

void Component::Start()
{
	isNew = false;
}

void Component::Update()
{
	Collider::Update(GTimer->GetDeltaTime());
}

void Component::Draw()
{
}

void Component::Stop()
{
}
