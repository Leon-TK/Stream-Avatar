#include "MouthInputFactory.h"
//#include "Mouth.h"
//#include "EAnimations.h"
#include "MouthAnimations.h"

Base::MouthInputFactory::MouthInputFactory(EAnimations type, Mouth * mouth, __int8* bufferArray)
{
	this->mouth = mouth;
	this->type = type;
	this->bufferArray = bufferArray;
}

AnimationSpace::Animation * Base::MouthInputFactory::getAnimation()
{
	switch (type)
	{
	
	case EAnimations::MouthInput1:
		return new MouthAnimations::Input1(mouth, bufferArray);
		break;
	case EAnimations::MouthIdle1:
		return nullptr;
		break;
	case EAnimations::BodyIdle1:
	default:
	return nullptr;
	}
	return nullptr;
}
