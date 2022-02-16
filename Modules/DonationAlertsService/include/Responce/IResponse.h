#pragma once

#include "Poco/Net/HTTPSClientSession.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/JSON/Object.h"

#include "Incl.h"
#include "Variables.h"
#include "Defines.h"

class AResponse
{
public:
	Poco::Net::HTTPSClientSession* m_pS; = nullptr
	AResponse(Poco::Net::HTTPSClientSession& rS);
	virtual std::istream& process() = 0;
};

