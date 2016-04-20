#include "Timer.h"

Timer::Timer()
	:startTime(0)
	,currTime(0)
{
	
}	

Timer::~Timer()
{
}

void Timer::ResetTimer()
{
	startTime = 0;
	currTime = 0;
	fCurrTime = 0;
	fPrevTime = 0;
	deltaTime = 0;
}

void Timer::StartTimer()
{
	fCurrTime = SDL_GetPerformanceCounter();
	fPrevTime = 0;
	deltaTime = 0;

	if (startTime == 0)
	{
		startTime = SDL_GetTicks();
	}
}

void Timer::Tick()
{
	fPrevTime = fCurrTime;
	fCurrTime = SDL_GetPerformanceCounter();
	deltaTime = (double)((fCurrTime - fPrevTime) * 1000 / SDL_GetPerformanceFrequency());
	currTime = SDL_GetTicks();
}

void Timer::ShowTime()
{
	
}
