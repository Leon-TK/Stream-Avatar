#pragma once

#include "ICentrifugoMsg.h"

class UCentrifugoMsg1 : public ICentrifugoMsg
{
public:
	UCentrifugoMsg1();
	std::string getMsg();
};

class UCentrifugoMsg2 : public ICentrifugoMsg
{
public:
	UCentrifugoMsg2();
	std::string getMsg();
};

class UCentrifugoMsg3 : public ICentrifugoMsg
{
public:
	UCentrifugoMsg3();
	std::string getMsg();
};
