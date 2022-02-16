#include "MouthFrames.h"

Frames::MOPEN1::MOPEN1()
{
	m_location = sf::Vector2i(0,0);
	m_size = sf::Vector2i(39, 18);
	m_offset = sf::Vector2f(-3*3, -3*3);
	EFrame = Frames::EMouth::MOPEN1;
}

Frames::MOPEN2::MOPEN2()
{
	m_location = sf::Vector2i(96, 6);
	m_size = sf::Vector2i(21, 9);
	m_offset = sf::Vector2f(0 * 3, -1 * 3);
	EFrame = Frames::EMouth::MOPEN2;
}

Frames::MOPEN3::MOPEN3()
{
	m_location = sf::Vector2i(123, 0);
	m_size = sf::Vector2i(21, 15);
	m_offset = sf::Vector2f(0 * 3, -2 * 3);
	EFrame = Frames::EMouth::MOPEN3;
}

Frames::MIDLE::MIDLE()
{
	m_location = sf::Vector2i(39, 9);
	m_size = sf::Vector2i(21, 3);
	m_offset = sf::Vector2f(0, 0);
	EFrame = Frames::EMouth::MIDLE;
}

Frames::MSMILE::MSMILE()
{
	m_location = sf::Vector2i(39, 0);
	m_size = sf::Vector2i(30, 9);
	m_offset = sf::Vector2f(-1 * 3, -2 * 3);
	EFrame = Frames::EMouth::MSMILE;
}

Frames::MSAD::MSAD()
{
	m_location = sf::Vector2i(96, 0);
	m_size = sf::Vector2i(27, 6);
	m_offset = sf::Vector2f(-1 * 3, 0);
	EFrame = Frames::EMouth::MSAD;
}

Frames::MKITTY::MKITTY()
{
	m_location = sf::Vector2i(69, 0);
	m_size = sf::Vector2i(27, 9);
	m_offset = sf::Vector2f(-1 * 3, -1 * 3);
	EFrame = Frames::EMouth::MKITTY;
}
