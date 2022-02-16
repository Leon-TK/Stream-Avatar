#pragma once

#include "AnimationFactory.h"
//#include "Mouth.h"
#include "EAnimations.h"
//#include "MouthAnimations.h"

namespace Base
{
	//enum class EAnimations;
	class Mouth;
	//class AnimationFactory;

	class MouthInputFactory: public AnimationFactory
	{
	private:
		EAnimations m_type;
		Mouth * m_pMouth = nullptr;
		int8_t m_bufferArray;
	public:
		MouthInputFactory(EAnimations type, Mouth& rMouth, int8_t bufferArray);
		virtual AnimationSpace::Animation* getAnimation() override final;
	};

}
