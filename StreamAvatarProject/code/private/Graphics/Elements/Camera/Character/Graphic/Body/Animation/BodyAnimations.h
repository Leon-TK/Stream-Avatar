#pragma once

#include "BodyTimeAnimation.h"
#include "EnumFrames.h"
//#include "IAnimation.h"

namespace BodyAnimations
{
	class Idle1: public CharAnimation::BodyTimeAnimation
	{
	public:
		Idle1(Base::Body& rBody, const Base::Timer& rTimer, float t);
		Idle1();
		Idle1(Base::Body& rBody);
		
		virtual void update() override final;
		void start();
		void stop();
	};

	class Idle2 : public CharAnimation::BodyTimeAnimation
	{
	public:
		Idle2(Base::Body& rBody, Base::Timer& rTimer, float t);
		Idle2(Base::Body& rBody);
		virtual void update() override final;
		void start();
		void stop();
	};
}
