#include "MouthFrame.h"

Frames::MouthFrame::MouthFrame()
{
}

Frames::EMouth Frames::MouthFrame::getEFrame()
{
	return EFrame;
}

void Frames::MouthFrame::updateElement(Base::SpriteElement& mouth)
{
	Base::Mouth* m = static_cast<Base::Mouth*>(mouth);
	m->setCurrentFrame(EFrame);
	//m->UpdatePositionFromParent(nullptr); //this must be in set frame or something like this because update element is called in set frame where is cheking for current frame and this not callin
	m->UpdateOffset(&m_offset);//TODO: vector2f cast mut not be here, mouthANchor must be Vector2f/
	m->UpdateRect(&m_location, &m_size);

}
