#pragma once

#include "thirdparty/Poco/Net/HTTPRequest.h"

#include "Incl.h"
#include "IProcessRequest.h"

class RCentrifugoToken: public IProcessRequest
{
public:
	RCentrifugoToken();
	
	Poco::Net::HTTPRequest* getRequest();
};

