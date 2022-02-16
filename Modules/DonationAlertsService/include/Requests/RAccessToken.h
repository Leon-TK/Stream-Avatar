#pragma once

#include "Incl.h"
#include "IProcessRequest.h"

class RAccessToken : public IProcessRequest
{
public:
	RAccessToken();
	
	Poco::Net::HTTPRequest* getRequest();
};

