#pragma once

#include "sfml\Graphics.hpp"
//#include "thirdparty/Poco\JSON\Object.h"
//#include "thirdparty/Poco\JSON\Array.h"
//#include "thirdparty/Poco\JSON\Parser.h"

//#include "Mouth.h"
//#include "OtherElements.h"

namespace Base
{
	class Mouth;
	class Body;
}
namespace sf
{
	//class Vector2i;
	//class Vector2f;
}

namespace Frames
{
	struct SFrame
	{
		sf::Vector2i rectPos;
		sf::Vector2i rectSize;
		sf::Vector2f spriteOffset; //offset from derivedAnchor
		sf::Vector2f charAnchor;
		sf::Vector2f mouthAnchor;
		sf::Vector2f noseAnchor;
		sf::Vector2f eyesAnchor;
	};

	enum class EBody
	{
		F1BOTTOM = 101,
		F1BROWUP = 102,
		F1CLOSEEYES = 103,
		F1IDLE = 104,
		F1LEFT = 105,
		F1LOOK = 106,
		F1MAD = 107,
		F1Q = 108,
		F1RIGHT = 109,
		F1SLEEP1 = 100,
		F1SLEEP2 = 111,
		F1UDIVL2 = 112,
		F1UDIVL13 = 113,
		F1UPPER = 114,
		F1VSK = 115,

		F2BOTTOM = 216,
		F2BROWUP = 217,
		F2CLOSEEYES = 218,
		F2IDLE = 219,
		F2LEFT = 220,
		F2LOOK = 221,
		F2MAD = 222,
		F2Q = 223,
		F2RIGHT = 224,
		F2SLEEP1 = 225,
		F2SLEEP2 = 226,
		F2UDIVL2 = 227,
		F2UDIVL13 = 228,
		F2UPPER = 229,
		F2VSK = 230,

		

	};
	enum class EMouth
	{
		MOPEN1 = 300,
		MOPEN2 = 301,
		MOPEN3 = 302,
		MIDLE = 303,
		MSMILE = 304,
		MSAD = 305,
		MKITTY = 306
	};


	class FramesHanlde
	{
	private:
		Base::Mouth* m_pMouth = nullptr;
		Base::Body*  m_pBody = nullptr;

		sf::Vector2f m_Face1MouthAnchor;
		sf::Vector2f m_Face2MouthAnchor;

		sf::Vector2i m_sizeBody; //144 147

	public:
		FramesHanlde			();
		void setMouth			(const Base::Mouth& rMouth);
		void setBody			(const Base::Body& rBody);
		Base::Mouth* getMouth   ();
		Base::Body* getBody     ();
		//SFrame* GetFrameData(EFrames* frame);

	};
}
