#pragma once
#include "FrameFactory.h"

namespace Base
{
	class MouthFrameFactory: public FrameFactory
	{
	public:
		MouthFrameFactory();
		virtual Frames::BaseFrame* getFrame(Frames::EMouth frame) override final;
		virtual Frames::BaseFrame* getFrame(Frames::EBody frame) override final;

	};
}
