#include "Camera.h"

Base::ViewCamera::ViewCamera(const sf::Vector2f& rPos)
{
	//Animation.getCharAnim()->SetCharacter(&character);
	Animation.setCharAnima(character.getCharacterAnimation());
}

Base::ViewCamera::ViewCamera()
{
}

Base::ViewCamera::~ViewCamera()
{
	//delete Animation;
}

void Base::ViewCamera::onPositionChanged()
{
}

void Base::ViewCamera::updateChildAnchor()
{
}

void Base::ViewCamera::setPos(const sf::Vector2f& rPos)
{
	ViewElement::setPos(rPos);
	onPositionChanged();
}

void Base::ViewCamera::setVisible(bool val)
{
	ViewElement::setVisible(val);
	character.setVisible(val);
	camText.setVisible(val);
	bg.setVisible(val);
	fg.setVisible(val);
}


void Base::ViewCamera::setAnimation(CamAnimation::CameraAnimation& rAnim)
{
	this->Animation = &rAnim;
}

CamAnimation::CameraAnimation* Base::ViewCamera::getAnimation()
{
	return &Animation;
	//character.getCharacterAnimation();
}

Base::CharacterAbstract * Base::ViewCamera::getCharacter()
{
	return &character;
}

void Base::ViewCamera::deleteAnimation()
{
	
	//delete Animation;
}
