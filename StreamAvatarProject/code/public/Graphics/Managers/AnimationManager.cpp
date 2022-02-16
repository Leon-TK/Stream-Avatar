#include "AnimationManager.h"
//#include "CameraAnimation.h"
//#include "Camera.h"
#include "EventManager.h"
//#include "BodyAnimations.h"
//#include "MouthAnimations.h"
#include "AnimationFactory.h"
#include "BodyTimeFactory.h"
#include "MouthInputFactory.h"
//#include "EAnimations.h"
#include "AudioApiManager.h"
//#include "BaseFaceElements.h"

Base::AnimationManager::AnimationManager()
{
}

Base::AnimationManager::~AnimationManager()
{
}

void Base::AnimationManager::update()
{
	if (camera->getAnimation() != nullptr) //refactor it
	{
		camera->getAnimation()->update();
	}
	
}

void Base::AnimationManager::setCameraPtr(Base::ViewCamera& rCamera)
{
	this->camera = &rCamera;
}

void Base::AnimationManager::setEventManager(Base::EventManager& rEventmanager)
{
	this->eventManaget = &rEventmanager;
}

void Base::AnimationManager::setRT(AudioApi::AudioApiManager& rRt)
{
	this->rt = &rRt;
}

Base::ViewCamera * const Base::AnimationManager::getCamera()
{
	return camera;
}

Base::EventManager * const Base::AnimationManager::getEventManager()
{
	return eventManaget;
}

void Base::AnimationManager::processEvent(const Message& msg)
{
	switch (msg.type)
	{
	case Base::EMessage::Donation:
	{
		SetDonationAnimation(msg.value);
		break;
	}
	case Base::EMessage::Bits:
	{
		SetBitsAnimation(msg.value);
		break;
	}
	case Base::EMessage::Subscribe:
	{
		SetSUbscribeAnimation(msg.value);
		break;
	}

	default:
		SetIdleAnimation();
		break;
	}
}

//void Base::AnimationManager::SetAnimation(CameraAnimation::CameraAnimation * animation)
//{
//}

void Base::AnimationManager::setDonationAnimation(float value)
{
	
}

void Base::AnimationManager::setSUbscribeAnimation(float value)
{
	
}

void Base::AnimationManager::setBitsAnimation(float value)
{

}

void Base::AnimationManager::setIdleAnimation()
{
	Base::AnimationFactory* af = new Base::BodyTimeFactory(EAnimations::BodyIdle2, &camera->getCharacter()->body);
	camera->getAnimation()->getCharAnim()->SetBodyAnim(af->getAnimation());
	delete af;
	af = new Base::MouthInputFactory(EAnimations::MouthInput1, &camera->getCharacter()->mouth, rt->GetInputBuffer());
	camera->getAnimation()->getCharAnim()->SetMouthAnim(af->getAnimation());
	delete af;
}
