#pragma once

#include "BaseFrame.h"
#include "EnumFrames.h"
#include "Mouth.h"

namespace Frames
{
	class MouthFrame : public BaseFrame
	{
	protected:
		Frames::EMouth m_EFrame;

	public:
		MouthFrame();

		Frames::EMouth getEFrame();
		//virtual void UpdateElement(Base::Body* mouth) override;
		virtual void updateElement(Base::SpriteElement& rMouth) override final;
	};
}