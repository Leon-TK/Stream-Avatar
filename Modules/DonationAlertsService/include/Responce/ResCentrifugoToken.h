#pragma once

#include "IResponse.h"

class ResCentrifugoToken : public IResponse
{
	public:
	ResCentrifugoToken(Poco::Net::HTTPSClientSession& rS);
	std::istream& process();
};

