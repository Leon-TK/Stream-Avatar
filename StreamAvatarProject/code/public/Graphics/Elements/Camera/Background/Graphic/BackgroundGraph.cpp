#include "BackgroundGraph.h"

Base::BackgroundGraph::BackgroundGraph()
{
	loadTexture();
	initSprite();
	//set child anchors
}

void Base::BackgroundGraph::update()
{
}

void Base::BackgroundGraph::loadTexture()
{
	SpriteElement::LoadTexture("img/background/background.png");
}

void Base::BackgroundGraph::initSprite()
{
	float x = 0;
	float y = 0;
	SpriteElement::InitSprite(&x, &y, &texture);
	UpdateRect(&sf::Vector2i(0,0), &sf::Vector2i(151, 151));
}

void Base::BackgroundGraph::onPositionChanged()
{
}

void Base::BackgroundGraph::updateChildPosition()
{
}
