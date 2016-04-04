#pragma once

#include <vector>
#include "Component.h"

class Engine
{

#pragma region SINGLETON
public:
	static Engine* GetInstance()
	{
		if (instance == nullptr)
			instance = new Engine();
		return instance;
	}

private:
	Engine();
	~Engine();

	static Engine* instance;
#pragma endregion

public:

	bool Init();
	void Start();
	void Update();
	void Draw();
	void Stop();


private:

	

};

