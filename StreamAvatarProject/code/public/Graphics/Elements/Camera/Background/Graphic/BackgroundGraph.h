#pragma once

#include "GraphicalElement.h"

namespace Base
{
	class BackgroundGraph final: public SpriteElement
	{
	public:
		BackgroundGraph();

		void update();
		void loadTexture();
		void initSprite();

		virtual void onPositionChanged() override final;
		virtual void updateChildPosition() override final;
	};
}
