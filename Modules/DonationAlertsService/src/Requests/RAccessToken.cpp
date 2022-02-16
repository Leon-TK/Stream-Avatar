#include "RAccessToken.h"

RAccessToken::RAccessToken()
{
}

Poco::Net::HTTPRequest * RAccessToken::getRequest()
{
	Poco::Net::HTTPRequest* request = new Poco::Net::HTTPRequest(Poco::Net::HTTPRequest::HTTP_POST, std::string(DONATIONTOKEN), Poco::Net::HTTPMessage::HTTP_1_1);
	request->setContentType("application/x-www-form-urlencoded");
	
	return request;
}
