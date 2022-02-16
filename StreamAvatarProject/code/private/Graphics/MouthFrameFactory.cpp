#include "MouthFrameFactory.h"

Base::MouthFrameFactory::MouthFrameFactory()
{
}

Frames::BaseFrame* Base::MouthFrameFactory::getFrame(Frames::EMouth frame)
{
	switch (frame)
	{
	case Frames::EMouth::MOPEN1:
		return new Frames::MOPEN1();
		break;
	case Frames::EMouth::MOPEN2:
		return new Frames::MOPEN2();
		break;
	case Frames::EMouth::MOPEN3:
		return new Frames::MOPEN3();
		break;
	case Frames::EMouth::MIDLE:
		return new Frames::MIDLE();
		break;
	case Frames::EMouth::MSMILE:
		return new Frames::MSMILE();
		break;
	case Frames::EMouth::MSAD:
		return new Frames::MSAD();
		break;
	case Frames::EMouth::MKITTY:
		return new Frames::MKITTY();
		break;
	default:
		return nullptr;
		break;
	}
}

Frames::BaseFrame * Base::MouthFrameFactory::getFrame(Frames::EBody frame)
{
	return nullptr;
}
