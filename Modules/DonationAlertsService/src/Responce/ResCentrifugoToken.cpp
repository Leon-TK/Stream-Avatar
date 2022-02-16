#include "ResCentrifugoToken.h"

ResCentrifugoToken::ResCentrifugoToken(Poco::Net::HTTPSClientSession& rS) : IResponse(rS)
{
}

std::istream& ResCentrifugoToken::Pprocess()
{
	Poco::Net::HTTPResponse response;
	//stream
	std::istream& is = rS->receiveResponse(response);
	return is;
}
