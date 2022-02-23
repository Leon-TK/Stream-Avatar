#pragma once

#include "Defines.h"
#include "thirdparty/Poco/JSON/Parser.h"
#include "thirdparty/Poco/JSON/Object.h"
#include "thirdparty/Poco/JSON/Stringifier.h"
#include "thirdparty/Poco/JSON/JSON.h"

#include "Incl.h"
#include "Variables.h"

class ICentrifugoMsg
{
public:
	virtual ~ICentrifugoMsg() {};
	virtual std::string getMsg() = 0;
};

