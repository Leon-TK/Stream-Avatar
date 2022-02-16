//#include "CharacterAnimation.h"
#include "Character.h"
#include "CharacterAnimation.h"
//#include "BodyTimeAnimation.h"
//#include "MouthTimeAnimation.h"

/*
void CharAnimation::CharacterAnimation::SetBodyAnim(CharAnimation::BodyAnimation * bodyAnim)
{
	delete this->mouthAnim;
	this->bodyAnim = bodyAnim;
}
*/
/*
void CharAnimation::CharacterAnimation::SetBodyAnim2(AnimationSpace::Animation * bodyAnim2)
{
	delete this->bodyAnim2;
	this->bodyAnim2 = bodyAnim2;
}
*/
/*
void CharAnimation::CharacterAnimation::SetMouthAnim(CharAnimation::MouthAnimation * mouthAnim)
{
	delete this->mouthAnim;
	this->mouthAnim = mouthAnim;
}
*/

void CharAnimation::CharacterAnimation::setBodyAnim(AnimationSpace::Animation& bodyAnim)
{
	character->body.setAnimation(bodyAnim);
}

void CharAnimation::CharacterAnimation::setMouthAnim(AnimationSpace::Animation& mouthAnim)
{
	character->mouth.setAnimation(mouthAnim);
}
	//delete this->mouthAnim2;
	//this->bodyAnim2 = bodyAnim2;


void CharAnimation::CharacterAnimation::setCharacter(Base::CharacterAbstract& character)
{
	this->character = character;
	character->mouth.setParentAnchor(&character->body.mouthAnchor);
}

void CharAnimation::CharacterAnimation::setRt(AudioApi::AudioApiManager& rt)
{
	this->rt = rt;
}


CharAnimation::CharacterAnimation::CharacterAnimation()
{
	//	mouth->SetParentAnchor(&bodyAnim->GetBody()->mouthAnchor);
	//character->mouth.setParentAnchor(&character->body.mouthAnchor);
}

CharAnimation::CharacterAnimation::CharacterAnimation(Base::CharacterAbstract& character, AudioApi::AudioApiManager& rt)
{
	this->character = character; this->rt = rt;
	character->mouth.setParentAnchor(&character->body.mouthAnchor);
}

CharAnimation::CharacterAnimation::~CharacterAnimation()
{
	//delete bodyAnim;
	//delete mouthAnim;
}

void CharAnimation::CharacterAnimation::update()
{
	if (!bStop)
	{
		character->body.update();
		character->mouth.update();
		/*
		if (bodyAnim != nullptr)
		{
			bodyAnim->Update();
		}

		if (mouthAnim != nullptr)
		{
			mouthAnim->Update();
		}
		*/
		/*
		if (bodyAnim2 != nullptr)
		{
			bodyAnim2->Update();
		}
		*/
	}
	
}

void CharAnimation::CharacterAnimation::start()
{
	bStop = 0;
	//bodyAnim->Start();
	//mouthAnim->Start();
}

void CharAnimation::CharacterAnimation::stop()
{
	bStop = 1;
	//bodyAnim->Stop();
	//mouthAnim->Stop();
}
