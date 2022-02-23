#pragma once

#include "DonateAlertsApi.h"

class DaApiThread
{
private:
	DonateAlertsApi m_Api;

public:
	DaApiThread() = default;
	DaApiThread(const DaApiThread&) = delete;
	DaApiThread& operator=(const DaApiThread&) = delete;
	
	void setUp();
	void update();
	DonateAlertsApi* getApi();
};