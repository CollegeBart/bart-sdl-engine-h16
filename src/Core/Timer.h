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

	void ResetTimer();
	void StartTimer();
	void UpdateTimer();
	void ShowTime();

private:
	bool isRunning;

	int64_t startTime;
	int64_t currTime;


};

