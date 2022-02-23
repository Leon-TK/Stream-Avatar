#include "CentrifugoMessages.h"

UCentrifugoMsg1::UCentrifugoMsg1()
{
}

std::string UCentrifugoMsg1::getMsg()
{

	std::string stg = "{\"params\":{\"token\":\"" + Variables::m_CentrifugoToken + "\"},\"id\":1}";
	std::cout << stg;
	std::cout << std::endl;

	return stg;
}

UCentrifugoMsg2::UCentrifugoMsg2()
{
}

std::string UCentrifugoMsg2::getMsg()
{
	std::string stg = "{\"channels\":[\"$alerts:donation_" + Variables::m_UserID + "\"], \"client\":\"" + Variables::m_CentrifugoID + "\"}";
	std::cout << stg;
	std::cout << std::endl;
	return stg;
}

UCentrifugoMsg3::UCentrifugoMsg3()
{
}

std::string UCentrifugoMsg3::getMsg()
{
	std::string stg = "{\"params\":{\"channel\":\"" + Variables::m_CentrifugoChannel + "\",\"token\":\"" + Variables::m_CentrifugoChannelToken + "\"},\"method\":1,\"id\":2}";
	std::cout << stg;
	std::cout << std::endl;
	return stg;
}

