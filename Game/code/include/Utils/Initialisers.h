#pragma once

#include "sfml\System\Vector2.hpp"

#include "IInitialiser.h"

namespace Base
{
	class ViewCamera;
}

struct CameraInitSettings
{
	sf::Vector2f pos;
};

class CameraInitialiser : public IInitialiser
{
	CameraInitSettings m_settings;
	Base::ViewCamera* m_pCamera = nullptr;

public:
	CameraInitialiser(const CameraInitSettings& rSettings);
	bool init() override final;
	Base::ViewCamera* getCamera();
};

