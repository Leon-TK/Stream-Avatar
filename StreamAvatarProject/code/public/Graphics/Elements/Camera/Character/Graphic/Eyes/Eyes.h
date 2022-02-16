#pragma once

#include "GraphicalElement.h"

namespace Base {

	class Eyes final: public SpriteElement
	{
	public:
		Eyes();
		
		virtual void onPositionChanged() override final;
		virtual void updateChildPosition() override final;
		
	};
}
