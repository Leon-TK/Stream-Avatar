#include "ResCentrifugoSubscribe.h"

ResCentrifugoSubscribe::ResCentrifugoSubscribe(Poco::Net::HTTPSClientSession& rS) : IResponse(rS)
{
}

std::istream& ResCentrifugoSubscribe::process()
{
	Poco::Net::HTTPResponse response;
	//stream
	std::istream& is = s->receiveResponse(response);
	return is;
}
