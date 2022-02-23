#pragma once

#include "Configuration.h"

class ISubProgram;

class SubProgramManager
{
private:
	Configuration m_config;

	ISubProgram* _getAudioProgram();
	ISubProgram* _getGraphicProgram();
	ISubProgram* _getGame1Program();
	ISubProgram* _getDaApiProgram();
	ISubProgram* _getTwitchApiProgram();

	void _loadConfig(const std::string& rPath);

	void _initGraphic();
	void _initCamera();
	void _initDonationAlerts(unsigned int recvRate = 10000, const std::string& rType = nullptr);
	void _initTwitchAlerts(unsigned int recvRate = 1000, unsigned int sendRate = 1000, unsigned int sendBufferSize = 1024, unsigned int recvBufferSize = 1024, const std::string& rType = nullptr);
	void _initAudio();
	void _initGame1();

	void _setup();

public:
	

};

