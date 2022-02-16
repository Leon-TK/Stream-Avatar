#include "Element.h"

Base::Element::Element()
{
	//m_parentAnchor = sf::Vector2f(0,0);
	m_localOffset = sf::Vector2f(0, 0);
}

void Base::Element::setParentAnchor(sf::Vector2f * anchor)
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
void Base::Element::setLocalOffset(sf::Vector2f * offset)
{
	m_localOffset = *offset;
}

void Base::Element::setLocalOffset(float * x, float * y)
{
	m_localOffset.x = *x;
	m_localOffset.y = *y;
}

const sf::Vector2f * const Base::Element::getParentAnchor()
{
	return m_parentAnchor;
}

const sf::Vector2f * const Base::Element::getLocalOffset()
{
	return &m_localOffset;
}

void Base::Element::setVisible(bool value)
{
	this->bVisible = value;
}

bool Base::Element::getVisible()
{
	return bVisible;
}
