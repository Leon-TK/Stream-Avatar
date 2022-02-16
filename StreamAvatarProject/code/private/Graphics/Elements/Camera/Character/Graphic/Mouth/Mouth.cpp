#include <iostream>

#include "Mouth.h"

Base::Mouth::Mouth()
{
	loadTexture();
	initSprite();
	//animation.SetMouth(this);
}

void Base::Mouth::update()
{
	if (animation != nullptr)
	{
		animation->Update();
	}
}

void Base::Mouth::loadTexture()
{
	SpriteElement::loadTexture("img/mouth/atlas.png");
}

void Base::Mouth::initSprite()
{
	//SetCurrentFrame(Frames::EFrames::MIDLE);
	float x = 23 * 3;
	float y = 33 * 3;
	SpriteElement::initSprite(&x, &y, &texture);
	updateRect(&sf::Vector2i(0, 0), &sf::Vector2i(21, 21));
}


Frames::EMouth Base::Mouth::getCurrentFrame()
{
	return currentFrame;
}

void Base::Mouth::setCurrentFrame(Frames::EMouth frame)
{
	currentFrame = frame;
}

AnimationSpace::Animation* Base::Mouth::getAnimation()
{
	return animation;
}

void Base::Mouth::setAnimation(AnimationSpace::Animation& anim)
{
	delete this->animation;
	this->animation = anim;
}

void Base::Mouth::onPositionChanged()

{
	std::cout << "onposchanger mouth";
}

void Base::Mouth::updateChildPosition()
{
}
