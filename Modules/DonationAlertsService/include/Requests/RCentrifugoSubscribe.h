#pragma once

#include "Incl.h"
#include "IProcessRequest.h"

class RCentrifugoSubscribe : public IProcessRequest
{
public:
	RCentrifugoSubscribe();
	
	Poco::Net::HTTPRequest* getRequest();
};

