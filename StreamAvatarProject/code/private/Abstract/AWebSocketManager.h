#pragma once

#include "Poco/net/httpsclientsession.h"
#include "Poco/net/httpclientsession.h"
#include "Poco/URI.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/net/websocket.h"
#include "Poco/net/sslmanager.h"
#include "Poco/sharedptr.h"
#include "Poco/Net/KeyConsoleHandler.h"
#include "Poco/Net/ConsoleCertificateHandler.h"
#include "Poco/Net/AcceptCertificateHandler.h"

using Poco::Net::Context;
using Poco::SharedPtr;
using Poco::Net::AcceptCertificateHandler;
using Poco::Net::HTTPSClientSession;
using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::URI;
using Poco::Net::SSLManager;
using Poco::Net::WebSocket;

class AWebSocketManager
{
protected:
	bool m_isPing;
	bool m_bReceiveData;
	unsigned short m_receiveRate;

	WebSocket* m_pWs = nullptr;
	
	bool _initSocket(const std::string& rWssAddress, unsigned short port);
	int _sendFrame(const std::string& rPayload);
	std::string* _receiveFrame();
	virtual void _sendPong() = 0;

public:
	~AWebSocketManager();
	virtual bool init() = 0;
	virtual void recievingData() = 0;
	virtual void stop() = 0;
};

