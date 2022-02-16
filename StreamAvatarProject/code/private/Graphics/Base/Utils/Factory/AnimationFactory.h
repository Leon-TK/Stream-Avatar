#pragma once

#include "Animation.h"

namespace Base
{
	class AnimationFactory
	{
	public:
		virtual ~AnimationFactory() {};
		virtual AnimationSpace::Animation* getAnimation() = 0;
	};
}