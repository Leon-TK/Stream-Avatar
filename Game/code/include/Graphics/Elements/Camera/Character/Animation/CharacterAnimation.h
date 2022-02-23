#pragma once

#include "Animation.h"

namespace Base
{
	class CharacterAbstract;
	class Body;
	class Mouth;
}
namespace AudioApi
{
	class AudioApiManager;
}
namespace CharAnimation
{
	class BodyAnimation;
	class MouthAnimation;
}


namespace CharAnimation
{

	class CharacterAnimation : public AnimationSpace::Animation
	{
	private:
		//Util members//
		AudioApi::AudioApiManager* m_pRt = nullptr;
		Base::CharacterAbstract* m_pCharacter = nullptr;

		//Elemet's animations//

		//AnimationSpace::Animation * bodyAnim2;
		//AnimationSpace::Animation * mouthAnim2;
		//CharAnimation::BodyAnimation * bodyAnim;   //each part of character has animation
		//CharAnimation::MouthAnimation * mouthAnim;  // mouth can be as sequence or as microphone input dependet animation

		//Base::Timer *				 bodyTimer;  // TODO: shoud be in derived classes?
		//Base::Timer *				 mouthTimer; // TODO: shoud be in derived classes?

	public:

		CharacterAnimation();
		CharacterAnimation(Base::CharacterAbstract& rCharacter, AudioApi::AudioApiManager& rRt);
		~CharacterAnimation();

		//Setters//
		//void setBodyAnim			 (const CharAnimation::BodyAnimation& rBodyAnim);
		void setBodyAnim			 (const AnimationSpace::Animation& rBodyAnim);
		//void setMouthAnim			 (const CharAnimation::MouthAnimation& rMouthAnim);
		void setMouthAnim            (const AnimationSpace::Animation& rMouthAnim);
		void setCharacter			 (const Base::CharacterAbstract& rCharacter);
		void setRt(AudioApi::AudioApiManager& rRt);
		//void setBodyTimer(const Base::Timer& rTimer);
		//void setMouthTimer(const Base::Timer& rTimer);

		void update();
		void start();
		void stop();
	};

}
