#include "GraphManager.h"
//#include "Camera.h"
#include "AnimationManager.h"

Base::GraphManager::GraphManager()
{
	
	animationManager.SetCameraPtr(&camera);
}

void Base::GraphManager::update()
{
	animationManager.update();
}

Base::ViewCamera * const Base::GraphManager::getCamera()
{
	return &camera;
}

Base::AnimationManager * const Base::GraphManager::getAnimationManager()
{
	return &animationManager;
}

/*
std::thread Base::GraphManager::GetThread()
{
	return std::thread(&Base::GraphManager::Update, this);
}
*/