#pragma once

#include "Poco/JSON/Parser.h"
#include "Poco/JSON/Object.h"
#include "Poco/JSON/PrintHandler.h"

#include "Incl.h"
#include "Defines.h"
#include "Variables.h"

class UParseManager
{

public:

	UParseManager();

	std::string constructAouthUrl();
	std::string extractAccessCode(const std::string& rUrl);
	std::string constructAccessCodeRequestBody();
	Poco::JSON::Object::Ptr constructAccessCodeRequestJson();
	Poco::JSON::Object::Ptr constructCentrifugoMessage(int type);
	
	//Poco::Dynamic::Var ConstructResponceOnCentrifugoMessage();
};

