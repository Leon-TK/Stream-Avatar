#include "ASocketManager.h"

void ASocketManager::_initSocket(const std::string& rSAddress, int port)
{
	m_pSocket->_initSocket(rSAddress, port);
}

std::string ASocketManager::_receive()
{
	return m_pSocket->receiveData();
}

bool ASocketManager::_send(const std::string& rStr)
{
	return m_pSocket->sendData(rStr);
}



void ASocketManager::setSocket(ISocket& rSocket)
{
	this->m_pSocket = &rSocket;
}

ASocketManager::~ASocketManager()
{
	delete m_pSocket;
}
