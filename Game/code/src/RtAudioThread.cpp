#pragma once

#include "AudioApiManager.h"
#include "RtAudioThread.h"

void RtAudioThread::setUp()
{
}

AudioApi::AudioApiManager * RtAudioThread::getRtManager()
{
	return &m_rt;
}