#pragma once

#include "Camera.h"
#include "AnimationManager.h"
//#include <thread>
//class Base::SequenceManager;
//class Base::Timer;


namespace Base
{
	//class Camera;
	//class AnimationManager;

	class GraphManager
	{
	private:
		//DA alert
		Base::ViewCamera      m_camera;
		AnimationManager      m_animationManager;

	public:
		GraphManager();
		//tick
		void update();

		Base::ViewCamera* getCamera();
		AnimationManager* getAnimationManager();
		//std::thread getThread();
	};
}
