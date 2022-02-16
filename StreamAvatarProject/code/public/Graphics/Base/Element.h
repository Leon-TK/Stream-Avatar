#pragma once

#include "sfml/System/Vector2.hpp"
//for child
#include "sfml/Graphics/Texture.hpp" 
#include "sfml/Graphics/Rect.hpp"
#include "sfml/Graphics/Sprite.hpp"

namespace Base
{

	class Element
	{
	protected:
		sf::Vector2f*  m_pParentAnchor = nullptr;
		sf::Vector2f  m_localOffset;
		bool		  m_bVisible;

	public:

		Element();

		void setParentAnchor(const sf::Vector2f& rAchor);
		//void setParentAnchor(float x, float y);
		void setLocalOffset(const sf::Vector2f& rOffset);
		void setLocalOffset(float x, float y);
		void setVisible(bool value);
		
		sf::Vector2f* getParentAnchor();
		sf::Vector2f* getLocalOffset();
		bool getVisible();
		//methods
		//virtual void			UpdatePosition() = 0;
		
	};


}