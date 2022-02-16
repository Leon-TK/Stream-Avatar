#pragma once

#include "GraphicalElement.h"

namespace Base {

	class Brow final: public SpriteElement
	{
	public:
		Brow();

		virtual void onPositionChanged() override final;
		virtual void updateChildPosition() override final;
		
	};
}
