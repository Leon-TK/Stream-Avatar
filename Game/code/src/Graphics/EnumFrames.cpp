#include "EnumFrames.h"

Frames::FramesHanlde::FramesHanlde(): Face1MouthAnchor(23.0f*3.0f, 33.0f*3.0f), Face2MouthAnchor(26.0f*3.0f, 33.0f*3.0f), sizeBody(144,147)
{
}

void Frames::FramesHanlde::setMouth(Base::Mouth& mouth)
{
	this->mouth = mouth;
}

void Frames::FramesHanlde::setBody(Base::Body& body)
{
	this->body = body;
}

Base::Mouth * Frames::FramesHanlde::getMouth()
{
	return mouth;
}

Base::Body* Frames::FramesHanlde::getBody()
{
	return body;
}
/*
Frames::SFrame* Frames::FramesHanlde::GetFrameData(Frames::EFrames* frame)
{
	
	Frames::SFrame* f = new Frames::SFrame();
	switch (*frame)
	{
	case Frames::EFrames::F1BOTTOM:
		
		f->rectPos.x = 0;
		f->rectPos.y = 0;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F1BROWUP:
		f->rectPos.x = 144;
		f->rectPos.y = 0;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F1CLOSEEYES:
		f->rectPos.x = 0;
		f->rectPos.y = 147;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F1IDLE:
		f->rectPos.x = 144;
		f->rectPos.y = 147;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F1LEFT:
		f->rectPos.x = 0;
		f->rectPos.y = 294;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F1LOOK:
		f->rectPos.x = 144;
		f->rectPos.y = 294;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F1MAD:
		f->rectPos.x = 0;
		f->rectPos.y = 441;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F1Q:
		f->rectPos.x = 144;
		f->rectPos.y = 441;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F1RIGHT:
		f->rectPos.x = 0;
		f->rectPos.y = 588;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F1SLEEP1:
		f->rectPos.x = 144;
		f->rectPos.y = 588;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F1SLEEP2:
		f->rectPos.x = 0;
		f->rectPos.y = 735;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F1UDIVL2:
		f->rectPos.x = 144;
		f->rectPos.y = 735;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F1UDIVL13:
		f->rectPos.x = 0;
		f->rectPos.y = 882;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F1UPPER:
		f->rectPos.x = 144;
		f->rectPos.y = 882;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F1VSK:
		f->rectPos.x = 0;
		f->rectPos.y = 1029;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face1MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F2BOTTOM:
		f->rectPos.x = 144;
		f->rectPos.y = 1029;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F2BROWUP:
		f->rectPos.x = 0;
		f->rectPos.y = 1176;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F2CLOSEEYES:
		f->rectPos.x = 144;
		f->rectPos.y = 1176;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F2IDLE:
		f->rectPos.x = 0;
		f->rectPos.y = 1323;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		f->mouthAnchor = sf::Vector2f(26 * 3, 33 * 3);
		return f;
		break;
	case Frames::EFrames::F2LEFT:
		f->rectPos.x = 144;
		f->rectPos.y = 1323;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F2LOOK:
		f->rectPos.x = 0;
		f->rectPos.y = 1470;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F2MAD:
		f->rectPos.x = 144;
		f->rectPos.y = 1470;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F2Q:
		f->rectPos.x = 0;
		f->rectPos.y = 1617;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F2RIGHT:
		f->rectPos.x = 144;
		f->rectPos.y = 1617;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F2SLEEP1:
		f->rectPos.x = 0;
		f->rectPos.y = 1764;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F2SLEEP2:
		f->rectPos.x = 144;
		f->rectPos.y = 1764;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F2UDIVL2:
		f->rectPos.x = 0;
		f->rectPos.y = 1911;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F2UDIVL13:
		f->rectPos.x = 144;
		f->rectPos.y = 1911;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F2UPPER:
		f->rectPos.x = 0;
		f->rectPos.y = 2058;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		return f;
		break;
	case Frames::EFrames::F2VSK:
		f->rectPos.x = 144;
		f->rectPos.y = 2058;
		f->rectSize = sizeBody;
		f->mouthAnchor = Face2MouthAnchor;
		return f;
		break;

	case Frames::EFrames::MOPEN1:
		f->rectPos.x = 0;
		f->rectPos.y = 0;
		f->rectSize.x = 39;
		f->rectSize.y = 18;
		f->spriteOffset = sf::Vector2f(0.0f, -1.0f* 3.0f);
		return f;
		break;
	case Frames::EFrames::MOPEN2:
		f->rectPos.x = 96;
		f->rectPos.y = 6;
		f->rectSize.x = 21;
		f->rectSize.y = 9;
		f->spriteOffset = sf::Vector2f(-3.0f * 3.0f, -3.0f * 3.0f);
		return f;
		break;
	case Frames::EFrames::MOPEN3:
		f->rectPos.x = 123;
		f->rectPos.y = 0;
		f->rectSize.x = 21;
		f->rectSize.y = 15;
		f->spriteOffset = sf::Vector2f(0.0f, -2.0f* 3.0f);
		return f;
		break;
	case Frames::EFrames::MIDLE:
		f->rectPos.x = 39;
		f->rectPos.y = 9;
		f->rectSize.x = 21;
		f->rectSize.y = 3;
		return f;
		break;
	case Frames::EFrames::MSMILE:
		f->rectPos.x = 39;
		f->rectPos.y = 0;
		f->rectSize.x = 30;
		f->rectSize.y = 9;
		f->spriteOffset = sf::Vector2f(-1.0f* 3.0f, - 2.0f* 3.0f);
		return f;
		break;
	case Frames::EFrames::MSAD:
		f->rectPos.x = 96;
		f->rectPos.y = 0;
		f->rectSize.x = 27;
		f->rectSize.y = 6;
		f->spriteOffset = sf::Vector2f(-1.0f* 3.0f, 0.0f);
		return f;
		break;
	case Frames::EFrames::MKITTY:
		f->rectPos.x = 69;
		f->rectPos.y = 0;
		f->rectSize.x = 27;
		f->rectSize.y = 9;
		f->spriteOffset = sf::Vector2f(-1.0f* 3.0f, -1.0f* 3.0f);
		return f;
		break;
	default:
		f->rectPos.x = 1;
		f->rectPos.y = 1;
		f->rectSize.x = 1;
		f->rectSize.y = 1;
		return f;
		break;
	}
	return nullptr;
}
*/