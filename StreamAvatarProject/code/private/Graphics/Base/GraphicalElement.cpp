#include "GraphicalElement.h"
#include <iostream>

void Base::SpriteElement::updateLocation()
{
	sprite.setPosition(*m_parentAnchor + m_localOffset);
}

Base::SpriteElement::SpriteElement()
{
}

void Base::SpriteElement::Update()
{
	//UpdatePosition();
}

void Base::SpriteElement::LoadTexture(std::string path)
{
	if (!texture.loadFromFile(path))
	{
		std::cout << "Loading png is failed";
	}
}

void Base::SpriteElement::InitSprite(float* x, float* y, sf::Texture* texture)
{
	sprite.setTexture(*texture);
	//SetCurrentFrame(Frames::EFrames::MIDLE);
	sprite.setPosition(*x, *y);
	sprite.setTextureRect(rect);
}
/*
void Base::GraphicalElement::UpdatePositionFromParent(sf::Vector2f* parentAnchor)
{
	SetPosition(this->m_parentAnchor);
	//SetPosition(parentAnchor); //TODO: awoid Vector2f cast. m_ParentAnchor must be Vector2f instead
	//std::cout << this->getSprite()->getPosition().x;
}
*/
void Base::SpriteElement::UpdateRect(int* x, int*y, int* sx, int* xy)
{
	setRectParams(x, y, sx, xy);
	sprite.setTextureRect(rect);
}
void Base::SpriteElement::UpdateRect(sf::Vector2i* pos, sf::Vector2i* size)
{
	setRectParams(pos, size);
	sprite.setTextureRect(rect);
}

void Base::SpriteElement::UpdateOffset(sf::Vector2f* offset)
{
	sprite.setPosition(*m_parentAnchor + *offset); //TODO: offset must be v2f 
	//std::cout << m_parentAnchor->x;
	//std::cout << std::endl;
	//std::cout << m_parentAnchor->y;
	//std::cout << std::endl;
}
/*
sf::Sprite * const Base::GraphicalElement::getSprite()
{
	return &sprite;
}
*/
sf::IntRect * const Base::SpriteElement::getRect()
{
	return nullptr;
}

sf::Texture * const Base::SpriteElement::getTexture()
{
	return nullptr;
}

const sf::Vector2f * const Base::SpriteElement::getPosition()
{
	return &sprite.getPosition();
}

Frames::BaseFrame * const Base::SpriteElement::getFrame()
{
	return frame;
}

const sf::Sprite * const Base::SpriteElement::getSprite()
{
	return &sprite;
}

void Base::SpriteElement::setRectParams(int* xp, int* yp, int* xs, int* ys)
{
	rect.left = *xp;
	rect.top = *yp;
	rect.width = *xs;
	rect.height = *ys;
}

void Base::SpriteElement::setRectParams(sf::Vector2i * loc, sf::Vector2i * size)
{
	rect.left = loc->x;
	rect.top = loc->y;
	rect.width = size->x;
	rect.height = size->y;
}

void Base::SpriteElement::SetPosition(float * x, float * y)
{
	sprite.setPosition(*x, *y);
	onPositionChanged();
}

void Base::SpriteElement::SetPosition(sf::Vector2f * poc)
{
	sprite.setPosition(*poc);
	onPositionChanged();
}

void Base::SpriteElement::setSpriteTexture(sf::Texture * texture)
{
	sprite.setTexture(*texture);

}

void Base::SpriteElement::setFrame(Frames::BaseFrame * frame)
{
	this->frame = frame;
}
void Base::SpriteElement::setParentAnchor(sf::Vector2f * anchor)
{
	m_parentAnchor = anchor;
}
/*
void Base::Element::setParentAnchor(float * x, float * y)
{
	m_parentAnchor->x = *x;
	m_parentAnchor->y = *y;
}
*/
void Base::SpriteElement::setLocalOffset(sf::Vector2f * offset)
{
	m_localOffset = *offset;
}

void Base::SpriteElement::setLocalOffset(float * x, float * y)
{
	m_localOffset.x = *x;
	m_localOffset.y = *y;
}

const sf::Vector2f * const Base::SpriteElement::getParentAnchor()
{
	return m_parentAnchor;
}

const sf::Vector2f * const Base::SpriteElement::getLocalOffset()
{
	return &m_localOffset;
}

void Base::SpriteElement::setVisible(bool value)
{
	this->bVisible = value;
}

bool Base::SpriteElement::getVisible()
{
	return bVisible;
}
