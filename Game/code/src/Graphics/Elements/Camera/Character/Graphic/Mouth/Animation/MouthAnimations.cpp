#include "MouthAnimations.h"
#include "Mouth.h"
#include "EnumFrames.h"

MouthAnimations::Input1::Input1(Base::Mouth& mouth, int8_t bufferArray): MouthInputAnimation(mouth, bufferArray)
{
}

MouthAnimations::Input1::Input1()
{
}


void MouthAnimations::Input1::update()
{
	//mouth->getSprite()->setPosition(sf::Vector2f(*mouth->getParentAnchor()));
	Frames::EMouth f1 = Frames::EMouth::MIDLE;
	Frames::EMouth f2 = Frames::EMouth::MOPEN2;
	Frames::EMouth f3 = Frames::EMouth::MOPEN3;
	Frames::EMouth f4 = Frames::EMouth::MOPEN1;
	SetFrame(&f1, 20);
	SetFrame(&f2, 20, 70);
	SetFrame(&f3, 70, 100);
	SetFrame(&f4, 100, 255);
}

void MouthAnimations::Input1::start()
{
}

void MouthAnimations::Input1::stop()
{
}
