#include "BodyTimeFactory.h"
#include "BodyAnimations.h"
Base::BodyTimeFactory::BodyTimeFactory(EAnimations type, Body * body)
{
	this->body = body;
	this->type = type;
}

AnimationSpace::Animation * Base::BodyTimeFactory::getAnimation()
{
	switch (type)
	{
	case EAnimations::BodyIdle1:
		return new BodyAnimations::Idle1(this->body);
		break;
	case EAnimations::BodyIdle2:
		return new BodyAnimations::Idle2(this->body);
		break;
	case EAnimations::MouthInput1:
	case EAnimations::MouthIdle1:
	default:
		return nullptr;
	}
	
}
