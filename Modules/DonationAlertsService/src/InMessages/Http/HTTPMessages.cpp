#include "HTTPMessages.h"

AccessTokenMessage::AccessTokenMessage(const std::string& rMsg) : IResponseMessage(rMsg)
{
}

bool AccessTokenMessage::Handle()
{
	std::cout << "AccessTokenMessage: ";
	std::cout << std::endl;
	std::cout << m_data;
	std::cout << std::endl;

	std::string tmp1 = m_data.substr(m_data.find("access_token") + 15);

	//std::cout << tmp1;
	//std::cout << std::endl;

	std::string tmp2 = tmp1.erase(tmp1.find("\",\"refresh_token\""), tmp1.length());
	Variables::m_AccessToken = tmp2;
	//std::cout << tmp2;
	//std::cout << std::endl;

	//std::cout << m_data.find("\"refresh_token\"");
	//std::cout << std::endl;

	std::string tmp3 = m_data.substr(m_data.find("\",\"refresh_token\"") + 19);
	//std::cout << tmp3;
	//std::cout << std::endl;
	std::string tmp4 = tmp3.erase(tmp3.find("\"}"), 2);
	Variables::m_RefreshToken = tmp4;
	//std::cout << tmp4;
	//std::cout << std::endl;

	return true;
}
CentrifugoTokenMessage::CentrifugoTokenMessage(const std::string& rMsg) : IResponseMessage(rMsg)
{
}

bool CentrifugoTokenMessage::Handle()
{
	std::cout << "CentrifugoTokenMessage: ";
	std::cout << std::endl;
	std::cout << m_data;
	std::cout << std::endl;



	std::string tmp1 = m_data.substr(m_data.find("\"id\"") + 5);
	std::cout << tmp1;
	std::cout << std::endl;
	std::string tmp2 = tmp1.erase(tmp1.find(",\"code"), tmp1.length() - tmp1.find(",\"code"));
	std::cout << tmp2;
	std::cout << std::endl;
	Variables::m_UserID = tmp2;

	std::string tmp3 = m_data.substr(m_data.find("socket_connection_token") + 26);
	std::cout << tmp3;
	std::cout << std::endl;

	std::string tmp4 = tmp3.erase(tmp3.length() - 3);
	std::cout << tmp4;
	std::cout << std::endl;
	Variables::m_CentrifugoToken = tmp4;

	return true;
}

CentrifugoChannelMessage::CentrifugoChannelMessage(const std::string& rMsg) : IResponseMessage(rMsg)
{
}

bool CentrifugoChannelMessage::Handle()
{
	std::cout << "CentrifugoChannelMessage: ";
	std::cout << std::endl;
	std::cout << m_data;
	std::cout << std::endl;

	std::string tmp1 = m_data.substr(m_data.find("channel\":\"") + 10);
	std::cout << tmp1;
	std::cout << std::endl;
	std::string tmp2 = tmp1.erase(tmp1.find("\",\"toke"), tmp1.length() - tmp1.find("\",\"toke"));
	std::cout << tmp2;
	std::cout << std::endl;
	Variables::m_CentrifugoChannel = tmp2;

	std::string tmp3 = m_data.substr(m_data.find("\"token\":\"") + 9);
	std::cout << tmp3;
	std::cout << std::endl;

	std::string tmp4 = tmp3.erase(tmp3.length() - 4);
	std::cout << tmp4;
	std::cout << std::endl;
	Variables::m_CentrifugoChannelToken = tmp4;

	return true;
}

UnknownMessage::UnknownMessage(const std::string& rMsg) : IResponseMessage(rMsg)
{
}

bool UnknownMessage::Handle()
{
	std::cout << "Unknown message is recieved:";
	std::cout << std::endl;
	std::cout << m_data;
	return true;
}

EmptyMessage::EmptyMessage(const std::string& rMsg) : IResponseMessage(rMsg)
{
}

bool EmptyMessage::Handle()
{
	std::cout << "Empty message";
	return true;
}


