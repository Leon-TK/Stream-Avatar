#pragma once

#include "FrameFactory.h"

namespace Base
{

	class BodyFrameFactory : public FrameFactory
	{
	public:
		BodyFrameFactory();
		virtual Frames::BaseFrame* getFrame(Frames::EBody frame) override final;
		virtual Frames::BaseFrame* getFrame(Frames::EMouth frame) override final;
	};
}
