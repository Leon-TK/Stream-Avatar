#pragma once

//#include "Timer.h"

namespace AnimationSpace
{

	class AAnimation
	{
	protected:
		bool m_bStop;

	public:
		AAnimation();
		virtual void update() = 0;
		virtual void stop() = 0;
		virtual void start() = 0;
	};

}