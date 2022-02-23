#pragma once

#include "SFML/System/Clock.hpp"

//#include "IAnimation.h"
//#include "OtherElements.h"
#include "BodyAnimation.h"
#include "Timer.h"
//#include "Frames.h"

namespace Frames
{
	enum class EBody;
}

namespace CharAnimation
{
	//common animation with time flags
	class BodyTimeAnimation : public CharAnimation::BodyAnimation
	{
	protected:
		sf::Clock m_clock;
		Base::Timer m_timer;
		float m_t;
	public:
		BodyTimeAnimation(Base::Body& body);
		//BodyTimeAnimation(Base::Body& body, const Base::Timer& timer, float t);
		BodyTimeAnimation();

		virtual void update() = 0;
		virtual void start() = 0;
		virtual void stop() = 0;


		void setFrame(Frames::EBody frame, float t, bool bLast = false);

		Base::Timer* getTimer();
		float getTime();
		
		void setTimer(const Base::Timer& timer);
		void setTimer(float time);
		void onFrameChanged() override final;
	};
}