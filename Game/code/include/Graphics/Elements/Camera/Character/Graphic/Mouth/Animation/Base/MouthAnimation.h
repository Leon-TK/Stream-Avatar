#pragma once

#include "Animation.h"
#include "FrameFactory.h"
#include "MouthFrameFactory.h"
//#include "Mouth.h"

namespace Base
{
	class Mouth;
}

namespace CharAnimation
{
	class AMouthAnimation : public AnimationSpace::Animation
	{
	protected:
		Base::Mouth* m_pMouth = nullptr;
		Base::FrameFactory* m_pFactory = nullptr;
		Base::MouthFrameFactory m_baseFactory;
		Frames::BaseFrame* m_pBaseframe = nullptr;

	public:
		MouthAnimation();
		MouthAnimation(Base::Mouth& rMouth);
		
		virtual void update();
		virtual void start();
		virtual void stop();

		Base::Mouth* getMouth();

		void setMouth(Base::Mouth& rMouth);
		virtual void onFrameChanged() = 0;
	};
}
