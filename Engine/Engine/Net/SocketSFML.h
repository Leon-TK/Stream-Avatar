#pragma once

#include "SFML\Network\TcpSocket.hpp"
#include "SFML\Network\Packet.hpp"
#include "SFML\Network\IpAddress.hpp"
#include "SFML\Network\SocketHandle.hpp"

#include "ISocket.h"
//#include "TwitchSocketManager.h"

using sf::TcpSocket;
using sf::Packet;
using sf::IpAddress;
using sf::SocketHandle;

#define G_SOCKETSFML_COUT_TEST
class SocketSFML: public ISocket //TODO move class to other module, e.g. core/socket
{
private:
	TcpSocket m_socket;

public:
	SocketSFML();

	bool initSocket(const std::string& rAddress, int port) override final;
	void stop() override final;
	bool sendBuffer(const std::vector<char>& rData) override final;
	bool sendBuffer(const std::vector<wchar_t>& rData) override final;
	bool sendBuffer(const std::vector<uint8_t>& rData) override final;
	bool sendData(const std::string& rData) override final;
	std::string receiveData() override final;
};

