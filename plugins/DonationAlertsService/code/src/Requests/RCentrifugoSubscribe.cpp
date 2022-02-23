#include "RCentrifugoSubscribe.h"

RCentrifugoSubscribe::RCentrifugoSubscribe()
{
}

Poco::Net::HTTPRequest * RCentrifugoSubscribe::getRequest()
{
	//Request
	Poco::Net::HTTPRequest* request = new Poco::Net::HTTPRequest(Poco::Net::HTTPRequest::HTTP_POST, std::string(CENTRIFUGOSUBSCRIBEENDPOINT), Poco::Net::HTTPMessage::HTTP_1_1);
	std::string str = "Bearer " + Variables::m_AccessToken;
	request->add("Authorization", str);
	request->setContentType("application/json");
	return request;
}
