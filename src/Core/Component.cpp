#include "Component.h"

std::vector<Component*> Component::components;

// Marc Dallaire - 2016/04/20
// Initialisation du tableau secondaire pour l'ajout de components au runtime.
std::vector<Component*> Component::newComponents;

Component::Component()
{
	// Marc Dallaire - 2016/04/20
	//	components.push_back(this);
	newComponents.push_back(this);
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
