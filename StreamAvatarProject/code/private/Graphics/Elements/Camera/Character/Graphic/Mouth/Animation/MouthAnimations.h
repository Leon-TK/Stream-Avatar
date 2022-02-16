#pragma once

#include "MouthInputAnimation.h"
//#include "MouthTimeAnimation.h"
//#include "IAnimation.h"
//#include "RTManager.h"

namespace Base
{
	class Mouth;
}

namespace MouthAnimations
{
	class Input1: public CharAnimation::MouthInputAnimation
	{
	public:
		Input1(Base::Mouth& mouth, int8_t bufferArray);
		Input1();
		//Input1(Base::Mouth& mouth, int16_t bufferArray);
		
		virtual void update() override final;
		void start();
		void stop();
	};
}
