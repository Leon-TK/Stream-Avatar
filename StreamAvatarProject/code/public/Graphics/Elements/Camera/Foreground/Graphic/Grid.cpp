#include "Grid.h"

Base::Grid::Grid()
{
	loadTexture();
	initSprite();
	//set child anchors
}

void Base::Grid::update()
{
}

void Base::Grid::loadTexture()
{
	SpriteElement::LoadTexture("img/foreground/foreground.png");
}

void Base::Grid::initSprite()
{
	float x = 0;
	float y = 0;
	SpriteElement::initSprite(&x, &y, &texture);
	updateRect(&sf::Vector2i(0, 0), &sf::Vector2i(151, 151));
}

void Base::Grid::onPositionChanged()
{
}

void Base::Grid::updateChildPosition()
{
}
