#pragma once
#include "thirdparty/Poco/Net/HTTPRequest.h"
#include "thirdparty/Poco/JSON/Object.h"

#include "Incl.h"
#include "Variables.h"
#include "Defines.h"

class AProcessRequest
{
public:
	AProcessRequest();
	virtual Poco::Net::HTTPRequest* getRequest() = 0;
	Variables* pVrs = nullptr;
};