#pragma once

#include "GraphicalElement.h"
#include "Animation.h"
//#include "sfml"

namespace Base {

	class Mouth: public SpriteElement
	{
	private:
		AnimationSpace::Animation* m_pAnimation = nullptr;
		Frames::EMouth m_currentFrame;

	public:
		Mouth();
		void update();
		void loadTexture();
		void initSprite();
		Frames::EMouth getCurrentFrame();
		void setCurrentFrame(Frames::EMouth frame);

		AnimationSpace::Animation* getAnimation();
		void setAnimation(AnimationSpace::Animation& rAnim);
		virtual void onPositionChanged() override final;
		virtual void updateChildPosition() override final;
	};
}
