#pragma once

#include "sfml\System\Vector2.hpp"

namespace Base
{
	class AViewElement
	{
	private:
		sf::Vector2f				m_pos;
		bool						m_bVisible;

	public:
		AViewElement();

		void update					();

		void setVisible				(bool val);
		void setPos					(const sf::Vector2f& rPos);

		bool getVisible		();
		const sf::Vector2f* getPos	();

		void addOffset				(const sf::Vector2f& rOffset);

		virtual void onPositionChanged() = 0;
		virtual void updateChildAnchor() = 0;
	};
}
