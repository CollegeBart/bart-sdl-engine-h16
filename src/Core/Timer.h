#pragma once

#include "SDL.h"

class Timer
{
public:
	Timer();
	~Timer();

	int64_t GetStartTime() { return startTime; }
	int64_t GetCurrTime() { return currTime; }
	int64_t GetTime() { return (currTime - startTime); }
	int64_t GetTimeInSeconds() { return (currTime - startTime) / 1000; }
	Uint64 GetFCurrTime() { return fCurrTime; }
	Uint64 GetFPrevTime() { return fPrevTime; }
	double GetDeltaTime() { return deltaTime; }

	void ResetTimer();
	void StartTimer();
	void Tick();
	void ShowTime();

private:
	bool isRunning;

	Uint64 fPrevTime;
	Uint64 fCurrTime;
	double deltaTime;
	int64_t startTime;
	int64_t currTime;
};

