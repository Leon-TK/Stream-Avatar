#include "SocketSFML.h"
#include <iostream>
#include "ByteConverters.h"
SocketSFML::SocketSFML()
{
}

bool SocketSFML::initSocket(const std::string& rAddress, int port)
{
	IpAddress ip(*address);
	if (socket.connect(ip, *port) == sf::Socket::Status::Done)
	{
		IpAddress ip2 = socket.getRemoteAddress();
		if (ip2 == IpAddress::None)
		{
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "no address";
			std::cout << std::endl;
#endif
		}
#ifdef G_SOCKETSFML_COUT_TEST
		std::cout << ip2.toString();
		std::cout << std::endl;
#endif
		socket.setBlocking(1);
		//socket ssetings here
		return true;
	}
	else
	{
		return false;
	}
}

void SocketSFML::stop()
{
	socket.disconnect();
}

bool SocketSFML::sendBuffer(const std::vector<char>& rData)
{
	sf::Socket::Status st = socket.send(data->data(), data->size());
	//sf::Socket::Status st = socket.send(data->c_str(), data->size() + 1);
	if (st == sf::Socket::Status::Done)
	{
#ifdef G_SOCKETSFML_COUT_TEST
		//std::cout << "Sended " << data;
		std::cout << std::endl;
#endif
		return true;
	}
	else
	{
		switch (st)
		{
		case sf::Socket::NotReady:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "NotReady";
			std::cout << std::endl;
#endif
			return false;
			break;
		case sf::Socket::Partial:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "Partial";
			std::cout << std::endl;
#endif
			return false;
			break;
		case sf::Socket::Disconnected:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "Disconnected";
			std::cout << std::endl;
#endif
			return false;
			break;
		case sf::Socket::Error:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "Error";
			std::cout << std::endl;
#endif
			return false;
			break;
		default:
			return false;
			break;
		}
	}
}

bool SocketSFML::sendBuffer(const std::vector<wchar_t>& rData)
{
	sf::Socket::Status st = socket.send(data->data(), data->size());
	//sf::Socket::Status st = socket.send(data->c_str(), data->size() + 1);
	if (st == sf::Socket::Status::Done)
	{
#ifdef G_SOCKETSFML_COUT_TEST
		//std::cout << "Sended " << data;
		std::cout << std::endl;
#endif
		return true;
	}
	else
	{
		switch (st)
		{
		case sf::Socket::NotReady:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "NotReady";
			std::cout << std::endl;
#endif
			return false;
			break;
		case sf::Socket::Partial:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "Partial";
			std::cout << std::endl;
#endif
			return false;
			break;
		case sf::Socket::Disconnected:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "Disconnected";
			std::cout << std::endl;
#endif
			return false;
			break;
		case sf::Socket::Error:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "Error";
			std::cout << std::endl;
#endif
			return false;
			break;
		default:
			return false;
			break;
		}
	}
}

bool SocketSFML::sendBuffer(const std::vector<uint8_t>& rData)
{
	sf::Socket::Status st = socket.send(data->data(), data->size());
	//sf::Socket::Status st = socket.send(data->c_str(), data->size() + 1);
	if (st == sf::Socket::Status::Done)
	{
#ifdef G_SOCKETSFML_COUT_TEST
		std::cout << "Sended " << data;
		std::cout << std::endl;
#endif
		return true;
	}
	else
	{
		switch (st)
		{
		case sf::Socket::NotReady:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "NotReady";
			std::cout << std::endl;
#endif
			return false;
			break;
		case sf::Socket::Partial:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "Partial";
			std::cout << std::endl;
#endif
			return false;
			break;
		case sf::Socket::Disconnected:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "Disconnected";
			std::cout << std::endl;
#endif
			return false;
			break;
		case sf::Socket::Error:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "Error";
			std::cout << std::endl;
#endif
			return false;
			break;
		default:
			return false;
			break;
		}
	}
}

bool SocketSFML::sendData(const std::string& rData)
{
	//ByteConverter bc;
	//std::vector<char>* buffer = bc.convert(data);

	//sf::Socket::Status st = socket.send(buffer->data(), buffer->size());
	//delete buffer;
	sf::Socket::Status st = socket.send(data->c_str(), data->size() + 1);
	if (st == sf::Socket::Status::Done)
	{
#ifdef G_SOCKETSFML_COUT_TEST
		std::cout << "Sended " << *data;
		std::cout << std::endl;
#endif
		return true;
	}
	else
	{
		switch (st)
		{
		case sf::Socket::NotReady:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "NotReady";
			std::cout << std::endl;
#endif
			return false;
			break;
		case sf::Socket::Partial:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "Partial";
			std::cout << std::endl;
#endif
			return false;
			break;
		case sf::Socket::Disconnected:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "Disconnected";
			std::cout << std::endl;
#endif
			return false;
			break;
		case sf::Socket::Error:
#ifdef G_SOCKETSFML_COUT_TEST
			std::cout << "Error";
			std::cout << std::endl;
#endif
			return false;
			break;
		default:
			return false;
			break;
		}
	}
}

std::string SocketSFML::receiveData()
{
	//Packet pck;
	std::vector<char> buffer(1024);
	std::size_t received = 0;
	std::string str;
	//sf::Socket::Status ts = 
	socket.receive(&buffer[0], buffer.size(), received);
	str.append(buffer.begin(), buffer.end());
	return str;
	//if (pck >> *str)
	//{
	//	return str;
	//}
	//else
	//{
	//	return new std::string("none");
	//}
}
