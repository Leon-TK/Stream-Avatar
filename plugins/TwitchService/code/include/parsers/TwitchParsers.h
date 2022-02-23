#pragma once

#include "TwitchTags.h"
#include "TwitchEnums.h"

class TwitchParserUtil // other parse methods like insert messages to vector by full signature of IRC message with TAG
{
protected:
	std::string* m_pData = nullptr;

public:
	twitchEnums::ETag getTag(const std::string& rData);
	// getParameter();
	std::vector<std::string>* getParameters(const std::string& rData); //data must be full one signature
};

class TwitchParser
{
protected:
	std::string* m_pData = nullptr; //must me one full signature of IRC message TAG

public:
	virtual void parse() = 0;
};

class PrivateMessageParser : public TwitchParser
{
	twitchTags::PrivateMessage* m_pMsg = nullptr;

public:
	PrivateMessageParser(twitchTags::PrivateMessage& rMsg);
	void parse() override final;
};

class UserNoticeParser : public TwitchParser
{
	twitchTags::UserNotice* m_pMsg = nullptr;

public:
	UserNoticeParser(twitchTags::UserNotice& rMsg);
	void parse() override final;
};

class UserStateParser : public TwitchParser
{
	UserStateParser(twitchTags::UserState& rMsg);

	twitchTags::UserState* m_pMsg = nullptr;

public:
	void parse() override final;
};

class UnknownParser : public TwitchParser
{
	twitchTags::Unknown* m_pMsg = nullptr;
public:
	UnknownParser(twitchTags::Unknown& rMsg);
	void parse() override final;
};