#pragma once
#include "Common.h"
class Timer
{
public:
	Timer();
	~Timer();

	int GetStartTime() { return startTime; }
	int GetCurrTime() { return currTime; }
	int GetTime() { return (currTime - startTime); }
	int GetTimeInSeconds() { return (currTime - startTime) / 1000; }
	Uint64 GetFCurrTime() { return fCurrTime; }
	Uint64 GetFPrevTime() { return fPrevTime; }
	double GetDeltaTime() { return deltaTime; }

	void ResetTimer();
	void StartTimer();
	void UpdateTimer();
	void ShowTime();

private:
	bool isRunning;

	Uint64 fPrevTime;
	Uint64 fCurrTime;
	double deltaTime;
	int64_t startTime;
	int64_t currTime;


};

