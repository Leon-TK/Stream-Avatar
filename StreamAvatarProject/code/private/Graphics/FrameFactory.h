#pragma once

#include "EnumFrames.h"
#include "BodyFrames.h" 
#include "MouthFrames.h" 

namespace Frames
{
	class BaseFrame;
}

namespace Base
{
	class FrameFactory
	{
	public:
		//virtual Frames::BaseFrame* getFrame(Frames::EBody frame) = 0;
		virtual Frames::BaseFrame* getFrame(Frames::EBody frame) = 0;
		virtual Frames::BaseFrame* getFrame(Frames::EMouth frame) = 0;
	};
}
