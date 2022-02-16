#include "BodyAnimation.h"

Base::Body * CharAnimation::BodyAnimation::getBody()
{
	return body;
}

void CharAnimation::BodyAnimation::setBody(Base::Body& body)
{
	this->body = body;
}

CharAnimation::BodyAnimation::BodyAnimation()
{
	factory = &bfactory;
}

CharAnimation::BodyAnimation::BodyAnimation(Base::Body& body)
{
	this->body = body;
	factory = &bfactory;
}

void CharAnimation::BodyAnimation::update()
{
	std::cout << "hello";
}

void CharAnimation::BodyAnimation::start()
{
	bStop = 0;
}

void CharAnimation::BodyAnimation::stop()
{
	bStop = 1;
}
