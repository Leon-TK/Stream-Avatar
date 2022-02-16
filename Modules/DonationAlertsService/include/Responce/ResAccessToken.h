#pragma once

#include "IResponse.h"

class ResAccessToken: public IResponse
{
public:
	ResAccessToken(Poco::Net::HTTPSClientSession& rS);
	std::istream& process();
};

