#include "WebSocketMessages.h"
WsMessages::DonateMessage::DonateMessage(const std::string& rMsg, const std::vector<DonateData>& rDonateData) : IWebSocketMessage(rMsg)
{
	this->donateData = rDonateData;
}

WsMessages::PingMessage::pingMessage()
{
}

WsMessages::CentrifugoIDMessage::CentrifugoIDMessage(const std::string& rMsg) : IWebSocketMessage(rMsg)
{
}

WsMessages::UnknownMessageWs::UnknownMessageWs(const std::string& rMsg) : IWebSocketMessage(rMsg)
{
}
WsMessages::EmptyMessageWs::EmptyMessageWs()
{
}

void WsMessages::DonateMessage::process()
{
	cout << "DonateMessage: ";
	cout << m_data;
	cout << std::endl;
	//TODO: mutex
	DonateData dd = ParseData(&m_data);
	mtx.lock();
	donateData->push_back(dd);
	donateData->shrink_to_fit();
	mtx.unlock();

}

DonateData WsMessages::DonateMessage::parseData(const std::string& rData)
{
	DonateData dd;
	int u = rData->find("\"username\"");
	int n = rData->find("\"name\"");
	dd.type = rData->substr(n + 8, (u - 2) - (n + 8));
	std::cout << dd.type;
	std::cout << std::endl;
	int mt = rData->find("\"message_type\"");
	dd.username = rData->substr(u + 12, (mt - 2) - (u + 12));
	std::cout << dd.username;
	std::cout << std::endl;
	int ms = rData->find("\"message\"");
	int am = rData->find("\"amount\"");
	dd.message = rData->substr(ms + 11, (am - 2) -( ms + 11));
	std::cout << dd.message;
	std::cout << std::endl;
	int cr = rData->find("\"currency\"");
	dd.value = std::stof(rData->substr(am + 9, (cr-1) - (am + 9)));
	std::cout << dd.value;
	std::cout << std::endl;
	return dd;
}

void WsMessages::PingMessage::process()
{
	cout << "PingMessage: ";
	cout << std::endl;
	Variables::IsPing = 1;
}

void WsMessages::CentrifugoIDMessage::process()
{
	cout << "CentrifugoIDMessage: ";
	cout << m_data;
	cout << std::endl;

	string tmp1 = m_data.substr(m_data.find("client") + 9);
	tmp1.erase(tmp1.length() - 17);
	cout << tmp1;
	cout << std::endl;
	Variables::m_CentrifugoID = tmp1;

}


void WsMessages::UnknownMessageWs::process()
{
	cout << "UnknownMessageWs: ";
	cout << m_data;
	cout << std::endl;
}

void WsMessages::EmptyMessageWs::process()
{
	cout << "EmptyMessageWs: ";
	cout << std::endl;
}













