#pragma once
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


private:



};

