#pragma once

#include "GraphicalElement.h"

namespace Base
{

	class CharacterElement final: public SpriteElement
	{
	protected:
		sf::Vector2f m_bodyAnchor;

	public:
		CharacterElement();

		virtual void onPositionChanged() override final;
		virtual void updateChildPosition() override final;
	};

}