#include "BodyFrame.h"
#include "Body.h"

Frames::BodyFrame::BodyFrame(const sf::Vector2f& rAnchorOffset)
{
	//data.rectSize = sf::Vector2f(144, 147);
	//data.anchorOffset = rAnchorOffset;
}

Frames::BodyFrame::BodyFrame()
{
	m_size = sf::Vector2i(144, 147);
	m_offset = sf::Vector2f(0, 0);
}
Frames::EBody Frames::BodyFrame::getEFrame()
{
	return EFrame;
}
void Frames::BodyFrame::updateElement(Base::SpriteElement& body)
{
	Base::Body* b = static_cast<Base::Body*>(body);

	b->mouthAnchor = mouthAnchor + sf::Vector2f(-2*3,-1*3);
	//b->getMouth()->UpdatePositionFromParent(&mouthAnchor); //TODO: vector2f cast mut not be here, mouthANchor must be Vector2f/
	//update all child position like mouth 
	//body->setLocalOffset(&m_offset);
	//body->UpdateOffset(&m_offset);//TODO: vector2f cast mut not be here, mouthANchor must be Vector2f/
	b->setCurrentFrame(EFrame);
	b->updateRect(&m_location, &m_size);
	//update child postition;
	//body->getMouth()->setParentAnchor(&body->mouthAnchor);
	//body->setRectParams() TODO:
}

/*
Frames::Data * Frames::BodyFrame::getData()
{
	return &data;
}
*/