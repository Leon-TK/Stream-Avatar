#pragma once

#include "Element.h"
#include "Grid.h"

namespace Base
{

	class ForegroundAbstract : public Element
	{
	private:
		sf::Vector2i m_gridAnchor;
		Grid m_grid;
		
	public:
		ForegroundAbstract();
		Grid* getGrid();

	};

}