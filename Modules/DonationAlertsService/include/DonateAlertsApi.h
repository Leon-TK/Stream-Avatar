#pragma once

#include <thread>

#include "thirdparty/Poco/Thread.h"

#include "Incl.h"
#include "UParseManager.h"
#include "URequestMananger.h"
#include "UWebSocketManager.h"


class SSLInitializer {
public:
	SSLInitializer() { Poco::Net::initializeSSL(); }

	~SSLInitializer() { Poco::Net::uninitializeSSL(); }
};

class DonateAlertsApi
{
private:

	void _constructAuthUrl();
	void _extractAccessCode();

	bool _sendAccessTokenRequest();
	bool _sendRefreshToken(); //optional
	bool _sendProfileInfoRequest();
	bool _sendSocketTokenMsg();
	bool _sendCentrifugoSubscribeRequest();
	bool _sendConnectionTokenMsg();
	void _recieveData();
	std::thread* m_pThread = nullptr;

public:
	SSLInitializer sslInitializer;
	UParseManager prs;
	URequestMananger rss;
	UWebSocketManager wm;

	DonateAlertsApi();

	void start();
	void stopRecieveData();
	void test();

	std::thread* getThread();
};

