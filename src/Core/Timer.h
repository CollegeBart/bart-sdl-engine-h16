#pragma once

#include "SDL.h"

class Timer
{
public:
	Timer();
	~Timer();

	int64_t GetStartTime() const { return startTime; }
	int64_t GetCurrTime() const { return currTime; }
	int64_t GetTime() const { return (currTime - startTime); }
	int64_t GetTimeInSeconds() const { return (currTime - startTime) / 1000; }
	Uint64 GetFCurrTime() const { return fCurrTime; }
	Uint64 GetFPrevTime() const { return fPrevTime; }
	double GetDeltaTime() const { return deltaTime; }

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

