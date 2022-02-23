#pragma once

#include "thirdparty/Poco/net/httpsclientsession.h"
#include "thirdparty/Poco/net/httpclientsession.h"
#include "thirdparty/Poco/URI.h"
#include "thirdparty/Poco/Net/HTTPRequest.h"
#include "thirdparty/Poco/Net/HTTPResponse.h"
#include "thirdparty/Poco/Net/StreamSocket.h"
#include "thirdparty/Poco/Net/SocketStream.h"
#include "thirdparty/Poco/net/sslmanager.h"
#include "thirdparty/Poco/sharedptr.h"
#include "thirdparty/Poco/Net/KeyConsoleHandler.h"
#include "thirdparty/Poco/Net/ConsoleCertificateHandler.h"
#include "thirdparty/Poco/Net/AcceptCertificateHandler.h"
#include "thirdparty/Poco/StreamCopier.h"
#include "thirdparty/Poco/Net/RawSocket.h"

#include "ISocket.h"
#include "SocketSFML.h"

using Poco::Net::Context;
using Poco::SharedPtr;
using Poco::Net::AcceptCertificateHandler;
using Poco::Net::HTTPSClientSession;
using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::URI;
using Poco::Net::SSLManager;
using Poco::Net::StreamSocket;
using Poco::Net::RawSocket;
using Poco::Net::SocketAddress;
using Poco::Net::SocketInputStream;
using Poco::Net::SocketOutputStream;
using Poco::StreamCopier;

class ASocketManager
{
protected:
	bool m_isPing;
	bool m_bReceiveData;
	unsigned short m_receiveRate;

	ISocket* m_pSocket = nullptr;

	void _initSocket(const std::string& rSAddress, int port);
	std::string _receive();
	bool _send(const std::string& rStr);

	virtual void _sendPong() = 0;
	
public:
	~ASocketManager();

	void setSocket(ISocket& rSocket);

	virtual void init() = 0;
	virtual void recievingData() = 0;
	virtual void stop() = 0;
};

