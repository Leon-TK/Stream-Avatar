#pragma once

//#include "CameraAnimation.h"
#include "Camera.h"
//#include "EventManager.h"
//#include "BodyAnimations.h"
//#include "MouthAnimations.h"
//#include "AnimationFactory.h"
//#include "BodyTimeFactory.h"
//#include "MouthInputFactory.h"
//#include "EAnimations.h"
//#include "RTManager.h"
//#include "BaseFaceElements.h"

namespace AudioApi
{
	class  AudioApiManager;
}

namespace Base
{
	//class CameraAbstract;
	class  EventManager;
	struct Message;

	class AnimationManager
	{
	private:

		//BodyAnimations::Idle1 anim1; // = new BodyAnimations::Idle1(&gm.GetCamera()->character.body, &timer, 1.0f);
		//MouthAnimations::Input1 anim2; // = new MouthAnimations::Input1(&gm.GetCamera()->character.mouth);
		Base::ViewCamera *      m_pCamera = nullptr; //parent delete
		Base::EventManager*         m_pEventManaget = nullptr;
		//Event manager

	protected:
		AudioApi::AudioApiManager* m_pRt = nullptr; //?
		
	public:

		AnimationManager            ();
		~AnimationManager           ();

		//tick
		void update                 ();
		
		void processEvent            (Message msg);
		//void SetAnimation(CamAnimation::CameraAnimation* animation);
		void setDonationAnimation	(float value);
		void setSUbscribeAnimation  (float value);
		void setBitsAnimation       (float value);
		void setIdleAnimation       ();
		//void Subscribe();

		//setters
		void setCameraPtr			(Base::ViewCamera& rCamera);
		void setEventManager        (Base::EventManager& rEventmanager);
		void setRT                  (AudioApi::AudioApiManager& rRt);
		//getters
		Base::ViewCamera* getCamera();
		Base::EventManager* getEventManager();

	};

}
