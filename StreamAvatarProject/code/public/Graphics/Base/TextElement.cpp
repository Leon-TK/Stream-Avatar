#include "TextElement.h"

const Text * TextElement::getText()
{
	return &text;
}

TextElement::TextElement()
{

}

void TextElement::setTextString(std::wstring * text)
{
	this->text.setString(*text);
	this->stringText = *text;
}

void TextElement::setColor(Color * color)
{
	text.setFillColor(*color);
	this->color = *color;
}

void TextElement::setSize(unsigned int* size)
{
	text.setCharacterSize(*size);
	this->size = *size;

}

void TextElement::setPosition(sf::Vector2f * pos)
{
	text.setPosition(*pos);
}
void TextElement::setParentAnchor(sf::Vector2f * anchor)
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
void TextElement::setLocalOffset(sf::Vector2f * offset)
{
	m_localOffset = *offset;
}

void TextElement::setLocalOffset(float * x, float * y)
{
	m_localOffset.x = *x;
	m_localOffset.y = *y;
}

const sf::Vector2f * const TextElement::getParentAnchor()
{
	return m_parentAnchor;
}

const sf::Vector2f * const TextElement::getLocalOffset()
{
	return &m_localOffset;
}

void TextElement::setVisible(bool value)
{
	this->bVisible = value;
}

bool TextElement::getVisible()
{
	return bVisible;
}