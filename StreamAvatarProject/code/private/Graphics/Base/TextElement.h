#pragma once

#include "SFML\Graphics\Text.hpp"
//#include "SFML\Graphics\Font.hpp"
//#include "SFML\Graphics\Texture.hpp"
//#include "SFML\Graphics\Glyph.hpp"
#include "SFML\Graphics\Color.hpp"

using sf::Text;
using sf::Texture;
using sf::Glyph;
using sf::Font;
using sf::Color;

class TextElement
{
private:
	sf::Vector2f*			m_pParentAnchor = nullptr;
	sf::Vector2f			m_localOffset;
	bool					m_bVisible;

protected:
	Text					m_text;
	Font					m_font;
	Color					m_color;
	std::wstring			m_stringText;
	uint32_t				m_size;

public:
	TextElement();

	void setTextString		(const std::wstring& rText);
	void setColor			(const Color& rColor);
	void setSize			(uint32_t size);
	void setPosition		(const sf::Vector2f& rPos);
	void setParentAnchor	(const sf::Vector2f& rAnchor);
	void setLocalOffset		(const sf::Vector2f& rOffset);
	void setLocalOffset		(float x, float y);
	void setVisible			(bool value);
	//void setParentAnchor	(float x, float y);

	Text* getText();
	sf::Vector2f* getParentAnchor();
	sf::Vector2f* getLocalOffset();
	bool getVisible();	
};

