#pragma once

#include "sfml/System/Vector2.hpp"

//#include <SFML/Graphics.hpp>
//#include "Frames.h"

namespace Base
{
	//class Body;
	//class Mouth;
	class SpriteElement;
}

namespace Frames
{
	/*
	enum class EFrames;

	struct Data
	{
	public:
		sf::Vector2f rectPos;
		sf::Vector2f rectSize;
		EFrames frame;
		sf::Vector2f anchorOffset;
	};
	*/

class BaseFrame
{
protected:
	
	sf::Vector2i m_location; //location of intrect at texture
	sf::Vector2i m_size;     //size of intrect
	sf::Vector2f m_offset;   //offset from parent anchor
	
public:
	BaseFrame();
	//Data data;

	virtual void updateElement(const Base::SpriteElement& element) = 0;
	//virtual void updateElement(Base::Mouth& body) = 0;
	//virtual Frames::EBody getEFrame() = 0;
	//virtual Frames::EMouth getEFrame() = 0;
};

}
