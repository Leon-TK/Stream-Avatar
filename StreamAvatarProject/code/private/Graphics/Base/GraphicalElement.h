#pragma once

#include "sfml/Graphics/Texture.hpp" 
#include "sfml/Graphics/Rect.hpp"
#include "sfml/Graphics/Sprite.hpp"

//#include "Element.h"
//#include "BaseFrame.h"


namespace Frames
{
	class BaseFrame;
	enum class EMouth;
}

namespace Base
{

	class ASpriteElement
	{
	private: 
		sf::Sprite					m_sprite;

	protected:
		sf::Vector2f*				m_pParentAnchor = nullptr;
		sf::Vector2f				m_localOffset;
		bool						m_bVisible;
		sf::IntRect					m_rect;
		sf::Texture					m_texture;
		Frames::BaseFrame*			m_pFrame = nullptr;

	public:
		ASpriteElement();

		void update					(); //TODO: UpdatePosition() optimization because it calculates every tick

		void setParentAnchor		(const sf::Vector2f& rAnchor);
		void setLocalOffset			(const sf::Vector2f& rOffset);
		void setLocalOffset			(float x, float y);
		void setVisible				(bool value);
		void setFrame				(const Frames::BaseFrame& rFrame);

		void setRectParams			(int xp, int yp, int xs, int ys);
		void setRectParams			(const sf::Vector2i& rLoc, const sf::Vector2i& rSize);
		void setSpriteTexture		(const sf::Texture& rTexture);
		void setPosition			(float x, float y);
		void setPosition			(const sf::Vector2f& rPoc);
		//void setParentAnchor	(float x, float y);

		const sf::Vector2f* getParentAnchor();
		const sf::Vector2f* getLocalOffset();
		bool getVisible();

		//sf::Sprite* getSprite();
		sf::IntRect* getRect();
		sf::Texture* getTexture();
		const sf::Vector2f* getPosition();
		Frames::BaseFrame* getFrame();
		const sf::Sprite* getSprite();

		void updateLocation			();
		void loadTexture			(const std::string& path);
		void initSprite				(float x, float y, const sf::Texture& rTexture);
		//void updatePositionFromParent(sf::Vector2f& parentAnchor);
		void updateRect				(int x, int y, int sx, int xy);
		void updateRect				(const sf::Vector2i& rPos, const sf::Vector2i& rSize);
		void updateOffset			(const sf::Vector2f& rOffset);

		virtual void onPositionChanged() = 0; //called when SetPosition is called
		virtual void updateChildPosition() = 0;
	
	};

}
