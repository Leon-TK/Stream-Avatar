#pragma once

#include "BaseFrame.h"
#include "EnumFrames.h"
//#include "Body.h"

namespace Base
{
	class Body;
	class Mouth;
}
namespace Frames
{
	class BodyFrame: public BaseFrame
	{
	protected:
		sf::Vector2f m_mouthAnchor; //anchor for mouth
		sf::Vector2f m_eyesAnchor; //anchor for eyes
		sf::Vector2f m_noseAnchor; //anchor for nose
		Frames::EBody m_EFrame;
		
	public:
		BodyFrame(const sf::Vector2f& anchorOffset);
		BodyFrame();
		
		Frames::EBody getEFrame();
		virtual void updateElement(Base::SpriteElement& body) override final;
		//virtual void updateElement(Base::Mouth& body) override final;
		//Data* getData();
	};

}
