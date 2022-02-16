#pragma once

#include "CharacterAnimation.h"
#include "Animation.h"

namespace CamAnimation
{

	class CameraAnimation: public AnimationSpace::Animation
	{
	private:
		CharAnimation::CharacterAnimation* m_pCharAnim = nullptr;

	public:
		CameraAnimation();
		~CameraAnimation();

		CharAnimation::CharacterAnimation* getCharAnim();
		void setCharAnima(CharAnimation::CharacterAnimation& rCharAnim);

		void update();
		void start();
		void stop();
	};
}