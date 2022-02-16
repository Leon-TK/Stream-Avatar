#pragma once

#include "Defines.h"
#include "Poco\JSON\Parser.h"
#include "Poco\JSON\Object.h"
#include "Poco\JSON\Stringifier.h"
#include "Poco\JSON\JSON.h"

#include "Incl.h"
#include "Variables.h"

class ICentrifugoMsg
{
public:
	virtual ~ICentrifugoMsg() {};
	virtual std::string getMsg() = 0;
};

