#include "AudioApiManager.h"
#include "IAudioApi.h"

void AudioApi::AudioApiManager::setupData()
{
	Api->Setup();
}

void AudioApi::AudioApiManager::startStream()
{
	Api->StartStream();
}


AudioApi::AudioApiManager::AudioApiManager() : RtApiObj(device, channels, fs, bufferFrames)
{
	Api = &RtApiObj;
	SetupData();
}

AudioApi::AudioApiManager::~AudioApiManager()
{
}

void AudioApi::AudioApiManager::openStream()
{
	Api->OpenStream();
}

void AudioApi::AudioApiManager::stopStream()
{
	Api->StopStream();
}

__int8 * AudioApi::AudioApiManager::getInputBuffer()
{
	return Api->GetInputBuffer();
}
