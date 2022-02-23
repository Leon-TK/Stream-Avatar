#pragma once

#include "TwitchTagBase.h"
#include "TwitchParameters.h"

namespace twitchTags
{
	using namespace twitchParams;

	struct PrivateMessage
	{
		badgeInfo	badgeInfo;
		badges		badges;
		bits		bits;
		color		color;
		DName		dname;
		emotes		emotes;
		id			id;
		message		message;
		mod			mod;
		roomId		roomId;
		timestamp	timestamp;
		userId		userId;
		std::vector<unknown> unknown;
	};

	struct UserNotice
	{
		badgeInfo	badgeInfo;
		badges		badges;
		color		color;
		DName		dname;
		emotes		emotes;
		id			id;
		login		login;
		message		message;
		mod			mod;
		msgId		msgId;
		roomId		roomId;
		systemMsg	systemMsg;
		timestamp	timestamp;
		userId		userId;
		std::vector<unknown> unknown;
	};

	struct UserState
	{
		badgeInfo	badgeInfo;
		badges		badges;
		color		color;
		DName		dname;
		emoteSets	emoteSets;
		mod			mod;
		roomId		roomId;
		timestamp	timestamp;
		userId		userId;
		std::vector<unknown> unknown;
	};
	
	struct Unknown
	{
		std::vector<unknown> unknown;
	};

}