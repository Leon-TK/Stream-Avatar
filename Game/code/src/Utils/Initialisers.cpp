#include "Camera.h"
#include "Initialisers.h"

CameraInitialiser::CameraInitialiser(const CameraInitSettings& rSettings)
{
	this->settings = rSettings;
}

bool CameraInitialiser::init()
{
	camera = new Base::ViewCamera();
	camera->setPos(&settings.pos);
	//camera->setParentAnchor(&settings.pos);
	return true;
}

Base::ViewCamera * CameraInitialiser::getCamera()
{
	return camera;
}
