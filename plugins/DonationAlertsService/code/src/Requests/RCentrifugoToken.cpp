#include "RCentrifugoToken.h"


RCentrifugoToken::RCentrifugoToken(): IProcessRequest() //TODO ?
{
}

Poco::Net::HTTPRequest* RCentrifugoToken::getRequest()
{
	//Request
	Poco::Net::HTTPRequest* request = new Poco::Net::HTTPRequest(Poco::Net::HTTPRequest::HTTP_GET, std::string(CENTRIFUGOTOKENENDPOINT), Poco::Net::HTTPMessage::HTTP_1_1);
	std::string str = "Bearer " + Variables::m_AccessToken;
	request->add("Authorization", str);
	return request;
}


