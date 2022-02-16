#pragma once

#include "Element.h"
#include "BackgroundGraph.h"

namespace Base
{

	class BackgroundAbstract : public Element
	{
	private:
		sf::Vector2i m_backgroundAnchor;
		BackgroundGraph m_background;

	public:
		BackgroundAbstract();
		BackgroundGraph* getBackground();
	};

}