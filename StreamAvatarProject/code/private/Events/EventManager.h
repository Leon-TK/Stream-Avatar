#pragma once

//#include "AnimationManager.h"

namespace Base
{
	class AnimationManager;

	enum class EMessage
	{
		Donation,
		Subscribe,
		Bits
	};

	struct Message
	{
		EMessage type;
		float    value;
	};

	class EventManager
	{
	private:
		AnimationManager* m_pAm = nullptr;

	public:
		EventManager();
		EventManager(AnimationManager& rAm);

		void notify(const Message& msg);

		void setAnimManager(AnimationManager& rAm);
		
		AnimationManager* getAnimManager();
	};

}