#pragma once

#include "IResponse.h"

class ResCentrifugoSubscribe : public IResponse
{
public:
	ResCentrifugoSubscribe(Poco::Net::HTTPSClientSession& rS);
	std::istream& process();
};

