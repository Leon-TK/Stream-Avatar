#pragma once

#include <iostream>
#include <assert.h>
#include <mutex>
//#include <memory>

#include "thirdparty/Poco/net/websocket.h"
#include "thirdparty/Poco/net/httpclientsession.h"
#include "thirdparty/Poco/net/httprequest.h"
#include "thirdparty/Poco/net/httpresponse.h"
#include "thirdparty/Poco/net/serversocket.h"
#include "thirdparty/Poco/net/netexception.h"
#include "thirdparty/Poco/exception.h"
#include "thirdparty/Poco/net/httpsclientsession.h"
#include "thirdparty/Poco/URI.h"
#include "thirdparty/Poco/Net/HTTPRequest.h"
#include "thirdparty/Poco/Net/HTTPResponse.h"
#include "thirdparty/Poco/Net/HTTPMessage.h"
#include "thirdparty/Poco/Net/WebSocket.h"
#include "thirdparty/Poco/Net/SocketStream.h"
#include "thirdparty/Poco/Net/HTTPClientSession.h"
#include "thirdparty/Poco/uristreamopener.h"
#include "thirdparty/Poco/streamcopier.h"
#include "thirdparty/Poco/path.h"
#include "thirdparty/Poco/uri.h"
#include "thirdparty/Poco/sharedptr.h"
#include "thirdparty/Poco/exception.h"
#include "thirdparty/Poco/net/httpstreamfactory.h"
#include "thirdparty/Poco/net/httpsstreamfactory.h"
#include "thirdparty/Poco/net/ftpstreamfactory.h"
#include "thirdparty/Poco/net/sslmanager.h"
#include "thirdparty/Poco/net/keyconsolehandler.h"
#include "thirdparty/Poco/net/consolecertificatehandler.h"
#include "thirdparty/Poco/net/acceptcertificatehandler.h"
#include "thirdparty/Poco/net/securestreamsocket.h"
#include "thirdparty/Poco/net/x509certificate.h"

#include "Incl.h"
#include "Defines.h"
#include "UtilsMessage.h"
#include "CentrifugoInclude.h"
#include "DonateData.h"

using Poco::Net::HTTPSClientSession;
using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::WebSocket;
using Poco::Net::WebSocketException;
using Poco::Exception;

using Poco::URIStreamOpener;
using Poco::StreamCopier;
using Poco::Path;
using Poco::URI;

using Poco::Exception;
using Poco::Net::HTTPStreamFactory;
using Poco::Net::HTTPSStreamFactory;
using Poco::Net::FTPStreamFactory;
using Poco::Net::SSLManager;
using Poco::Net::Context;
using Poco::Net::KeyConsoleHandler;
using Poco::Net::PrivateKeyPassphraseHandler;
using Poco::Net::InvalidCertificateHandler;
using Poco::Net::ConsoleCertificateHandler;
using Poco::Net::AcceptCertificateHandler;
using Poco::Net::X509Certificate;


class UWebSocketManager
{
private:
	UtilsMessage m_um;
	WebSocket * m_pWs = nullptr;
	std::vector<DonateData> m_donateData;
	//std::mutex mtx;

public:
	UWebSocketManager();
	~UWebSocketManager();

	std::vector<DonateData>* getDonateData();
	bool isPing;
	bool recieveData;
	void sendSocketToken();
	void sendToken();
	void sendPong();
	bool initSocket();
	void recievingData();
};

