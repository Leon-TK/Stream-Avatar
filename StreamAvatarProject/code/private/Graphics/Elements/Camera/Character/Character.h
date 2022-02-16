#pragma once

#include "CharacterAnimation.h"
#include "Element.h"
#include "Body.h"
#include "Mouth.h"

namespace Base
{

	class CharacterAbstract: public Element
	{
	private:
		CharAnimation::CharacterAnimation m_charAnim;
		sf::Vector2i m_bodyAnchor;
		
	public:
		CharacterAbstract();
		Body body; //graphical element
		Mouth mouth; //graphical element
		// nose //graphical element
		// eyes //graphical element
		// brow //graphical element

		CharAnimation::CharacterAnimation* getCharacterAnimation();
	};


}
