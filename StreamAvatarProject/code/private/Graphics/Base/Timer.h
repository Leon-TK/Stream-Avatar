#pragma once

//#include "SFML\System\Clock.hpp"

namespace sf
{
	class Clock;
}
namespace Base
{
	class Timer
	{
	private:
		bool m_bStop;
		float m_elapsedTime;

	public:
		Timer();

		void update(const sf::Clock& rClock);

		void reset();
		void stop();
		void start();

		float getElapsedTime();
	};
}
