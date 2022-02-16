#include "Timer.h"
#include "SFML\System\Clock.hpp"
Base::Timer::Timer(): elapsedTime(0.0f), bStop(0)
{
}

void Base::Timer::Update(sf::Clock * clock)
{
	if (!bStop)
	{
		elapsedTime += clock->restart().asSeconds();
	}
	
}

void Base::Timer::Reset()
{
	elapsedTime = 0.0f;
}

void Base::Timer::Stop()
{
	bStop = 1;
	//Reset();
}

void Base::Timer::Start()
{
	bStop = 0;
}

float * const Base::Timer::getElapsedTime()
{
	return &elapsedTime;
}
