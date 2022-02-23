#pragma once

namespace twitchEnums
{

	enum class ETag
	{
		PRIVMSG,
		USERNOTICE,
		USERSTATE,
		UNKNOWN
	};

	enum class EParameter
	{
		unknown,
		badgeInfo,
		badges,
		bits,
		color,
		DName,
		emotes,
		emoteSets,
		id,
		message,
		mod,
		roomId,
		timestamp,
		userId,
		login,
		msgId,
		systemMsg,
		msgCumulativeMonths,
		msgDName,
		msgLogin,
		msgMonths,
		msgPromoGiftTotal,
		msgPromoName,
		msgRecipientDName,
		msgRecipientId,
		msgRecipientUserName,
		msgSenderLogin,
		msgSenderName,
		msgShouldShareStreak,
		msgStreakMonth,
		msgSubPlan,
		msgSubPlanName,
		msgViewerCount,
		msgRitualName,
		msgThreshold,
		msgGiftMonths
	};

	enum class EBadge
	{
		admin,
		bits,
		broadcaster,
		global_mod,
		moderator,
		subscriber,
		staff,
		turbo,
		unknown
	};

	enum class EMsgID
	{
		sub,
		resub,
		subgift,
		anonsubgift,
		submysterygift,
		giftpaidupgrade,
		rewardgift,
		anongiftpaidupgrade,
		raid,
		unraid,
		ritual,
		bitsbadgetier
	};

	enum class EMsgSubPlan
	{
		Prime,
		Tier1,
		Tier2,
		Tier3
	};

}