#include <iostream>

#include "Body.h"

Base::Body::Body()
{
	loadTexture();
	initSprite();
	mouthAnchor = sf::Vector2f(0,0);
	//animation.SetBody(this);
}

void Base::Body::update()
{
	if (animation != nullptr)
	{
		animation->update();
	}
	
}

void Base::Body::loadTexture()
{
	SpriteElement::loadTexture("img/body/atlas2.png");
}


void Base::Body::initSprite()
{
	//SetCurrentFrame(Frames::EFrames::F1CLOSEEYES);
	float x = 2.0f*3.0f;
	float y = 1.0f*3.0f;
	SpriteElement::initSprite(&x, &y, &texture);
	updateRect(&sf::Vector2i(0, 0), &sf::Vector2i(144, 147));

}

/*
sf::Vector2f * Base::Body::GetmouthJoint()
{
	return &mouthJoint;
}

void Base::Body::SetmouthJoint(sf::Vector2f * mouthJoint)
{
	this->mouthJoint = *mouthJoint;
}
*/

Base::Mouth* Base::Body::getMouth()
{
	return mouth;
}

void Base::Body::setMouth(Base::Mouth& mouth)
{
	this->mouth = mouth;
}

Frames::EBody Base::Body::getCurrentFrame()
{
	return currentFrame;
}

Frames::BaseFrame* Base::Body::setCurrentFrame(Frames::EBody frame)
{
	currentFrame = frame;
	return nullptr;
}

AnimationSpace::Animation* Base::Body::getAnimation()
{
	return animation;
}

void Base::Body::setAnimation(AnimationSpace::Animation& anim)
{
	delete this->animation;
	this->animation = anim;
}

void Base::Body::onPositionChanged()
{
	updateChildPosition();
}

void Base::Body::updateChildPosition()
{
	mouthAnchor += *getPosition(); //-3 - 1
	this->mouth->updateLocation();
	noseAnchor += *getPosition();
	//this->nose->updateLocation();
	eyesAnchor += *getPosition();
	//this->eyesAnchor->updateLocation();
	browAnchor += *getPosition();
	//this->browAnchor->updateLocation();
}

