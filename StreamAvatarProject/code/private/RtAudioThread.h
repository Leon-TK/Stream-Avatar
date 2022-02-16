#pragma once

#include "AudioApiManager.h"

class RtAudioThread
{
private:
	AudioApi::AudioApiManager m_rt;
    
public:
	RtAudioThread() = default;
	RtAudioThread(const RtAudioThread&) = delete;
	RtAudioThread& operator=(const RtAudioThread&) = delete;
	
	void setUp();
	void start();
	AudioApi::AudioApiManager* getRtManager();
};