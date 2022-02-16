#pragma once

#include <iostream>
#include <assert.h>
#include <mutex>
//#include <memory>

#include "Poco/net/websocket.h"
#include "Poco/net/httpclientsession.h"
#include "Poco/net/httprequest.h"
#include "poco/net/httpresponse.h"
#include "Poco/net/serversocket.h"
#include "Poco/net/netexception.h"
#include "Poco/exception.h"
#include "Poco/net/httpsclientsession.h"
#include "Poco/URI.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPMessage.h"
#include "Poco/Net/WebSocket.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/uristreamopener.h"
#include "Poco/streamcopier.h"
#include "poco/path.h"
#include "poco/uri.h"
#include "Poco/sharedptr.h"
#include "Poco/exception.h"
#include "Poco/net/httpstreamfactory.h"
#include "Poco/net/httpsstreamfactory.h"
#include "Poco/net/ftpstreamfactory.h"
#include "Poco/net/sslmanager.h"
#include "Poco/net/keyconsolehandler.h"
#include "Poco/net/consolecertificatehandler.h"
#include "Poco/net/acceptcertificatehandler.h"
#include "Poco/net/securestreamsocket.h"
#include "poco/net/x509certificate.h"

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

