#include "CameraText.h"

CameraText::CameraText()
{
	if (!font.loadFromFile("fonts/8-bit.ttf"))
	{
		//error;
	}
	Color color = Color::Green;
	setColor(&color);
	text.setFont(font);
	text.setCharacterSize(30);
	text.setPosition(1, 1);
	text.setLineSpacing(0);
	std::wstring str;
	str = L"sadasûôûôâd";
	setTextString(&str); 
}
