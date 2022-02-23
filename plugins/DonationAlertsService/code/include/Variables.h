#pragma once

#include <string>

class Variables
{
public:
	static std::string centrifugoToken;
	static std::string accessCode;
	static std::string accessToken;
	static std::string subscribeAccessToken;
	static std::string refreshToken;
	static std::string centrifugoID;
	static std::string userID;
	static std::string centrifugoChannel;
	static std::string centrifugoChannelToken;
	static bool IsPing = false;
};
