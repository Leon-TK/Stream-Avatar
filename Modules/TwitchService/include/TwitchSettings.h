#pragma once

#include <string>

struct TwitchApiSettings
{
	std::string username;    //
	std::string channelName; //
	std::string pass;        //
	std::string sAddress;    //irc.chat.twitch.tv
	std::string wssAddress;  //wss://irc-ws.chat.twitch.tv
	unsigned short wssPort;  //443
	int sPort;  //6667
};