#pragma once

#include "ASocketManager.h"
#include "AWebSocketManager.h"
#include "SocketSFML.h"
#include "ByteConverters.h"

#define G_TwitchSocketManager_ONLY
#define G_TwitchSocketManager_COUT_TEST

class TwitchApi;

class TwitchSocketManager: public ASocketManager
{
private:
	TwitchApi* m_pApi = nullptr;
	bool m_bTest;

	void _sendPass();
	void _sendNick();
	void _sendJoin();
	void _sendRequestForAdvancedCommands();
	void _sendMsg(const std::string& rData);
	void _sendPong() override final;
	
public:
	TwitchSocketManager();
	TwitchSocketManager(unsigned short receiveRate);
	~TwitchSocketManager();

	void recievingData() override final;
	void stop() override final;

	void init() override final;
	void setApi(TwitchApi& rApi);
};

#ifndef G_TwitchSocketManager_ONLY
class TwitchWebSocketManager : public IWebSocketManager
{
private:
	TwitchApi* m_pApi = nullptr;

	void sendPass();
	void sendNick();
	void sendJoin();
	void sendPong() override final;

public:
	TwitchWebSocketManager();
	TwitchWebSocketManager(unsigned short receiveRate);
	~TwitchWebSocketManager();

	void recievingData() override final;
	void stop() override final;

	bool init() override final;
	void setApi(TwitchApi& rApi);
};
#endif