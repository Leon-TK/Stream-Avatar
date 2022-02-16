#pragma once

#include "SFML/System/Clock.hpp"

//#include "IAnimation.h"
#include "MouthAnimation.h"
//#include "Mouth.h"
//#include "Frames.h"
#include "Timer.h"

namespace Frames
{
	enum class EMouth;
}

namespace CharAnimation
{
	//Common animation with time notes
	class MouthTimeAnimation : public CharAnimation::MouthAnimation
	{
	protected:
		sf::Clock m_clock;
		Base::Timer m_timer;
		float m_t;

	public:
		//MouthTimeAnimation(Base::Mouth* mouth, Base::Timer * timer, float t);
		MouthTimeAnimation(Base::Mouth& mouth);
		virtual void update() = 0;
		virtual void start() = 0;
		virtual void stop() = 0;

		void setFrame(Frames::EMouth frame, float t, bool bLast = false);

		//setters
		void setTimer(Base::Timer& rTimer);
		void setTime(float time);
		//getters
		Base::Timer* getTimer();
		float getTime();
		void onFrameChanged() override final;
	};
}
#endif