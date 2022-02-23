#include "EventManager.h"
#include "AnimationManager.h"

Base::EventManager::EventManager()
{
}

Base::EventManager::EventManager(AnimationManager& rAm): am(rAm)
{
}

void Base::EventManager::Notify(const Message& rMsg)
{
	m_pAm->ProcessEvent(rMsg);
}

void Base::EventManager::setAnimManager(AnimationManager& rAm)
{
	this->m_pAm = rAm;
}

Base::AnimationManager* Base::EventManager::getAnimManager()
{
	return m_pAm;
}
