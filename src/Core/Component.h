#pragma once

#include "Common.h"
#include "Collider.h"
#include "Engine.h"

class Component
	: public Collider
{
public:
	friend class Scene;

	Component();
	Component(const char* sceneName);
	~Component();

	bool GetIsNew() { return isNew; }

protected:
	virtual void Start();
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Stop();

// Marc Dallaire - 2016/04/26
// Ajout du Start() pour les nouveaux components créés au runtime. (Semble pas changer grand chose...)
private:
	bool isNew;
};

