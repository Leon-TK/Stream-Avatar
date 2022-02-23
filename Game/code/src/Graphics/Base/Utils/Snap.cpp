#include "Snap.h"

void SnapPoint::onPositionChanged()
{
}

void SnapPoint::addClaw(SnapClaw * claw)
{
	this->claw = claw;
}

void SnapPoint::updatePosition(const Vectorf * pos)
{
	setPosition(pos);
	claw->updatePositionByPoint();
}


void SnapClaw::onPositionChanged()
{
}

void SnapClaw::setOffset(Vectorf * offset)
{
	this->offset = *offset;
	updatePosition(&sf::Vector2f(pos += *offset));
}

void SnapClaw::addOffset(Vectorf * deltaOffset)
{
	offset += *deltaOffset;
	updatePosition(&sf::Vector2f(pos += *deltaOffset));
}


void SnapClaw::updatePosition(const Vectorf * pos)
{
	setPosition(pos);
	onPositionChanged();

}

void SnapClaw::updatePositionByPoint()
{
	updatePosition(&sf::Vector2f(*point->getPos() + offset));
}

void SnapClaw::attachToPoint(SnapPoint * point)
{
	point->addClaw(this);
	updatePosition(&sf::Vector2f(*point->getPos() + offset));
}

void SnapBase::setPosition(const Vectorf * pos)
{
	this->pos = *pos;
}

const Vectorf * SnapBase::getPos()
{
	return &pos;
}
