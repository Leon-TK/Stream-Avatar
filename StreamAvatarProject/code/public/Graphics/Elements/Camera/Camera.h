#pragma once

#include "ViewElement.h"
#include "Character.h"
#include "Background.h"
#include "Foreground.h"
#include "CameraText.h"
#include "CameraAnimation.h"

namespace CamAnimation
{
	//class CameraAnimation;
}

namespace Base
{
	//class BackgroundAbstract;
	//class ForegroundAbstract;

	class ViewCamera: public ViewElement
	{
	private:

		CamAnimation::CameraAnimation m_animation;
		CharacterAbstract m_character;
		BackgroundAbstract m_bg;
		ForegroundAbstract m_fg;
		CameraText m_camText;

	protected:
		sf::Vector2i m_characterAnchor;
		sf::Vector2i m_foregroundAnchor;
		sf::Vector2i m_backgroundAnchor;

	public:

		ViewCamera(const sf::Vector2f& pos);
		ViewCamera();
		~ViewCamera();

		void setAnimation(CamAnimation::CameraAnimation& anim);
		void setPos(const sf::Vector2f& pos);
		void setVisible(bool val);

		CamAnimation::CameraAnimation* getAnimation();
		CharacterAbstract* getCharacter();

		void deleteAnimation();
		void onPositionChanged() override final;
		void updateChildAnchor() override final;
		

	};

}
