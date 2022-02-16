#pragma once

#include "Incl.h"
#include "Variables.h"

class AResponseMessage 
{
public:

	Variables* pVrs = nullptr;
	std::string data;
	AResponseMessage(const std::string& rMsg);
	AResponseMessage();
	virtual bool process() = 0;
};

