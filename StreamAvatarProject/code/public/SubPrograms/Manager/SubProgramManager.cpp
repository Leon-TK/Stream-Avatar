#include "SubProgramManager.h"


void SubProgramManager::loadConfig(const std::string& rPath)
{
	config.loadConfigFile(rPath);
}

void SubProgramManager::setup()
{
	initGraphic();

#ifndef Program_TEST
	for (auto key : config.getKeys())
	{
		std::cout << key;
		std::cout << std::endl;
	}


	if (config.hasKey("ShowCamera"))
	{
		if (config.getBool("ShowCamera"))
		{
#ifdef Program_COUT_TEST
			//std::cout << configurator.getString("ShowTwitchAlertsType");
#endif
			initCamera();
		}
	}
	if (config.hasKey("ShowDonationAlerts"))
	{
		if (config.getBool("ShowDonationAlerts"))
		{
#ifdef Program_COUT_TEST
			std::cout << "ShowDonationAlerts";
#endif
			if (config.hasKey("ShowDonationAlertsType"))
			{
				InitDonationAlerts(config.getInt("DonationAlertsSocketRate"), &config.getString("ShowDonationAlertsType"));
			}
			else
			{
				InitDonationAlerts(config.getInt("DonationAlertsSocketRate"));
			}
		}
	}
	if (config.hasKey("ShowTwitchAlerts"))
	{
		if (config.getBool("ShowTwitchAlerts"))
		{
#ifdef Program_COUT_TEST
			std::cout << "ShowTwitchAlerts";
#endif
			if (config.hasKey("ShowTwitchAlertsType"))
			{
				initTwitchAlerts(config.getInt("TwitchReceiveSocketRate"), config.getInt("TwitchSendSocketRate"), config.getInt("TwitchSendBufferSize"), config.getInt("TwitchRecvBufferSize"), &config.getString("ShowTwitchAlertsType"));
			}
			else
			{
				initTwitchAlerts(config.getInt("TwitchReceiveSocketRate"), config.getInt("TwitchSendSocketRate"), config.getInt("TwitchSendBufferSize"), config.getInt("TwitchRecvBufferSize"));
			}
		}
	}
	if (config.hasKey("ShowGame1"))
	{
		if (config.getBool("ShowGame1"))
		{
#ifdef Program_COUT_TEST
			std::cout << "ShowGame1";
#endif
			initGame1();
		}
	}
#endif
}

void SubProgramManager::initGraphic()
{

}

void SubProgramManager::initCamera()
{

}

void SubProgramManager::initDonationAlerts(unsigned int recvRate, const std::string& rType)
{
	if (rType == nullptr)
	{

	}
	else
	{

	}
}

void SubProgramManager::initTwitchAlerts(unsigned int recvRate, unsigned int sendRate, unsigned int sendBufferSize, unsigned int recvBufferSize, const std::string& rType)
{
	if (rType == nullptr)
	{

	}
	else
	{

	}
}

void SubProgramManager::initAudio()
{
}

void SubProgramManager::initGame1()
{
}