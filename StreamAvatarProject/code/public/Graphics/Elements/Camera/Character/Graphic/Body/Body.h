#pragma once

#include "GraphicalElement.h"
#include "Animation.h"
#include  "FrameFactory.h"
#include  "BodyFrameFactory.h"

namespace Frames
{
	enum class EBody;
}

namespace Base {

	class Mouth;

	class Body : public SpriteElement
	{
	private:
		
		AnimationSpace::Animation* m_pAnimation = nullptr;
		Base::Mouth* m_pMouth = nullptr;
		Frames::EBody m_currentFrame;

	public:
		Body();

		void update();

		void loadTexture();
		void initSprite();

		Base::Mouth* getMouth();

		void setMouth(Base::Mouth& rMouth);

		sf::Vector2f mouthAnchor;
		sf::Vector2f noseAnchor;
		sf::Vector2f eyesAnchor;
		sf::Vector2f browAnchor;

		Frames::EBody getCurrentFrame();
		Frames::BaseFrame* setCurrentFrame(Frames::EBody frame);

		AnimationSpace::Animation* getAnimation();
		void setAnimation(AnimationSpace::Animation& rAnim);

		virtual void onPositionChanged() override final;
		virtual void updateChildPosition() override final;

	};
}
