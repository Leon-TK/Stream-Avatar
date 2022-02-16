#include "BodyFrameFactory.h"

Base::BodyFrameFactory::BodyFrameFactory()
{
}

Frames::BaseFrame* Base::BodyFrameFactory::getFrame(Frames::EBody frame)
{
	switch (frame)
	{
	case Frames::EBody::F1BOTTOM:
		return new Frames::F1BOTTOM();
		break;
	case Frames::EBody::F1BROWUP:
		return new Frames::F1BROWUP();
		break;
	case Frames::EBody::F1CLOSEEYES:
		return new Frames::F1CLOSEEYES();
		break;
	case Frames::EBody::F1IDLE:
		return new Frames::F1IDLE();
		break;
	case Frames::EBody::F1LEFT:
		return new Frames::F1LEFT();
		break;
	case Frames::EBody::F1LOOK:
		return new Frames::F1LOOK();
		break;
	case Frames::EBody::F1MAD:
		return new Frames::F1MAD();
		break;
	case Frames::EBody::F1Q:
		return new Frames::F1Q();
		break;
	case Frames::EBody::F1RIGHT:
		return new Frames::F1RIGHT();
		break;
	case Frames::EBody::F1SLEEP1:
		return new Frames::F1SLEEP1();
		break;
	case Frames::EBody::F1SLEEP2:
		return new Frames::F1SLEEP2();
		break;
	case Frames::EBody::F1UDIVL2:
		return new Frames::F1UDIVL2();
		break;
	case Frames::EBody::F1UDIVL13:
		return new Frames::F1UDIVL13();
		break;
	case Frames::EBody::F1UPPER:
		return new Frames::F1UPPER();
		break;
	case Frames::EBody::F1VSK:
		return new Frames::F1VSK();
		break;
	case Frames::EBody::F2BOTTOM:
		return new Frames::F2BOTTOM();
		break;
	case Frames::EBody::F2BROWUP:
		return new Frames::F2BROWUP();
		break;
	case Frames::EBody::F2CLOSEEYES:
		return new Frames::F2CLOSEEYES();
		break;
	case Frames::EBody::F2IDLE:
		return new Frames::F2IDLE();
		break;
	case Frames::EBody::F2LEFT:
		return new Frames::F2LEFT();
		break;
	case Frames::EBody::F2LOOK:
		return new Frames::F2LOOK();
		break;
	case Frames::EBody::F2MAD:
		return new Frames::F2MAD();
		break;
	case Frames::EBody::F2Q:
		return new Frames::F2Q();
		break;
	case Frames::EBody::F2RIGHT:
		return new Frames::F2RIGHT();
		break;
	case Frames::EBody::F2SLEEP1:
		return new Frames::F2SLEEP1();
		break;
	case Frames::EBody::F2SLEEP2:
		return new Frames::F2SLEEP2();
		break;
	case Frames::EBody::F2UDIVL2:
		return new Frames::F2UDIVL2();
		break;
	case Frames::EBody::F2UDIVL13:
		return new Frames::F2UDIVL13();
		break;
	case Frames::EBody::F2UPPER:
		return new Frames::F2UPPER();
		break;
	case Frames::EBody::F2VSK:
		return new Frames::F2VSK();
		break;
	default:
		return nullptr;
		break;
	}
	return nullptr;
}

Frames::BaseFrame * Base::BodyFrameFactory::getFrame(Frames::EMouth frame)
{
	return nullptr;
}

