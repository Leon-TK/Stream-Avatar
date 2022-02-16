#include "Character.h"

Base::CharacterAbstract::CharacterAbstract()
{
	bodyAnchor - sf::Vector2i(0,0);
	body.setMouth(&mouth);
}

CharAnimation::CharacterAnimation * Base::CharacterAbstract::getCharacterAnimation()
{
	return &charAnim;
}

