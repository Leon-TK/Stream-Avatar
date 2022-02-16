#pragma once

#include "Incl.h"
#include "Variables.h"

class AWebSocketMessage
{
public:
	AWebSocketMessage(const std::string& rData);
	AWebSocketMessage();
	~AWebSocketMessage();
	std::string data;
	virtual void process() = 0;
};

