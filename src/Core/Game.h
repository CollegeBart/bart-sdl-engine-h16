#pragma once

#include "Scene.h"

class Game :
	public Scene
{
public:
	Game();
	virtual ~Game();

protected:
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Stop();

};

