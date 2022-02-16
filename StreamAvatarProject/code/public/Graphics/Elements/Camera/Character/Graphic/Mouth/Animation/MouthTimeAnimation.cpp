#include "MouthTimeAnimation.h"
#include "Mouth.h"
#include "EnumFrames.h"
/*
CharAnimation::MouthTimeAnimation::MouthTimeAnimation(Base::Mouth * mouth, Base::Timer * timer, float t)
{
	this->mouth = mouth;
	this->timer = timer;
	this->t = t;
}
*/
CharAnimation::MouthTimeAnimation::MouthTimeAnimation(Base::Mouth * mouth)
{
	this->mouth = mouth;
}

void CharAnimation::MouthTimeAnimation::Update()
{
}

void CharAnimation::MouthTimeAnimation::Start()
{
}

void CharAnimation::MouthTimeAnimation::Stop()
{
}

void CharAnimation::MouthTimeAnimation::SetFrame(Frames::EMouth frame, float t, bool bLast)
{
	if (mouth->getCurrentFrame() != frame)
	{
		if (*timer.getElapsedTime() > t)
		{
			mouth->setCurrentFrame(frame);
			if (bLast) timer.Reset();
		}
	}
}

void CharAnimation::MouthTimeAnimation::setTimer(Base::Timer * timer)
{
	this->timer = *timer;
}

void CharAnimation::MouthTimeAnimation::setTime(float * time)
{
	this->t = *time;
}

Base::Timer * const CharAnimation::MouthTimeAnimation::getTimer()
{
	return &timer;
}

float * const CharAnimation::MouthTimeAnimation::getTime()
{
	return &t;
}

void CharAnimation::MouthTimeAnimation::onFrameChanged()
{
}

