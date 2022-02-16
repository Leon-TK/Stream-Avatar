#include "MouthAnimation.h"

Base::Mouth * CharAnimation::MouthAnimation::getMouth()
{
	return mouth;
}

void CharAnimation::MouthAnimation::setMouth(Base::Mouth& mouth)
{
	this->mouth = mouth;
}

void CharAnimation::MouthAnimation::start()
{
	bStop = 0;
}

void CharAnimation::MouthAnimation::stop()
{
	bStop = 1;
}

CharAnimation::MouthAnimation::MouthAnimation()
{
	factory = &bfactory;
}

CharAnimation::MouthAnimation::MouthAnimation(Base::Mouth& mouth)
{
	this -> mouth = mouth;
	factory = &bfactory;
}

void CharAnimation::MouthAnimation::update()
{
}
