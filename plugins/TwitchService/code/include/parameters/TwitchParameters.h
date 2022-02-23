#pragma once
#include <string>
#include <vector>
#include "TwitchEnums.h"

typedef std::string s;

namespace twitchParams
{
	
	//badges
	class badge
	{
	public:
		twitchEnums::EBadge badge;
		s value; //int
	};

	class unknown
	{
	public:
		s field; 
		s value; 
	};

	class badgeInfo
	{
	public:
		s field; //str -subscriber
		s value; //int
	};

	class badges //There are many valid badge values; e.g., admin, bits, broadcaster, global_mod, moderator, subscriber, staff, turbo.
	{
	public:
		std::vector<badge> badges;
	};

	class bits //Sent only for Bits messages.
	{
	public:
		s value; //TODO:
	};

	class color //Hexadecimal RGB color 
	{
	public:
		s value; //#004032
	};

	class DName
	{
	public:
		s value; //str
	};

	class emotes
	{
	public:
		s value; //TODO:
	};

	class emoteSets
	{
	public:
		s value; //TODO:
	};

	class id
	{
	public:
		s value; //str
	};

	class message
	{
	public:
		s value; //str
	};

	class mod // 1 or 0
	{
	public:
		s value; //int
	};

	class roomId
	{
	public:
		s value; //str
	};

	class timestamp
	{
	public:
		s value; //str time
	};

	class userId
	{
	public:
		s value; //str
	};

	class login
	{
	public:
		s value; //str
	};

	class msgId //Valid values: sub, resub, subgift, anonsubgift, submysterygift, giftpaidupgrade, rewardgift, anongiftpaidupgrade, raid, unraid, ritual, bitsbadgetier.
	{
	public:
		twitchEnums::EMsgID msgId;
	};

	class systemMsg
	{
	public:
		s value; //str
	};

	//msg-param fields 
	class msgCumulativeMonths //Sent only on sub, resub
	{
	public:
		s value; //int
	};

	class msgDName //Sent only on raid
	{
	public:
		s value; //str
	};

	class msgLogin //Sent on only raid
	{
	public:
		s value; //str
	};

	class msgMonths //Sent only on subgift, anonsubgift
	{
	public:
		s value; //int
	};

	class msgPromoGiftTotal //Sent only on anongiftpaidupgrade, giftpaidupgrade
	{
	public:
		s value; //int
	};

	class msgPromoName //Sent only on anongiftpaidupgrade, giftpaidupgrade
	{
	public:
		s value; //str
	};

	class msgRecipientDName //Sent only on subgift, anonsubgift
	{
	public:
		s value; //str
	};

	class msgRecipientId //Sent only on subgift, anonsubgift
	{
	public:
		s value; //str
	};

	class msgRecipientUserName //Sent only on subgift, anonsubgift
	{
	public:
		s value; //str
	};

	class msgSenderLogin //Sent only on giftpaidupgrade
	{
	public:
		s value; //str
	}; 

	class msgSenderName //Sent only on giftpaidupgrade
	{
	public:
		s value; //str
	};

	class msgShouldShareStreak //Sent only on sub, resub
	{
	public:
		s value; //bool
	};

	class msgStreakMonth //Sent only on sub, resub
	{
	public:
		s value; //int
	};

	class msgSubPlan //(Sent only on sub, resub, subgift, anonsubgift)
	{
	public:
		twitchEnums::EMsgSubPlan subPlan; //str  Prime, 1000, 2000, 3000.
	};

	class msgSubPlanName //Sent only on sub, resub, subgift, anonsubgift
	{
	public:
		s value; //str
	};

	class msgViewerCount //Sent only on raid
	{
	public:
		s value; //int
	};

	class msgRitualName //Sent only on ritual
	{
	public:
		s value; //str
	};

	class msgThreshold //Sent only on bitsbadgetier
	{
	public:
		s value; //int
	};

	class msgGiftMonths //Sent only on subgift, anonsubgift
	{
	public:
		s value; //int
	};

}
