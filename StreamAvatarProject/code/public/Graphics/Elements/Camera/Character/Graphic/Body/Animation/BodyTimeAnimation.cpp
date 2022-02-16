//#include <iostream>

#include "BodyTimeAnimation.h"
#include "Body.h"
#include "EnumFrames.h"
#include "FrameFactory.h"
#include "BodyFrameFactory.h"

CharAnimation::BodyTimeAnimation::BodyTimeAnimation(Base::Body& body)
{
	this->body = body;
}
/*
CharAnimation::BodyTimeAnimation::BodyTimeAnimation(Base::Body * body, Base::Timer * timer, float t)
{
	this->body = body;
	this->timer = timer;
	this->t = t;
}
*/
CharAnimation::BodyTimeAnimation::BodyTimeAnimation()
{
}

void CharAnimation::BodyTimeAnimation::update()
{
}

void CharAnimation::BodyTimeAnimation::start()
{
}

void CharAnimation::BodyTimeAnimation::stop()
{
}

void CharAnimation::BodyTimeAnimation::setFrame(Frames::EBody frame, float t, bool bLast) //TODJ: pointers
{
	if (body->getCurrentFrame() != *frame)
	{
		
		if (*timer.getElapsedTime() > t)
		{
			delete bframe;
			bframe = factory->getFrame(frame);
			bframe->UpdateElement(body);
			//body->mouthAnchor = framedata->mouthAnchor;
			//delete framedata;
			onFrameChanged();
			if (bLast) timer.Reset();
		}
	}
}

Base::Timer* CharAnimation::BodyTimeAnimation::getTimer()
{
	return &timer;
}

float * const CharAnimation::BodyTimeAnimation::getTime()
{
	return &t;
}

void CharAnimation::BodyTimeAnimation::setTimer(const Base::Timer& timer)
{
	this->timer = *timer;
}

void CharAnimation::BodyTimeAnimation::setTimer(float time)
{
	this->t = *time;
}

void CharAnimation::BodyTimeAnimation::onFrameChanged()
{
	body->updateChildPosition();
}


