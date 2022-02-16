#include "UWebSocketManager.h"

std::vector<DonateData>* UWebSocketManager::getDonateData()
{
	return &donateData;
}

UWebSocketManager::UWebSocketManager()
{
	um.setDonateData(&donateData);
	IsPing = 0;
	recieveData = 0;
	InitSocket();
}

UWebSocketManager::~UWebSocketManager()
{
	ws->shutdown();
}

void UWebSocketManager::sendSocketToken()
{
	char data[1024];
	int flags;
	int n;
	std::string payload;

try
{

	ICentrifugoMsg* msg = new UCentrifugoMsg1();
	payload = msg->GetMsg();
	delete msg;
	ws->sendFrame(payload.data(), payload.size(), WebSocket::FRAME_TEXT);
	n = ws->receiveFrame(data, sizeof(data), flags);

	std::vector<IWebSocketMessage*> messages;
	messages = um.GetWsMessages(std::string(data, n));
	for (int i = 0; i < messages.size(); ++i)
	{
		messages[i]->Process();
		delete messages[i];
	}
}

catch (Poco::Exception& ex)
{
	std::cout << "Error: " <<__FILE__ << "\": \""<<__LINE__<<"\" : \""<< ex.displayText() << "\"\n";
}

}

void UWebSocketManager::sendToken()
{
	char data[1024];
	int flags;
	int n;
	std::string payload;

	ICentrifugoMsg* msg = new UCentrifugoMsg3();
	payload = msg->GetMsg();
	delete msg;
	ws->sendFrame(payload.data(), payload.size(), WebSocket::FRAME_TEXT);
	n = ws->receiveFrame(data, sizeof(data), flags);
	std::vector<IWebSocketMessage*> messages;
	messages = um.GetWsMessages(std::string(data, n));
	for (int i = 0; i < messages.size(); ++i)
	{
		messages[i]->Process();
		delete messages[i];
	}
	recieveData = 1;
	std::cout << "Initiate complete. You can recieving data now";
	std::cout << std::endl;
}

void UWebSocketManager::sendPong()
{
	std::string payload = "pong";
	ws->sendFrame(payload.data(), payload.size(), WebSocket::FRAME_TEXT);
	Variables::IsPing = 0;
}

bool UWebSocketManager::initSocket()
{
	/*
	SharedPtr<Poco::Net::InvalidCertificateHandler> ptrCert = new AcceptCertificateHandler(false);; //Ask the user via console InitializeClient(0, Pcert, pContext);
	Context::Ptr pContext = new Context(Context::TLS_CLIENT_USE, "", "", "", Context::VERIFY_RELAXED, 9, false, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
	SSLManager::instance().initializeClient(0, ptrCert, pContext);
	*/

	Poco::URI uri(std::string(CENTRIFUGOENDPOINT));
	Poco::Net::HTTPSClientSession s(uri.getHost(), 443); //uri.getPort()

	HTTPRequest request(HTTPRequest::HTTP_GET, uri.getPath(), Poco::Net::HTTPMessage::HTTP_1_1);
	HTTPResponse response;
	std::string cmd;

	ws = new WebSocket(s, request, response); //Causes the timeout

	return false;
}

void UWebSocketManager::recievingData()
{
	while (recieveData)
	{
		
		if (IsPing)
		{
			SendPong();
		}

		char data[1024];
		int flags;
		int n;
		std::string payload;
		
		//Poco::Thread::sleep(1000); // TODO: sleep std thread
		
		n = ws->receiveFrame(data, sizeof(data), flags);
		
		Poco::Thread::sleep(5000); // TODO: sleep std thread
		//std::string s = "{\"data\":[{\"id\":30530030,\"name\":\"donation\",\"username\":\"Ivan\",\"message_type\":\"text\",\"message\":\"Hello!\",\"amount\":500,\"currency\":\"RUB\",\"is_shown\":1,\"created_at\":\"2019-09-29 09:00:00\",\"shown_at\":null}],\"links\":{\"first\":\"https://www.donationalerts.com/api/v1/alerts/donations?page=1\",\"last\":\"https://www.donationalerts.com/api/v1/alerts/donations?page=1\",\"prev\":null,\"next\":null},\"meta\":{\"current_page\":1,\"from\":1,\"last_page\":1,\"path\":\"https://www.donationalerts.com/api/v1/alerts/donations\",\"per_page\":30,\"to\":1,\"total\":1}}";
		std::vector<IWebSocketMessage*> messages;
		//messages = um.GetWsMessages(s);
		messages = um.GetWsMessages(std::string(data, n));
		for (int i = 0; i < messages.size(); ++i)
		{
			messages[i]->Process();
			delete messages[i];
		}
		
	}

}
