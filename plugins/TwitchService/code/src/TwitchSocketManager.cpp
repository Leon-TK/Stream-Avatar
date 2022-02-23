#include "TwitchSocketManager.h"
#include "TwitchApi.h"

#include <locale>
#include <codecvt>

void TwitchSocketManager::sendPass()
{
	std::string str = ("PASS ") + api->pass + ("\r\n");
	if (send(&str))
	{
#ifdef G_TwitchSocketManager_COUT_TEST
		std::cout << "pass failed";
		std::cout << std::endl;
#endif
	}
	//ReceiveStreamData();
}

void TwitchSocketManager::sendNick()
{
	std::string str = ("NICK ") + api->username + ("\r\n");
	if (send(&str))
	{
#ifdef G_TwitchSocketManager_COUT_TEST
		std::cout << "nick failed";
		std::cout << std::endl;
#endif
	}
	//ReceiveStreamData();
}

void TwitchSocketManager::sendJoin()
{
	std::string str = ("JOIN #") + api->channelname + ("\r\n");
	if (send(&str))
	{
#ifdef G_TwitchSocketManager_COUT_TEST
		std::cout << "join failed";
		std::cout << std::endl;
#endif
	}
}

void TwitchSocketManager::sendRequestForAdvancedCommands()
{
	std::string Command1 = ("CAP REQ :twitch.tv/commands\r\n");
	std::string Command2 = ("CAP REQ :twitch.tv/membership\r\n");
	std::string Command3 = ("CAP REQ :twitch.tv/tags\r\n");
	bool c1 = send(&Command1);
	bool c2 = send(&Command2);
	bool c3 = send(&Command3);

	if (c1 || c2 || c3)
	{
#ifdef G_TwitchSocketManager_COUT_TEST
		std::cout << "command failed";
		std::cout << std::endl;
#endif
	}
}

void TwitchSocketManager::sendMsg(const std::string& rData) 
{
	std::string msgCommand = "PRIVMSG #" + api->channelname + " :";
	std::string msgEnd = "\r\n";

	std::string message = msgCommand + *data + msgEnd;
	//ByteConverter bc;
	//std::vector<char>* buffer1 = bc.convert(&msgCommand);
	//std::vector<char>* buffer2 = bc.convert(data);
	//std::vector<char>* buffer3 = bc.convert(&msgEnd);
	//buffer1->insert(buffer1->end(), buffer2->begin(), buffer2->end());
	//buffer1->insert(buffer1->end(), buffer3->begin(), buffer3->end());
	send(&message);
}


TwitchSocketManager::TwitchSocketManager()
{
	bTest = 0;
	setSocket(new SocketSFML());
	m_receiveRate = 1000;
}

TwitchSocketManager::TwitchSocketManager(unsigned short receiveRate)
{
	this->m_receiveRate = receiveRate;
}

TwitchSocketManager::~TwitchSocketManager()
{
}

void TwitchSocketManager::init()
{
	/*
	SharedPtr<Poco::Net::InvalidCertificateHandler> ptrCert = new AcceptCertificateHandler(false);; //Ask the user via console InitializeClient(0, Pcert, pContext);
	Context::Ptr pContext = new Context(Context::TLS_CLIENT_USE, "", "", "", Context::VERIFY_RELAXED, 9, false, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
	SSLManager::instance().initializeClient(0, ptrCert, pContext);
	*/
	//const int port = 1;
	initSocket(&api->sAddress, &api->sPort); //api->wssport
	sendPass();
	sendNick();
	sendRequestForAdvancedCommands();
	sendJoin();
#ifdef G_TwitchSocketManager_COUT_TEST
	std::cout << "Sending cmplete";
	std::cout << std::endl;
#endif
	//ReceiveStreamData();
	m_bReceiveData = 1;
}

void TwitchSocketManager::sendPong()
{
	std::string str = ("PONG");
	send(&str);
}

void TwitchSocketManager::recievingData()
{
	while (m_bReceiveData)
	{
#ifdef G_TwitchSocketManager_COUT_TEST
		std::cout << "Receiving data";
#endif
		if (m_isPing)
		{
			sendPong();
		}
		
		std::string* data = receive();
		//.std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		//..std::wstring data2 = converter.from_bytes(*data);
		std::cout << *data;
		std::cout << std::endl;
		//SendMsg(&std::string(u8"������, Hello"));
		delete data;
		Poco::Thread::sleep(m_receiveRate); // TODO: sleep std thread
		
		
		/*
		while (bTest)
		{
			SendMsg(&std::wstring(L"dsad"));
			bTest = 0;
		}
		*/
	}
}

void TwitchSocketManager::stop()
{
	m_bReceiveData = 0;
	m_socket->Stop();
}

void TwitchSocketManager::setApi(TwitchApi * api)
{
	this->api = api;
}

#ifndef G_TwitchSocketManager_ONLY
void TwitchWebSocketManager::sendPass()
{
	std::string str = "PASS " + api->pass +"\r\n";
	sendFrame(str);
}

void TwitchWebSocketManager::sendNick()
{
	std::string str = "NICK " + api->username +"\r\n";
	sendFrame(str);
}

void TwitchWebSocketManager::sendJoin()
{
	std::string str = "JOIN #" + api->channelname +"\r\n";
	sendFrame(str);
}

void TwitchWebSocketManager::sendPong()
{
}

TwitchWebSocketManager::TwitchWebSocketManager()
{
	receiveRate = 500;
}

TwitchWebSocketManager::TwitchWebSocketManager(unsigned short receiveRate)
{
	this->receiveRate = receiveRate;
}

TwitchWebSocketManager::~TwitchWebSocketManager()
{
}

void TwitchWebSocketManager::recievingData()
{
	while (bReceiveData)
	{
#ifdef G_TwitchSocketManager_COUT_TEST
		std::cout << "Receiving data";
#endif
		if (isPing)
		{
			sendPong();
		}

		std::string* data = receiveFrame();
		//std::cout << data;
		//std::cout << std::endl;
		delete data;
		Poco::Thread::sleep(receiveRate); // TODO: sleep std thread

	}
}

void TwitchWebSocketManager::stop()
{
}

bool TwitchWebSocketManager::init()
{
	/*
	SharedPtr<Poco::Net::InvalidCertificateHandler> ptrCert = new AcceptCertificateHandler(false);; //Ask the user via console InitializeClient(0, Pcert, pContext);
	Context::Ptr pContext = new Context(Context::TLS_CLIENT_USE, "", "", "", Context::VERIFY_RELAXED, 9, false, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
	SSLManager::instance().initializeClient(0, ptrCert, pContext);
	*/
	initSocket(api->wssAddress, api->wssPort);

	sendPass();
	sendNick();
	sendJoin();
#ifdef G_TwitchSocketManager_COUT_TEST
	std::cout << "Sending cmplete";
#endif
	bReceiveData = 1;
	return 1;
}

void TwitchWebSocketManager::setApi(TwitchApi * api)
{
	this->api = api;
}
#endif