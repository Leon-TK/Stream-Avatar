#include "TwitchService.h"

TwitchService::TwitchService()
{
	tsm.setApi(this);
	SocketManager = &tsm;
}

void TwitchService::start()
{
	SocketManager->Init();
	SocketManager->RecievingData();
}

void TwitchService::stop()
{
}

std::thread* TwitchService::getThread()
{
	return nullptr;
}
