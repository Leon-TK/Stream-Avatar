#pragma once

#include "thirdparty/Poco/Net/HTTPSClientSession.h"
#include "thirdparty/Poco/Net/HTTPResponse.h"
#include "thirdparty/Poco/JSON/Object.h"

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

