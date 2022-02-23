#pragma once

#include "AnimationFactory.h"
//#include "OtherElements.h"
#include "EAnimations.h"
//#include "BodyAnimations.h"

namespace Base
{
	class Body;

	class BodyTimeFactory: public AnimationFactory
	{
	private:
		EAnimations m_type;
		Body* m_pBody = nullptr;
		
	public:
		BodyTimeFactory(EAnimations type, Body& body);
		virtual AnimationSpace::Animation* getAnimation() override final;
	};

}
