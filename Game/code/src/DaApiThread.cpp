#pragma once

#include "DaApiThread.h"

void DaApiThread::setUp()
{
	m_Api.start();
}

void DaApiThread::update()
{
	//Api.recieveData();
}

DonateAlertsApi* DaApiThread::getApi()
{
	return &m_Api;
}