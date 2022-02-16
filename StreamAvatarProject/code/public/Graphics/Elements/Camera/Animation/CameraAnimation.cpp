#include "CameraAnimation.h"

CamAnimation::CameraAnimation::CameraAnimation()
{
}

CamAnimation::CameraAnimation::~CameraAnimation()
{
}

CharAnimation::CharacterAnimation * CamAnimation::CameraAnimation::getCharAnim()
{
	return charAnim;
}

void CamAnimation::CameraAnimation::setCharAnima(CharAnimation::CharacterAnimation& charAnim)
{
	this->charAnim = charAnim;
}

void CamAnimation::CameraAnimation::update()
{
	if (!bStop)
	{
		charAnim->update();
	}
	
}

void CamAnimation::CameraAnimation::start()
{
	bStop = 0;
	charAnim->start();
}

void CamAnimation::CameraAnimation::stop()
{
	bStop = 1;
	charAnim->stop();
}
