#pragma once

#include "GraphicalElement.h"

namespace Base
{
	class Grid: public SpriteElement
	{
	public:
		Grid();
		void update();
		void loadTexture();
		void initSprite();
		virtual void onPositionChanged() override final;
		virtual void updateChildPosition() override final;
	};
}
