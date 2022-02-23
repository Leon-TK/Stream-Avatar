#include "DonateAlertsApi.h"

DonateAlertsApi::DonateAlertsApi()
{
}

void DonateAlertsApi::start()
{
	ConstructAuthUrl();
	ExtractAccessCode();

	SendAccessTokenRequest();
		Poco::Thread::sleep(1100);
	//SendRefreshToken(); //optional
	SendProfileInfoRequest();
		Poco::Thread::sleep(1100);
	SendSocketTokenMsg();
	SendCentrifugoSubscribeRequest();
	SendConnectionTokenMsg();
	//RecieveData();
}

void DonateAlertsApi::stopRecieveData()
{
	wm.recieveData = 0;
}

void DonateAlertsApi::test()
{
}

void DonateAlertsApi::constructAuthUrl()
{
	std::string url = prs.ConstructAouthUrl();

	//Show url
	std::cout << url;
	std::cout << std::endl;
}

void DonateAlertsApi::extractAccessCode()
{
	std::string url;
	std::cin >> url;
	std::cout << std::endl;

	Variables::m_AccessCode = prs.ExtractAccessCode(url);
}


bool DonateAlertsApi::sendAccessTokenRequest()
{
	rss.SendAccessTokenRequest();
	return false;
}

bool DonateAlertsApi::sendRefreshToken()
{
	return false;
}

bool DonateAlertsApi::sendProfileInfoRequest()
{
	rss.SendCentrifugoTokenRequest();
	return false;
}

bool DonateAlertsApi::sendSocketTokenMsg()
{
	wm.SendSocketToken();
	return false;
}

bool DonateAlertsApi::sendCentrifugoSubscribeRequest()
{
	rss.SendCentrifugeSubscribe();
	return false;
}

bool DonateAlertsApi::sendConnectionTokenMsg()
{
	wm.SendToken();
	return false;
}

void DonateAlertsApi::recieveData()
{
	wm.RecievingData();
}

std::thread* DonateAlertsApi::getThread()
{
	return new std::thread(&DonateAlertsApi::RecieveData, this);
}
