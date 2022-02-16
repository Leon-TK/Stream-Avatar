#pragma once
#include "Poco/Net/HTTPRequest.h"
#include "Poco/JSON/Object.h"

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