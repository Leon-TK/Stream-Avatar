#include "AWebSocketManager.h"

AWebSocketManager::~AWebSocketManager()
{
	m_pWs->shutdown();
}

bool AWebSocketManager::initSocket(const std::string& rWssAddress, unsigned short port)
{
	//username("leon_tk_bot"),channelname("leon_tk"), pass("oauth:8puxnbmtktu4xyxxoanrqe3bwplmtj"), wssAddress("wss://irc-ws.chat.twitch.tv"), wssPort(443) //oauth:
	
	//Poco::Net::HTTPCredentials creds("leon_tk_bot", "oauth:8puxnbmtktu4xyxxoanrqe3bwplmtj");
	Poco::Net::initializeSSL();
	SharedPtr<Poco::Net::InvalidCertificateHandler> ptrCert = new AcceptCertificateHandler(false);; //Ask the user via console InitializeClient(0, Pcert, pContext);
	Context::Ptr pContext = new Poco::Net::Context(Poco::Net::Context::TLS_CLIENT_USE, "", "", "", Poco::Net::Context::VERIFY_RELAXED, 9, false, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
	SSLManager::instance().initializeClient(0, ptrCert, pContext);
	
	URI uri(wssAddress);
	HTTPSClientSession s(uri.getHost(), port);

	HTTPRequest request(HTTPRequest::HTTP_GET, uri.getPath(), Poco::Net::HTTPMessage::HTTP_1_1);
	HTTPResponse response;
	return ws = new WebSocket(s, request, response);
}

int AWebSocketManager::sendFrame(const std::string& rPayload)
{
	return m_pWs->sendFrame(payload.data(), payload.size(), WebSocket::FRAME_TEXT);
}

std::string * AWebSocketManager::receiveFrame()
{
	char data[1024];
	int flags;
	int n;
	n = m_pWs->receiveFrame(data, sizeof(data), flags);
	return new std::string(data, n);
}
