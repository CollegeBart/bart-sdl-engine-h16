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
}

void Timer::StartTimer()
{
	if (startTime == 0)
	{
		startTime = SDL_GetTicks();
	}
}

void Timer::UpdateTimer()
{
	currTime = SDL_GetTicks();
}

void Timer::ShowTime()
{
	
}
