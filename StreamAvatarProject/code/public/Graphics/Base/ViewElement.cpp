#include "ViewElement.h"

Base::ViewElement::ViewElement()
{
	setVisible(1);
	setPos(&sf::Vector2f(0,0));

}

void Base::ViewElement::Update()
{
}

void Base::ViewElement::setVisible(bool val)
{
	bVisible = val;
}

const bool Base::ViewElement::getVisible()
{
	return bVisible;
}

void Base::ViewElement::setPos(sf::Vector2f * pos)
{
	this->pos = *pos;
}

const sf::Vector2f * Base::ViewElement::getPos()
{
	return &pos;
}

void Base::ViewElement::addOffset(sf::Vector2f * offset)
{
	pos += *offset;
}
