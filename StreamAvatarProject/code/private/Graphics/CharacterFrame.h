#pragma once
#include "BaseFrame.h"

namespace Frames
{
	class CharacterFrame : public BaseFrame
	{
	protected:
		sf::Vector2f m_bodyAnchor; //anchor for character
	public:
		CharacterFrame();
	};

}