#pragma once
#include <string>
#include <vector>

class ISocket
{
public:
	virtual	~ISocket() {};

	virtual bool sendData(const std::string& rData) = 0;
	virtual bool sendBuffer(const std::vector<char>& rData) = 0;
	virtual bool sendBuffer(const std::vector<wchar_t>& rData) = 0;
	virtual bool sendBuffer(const std::vector<uint8_t>& rData) = 0;
	virtual std::string* receiveData() = 0;
	virtual void stop() = 0;
	virtual bool initSocket(const std::string& rAddress, int port) = 0;

};

