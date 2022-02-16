#include "TwitchParsers.h"

PrivateMessageParser::PrivateMessageParser(twitchTags::PrivateMessage& rMsg)
{
	this->msg = msg;
}

void PrivateMessageParser::parse()
{
}

UserNoticeParser::UserNoticeParser(twitchTags::UserNotice& rMsg)
{
	this->msg = msg;
}
void UserNoticeParser::parse()
{
}
UserStateParser::UserStateParser(twitchTags::UserState& rMsg)
{
	this->msg = msg;
}
void UserStateParser::parse()
{
}
UnknownParser::UnknownParser(twitchTags::Unknown& rMsg)
{
	this->msg = msg;
}

void UnknownParser::parse()
{
}

twitchEnums::ETag TwitchParserUtil::getTag(const std::string& rData)
{
	if (data->rfind(":tmi.twitch.tv PRIVMSG #"))
	{
		return twitchEnums::ETag::PRIVMSG;
	}
	if (data->rfind(":tmi.twitch.tv USERNOTICE #"))
	{
		return twitchEnums::ETag::USERNOTICE;
	}
	if (data->rfind(":tmi.twitch.tv USERSTATE #"))
	{
		return twitchEnums::ETag::USERSTATE;
	}
	
	return twitchEnums::ETag::UNKNOWN;
}

std::vector<std::string>* TwitchParserUtil::getParameters(const std::string& rData)
{
	std::vector<std::string>* str = new std::vector<std::string>();

	for (std::string::size_type i = 0; i < data->size(); ++i)
	{
		std::string buffer;
		

	}

	return nullptr;
}
