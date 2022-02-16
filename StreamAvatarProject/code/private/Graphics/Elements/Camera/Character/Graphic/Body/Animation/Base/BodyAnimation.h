#pragma once

#include <iostream>

//#include "OtherElements.h"
//#include "Mouth.h"
#include "Animation.h"
#include "FrameFactory.h"
#include "BodyFrameFactory.h"


namespace Base
{
	class Body;
}

namespace CharAnimation
{
	class BodyAnimation : public AnimationSpace::Animation
	{
	protected:
		Base::Body* m_pBody = nullptr;
		Base::FrameFactory* m_pFactory = nullptr;
		Base::BodyFrameFactory m_bFactory;
		Frames::BaseFrame* m_pBFrame = nullptr;
	public:
		BodyAnimation();
		BodyAnimation(Base::Body& body);
		
		virtual void update();
		virtual void start();
		virtual void stop();

		Base::Body* getBody();
		
		void setBody(Base::Body& body);
		virtual void onFrameChanged() = 0;
	};
}
