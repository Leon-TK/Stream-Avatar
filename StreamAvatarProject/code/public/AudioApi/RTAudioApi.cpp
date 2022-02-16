#include <mutex>

#include "RTAudioApi.h"

using namespace RtAudioApi;

int record(void *outputBuffer, void *inputBuffer, unsigned int nFrames, double streamTime, RtAudioStreamStatus status, void *userData)
{
	//Note: Arithmetic mean gains bass

	//Try to send inputbuffer to user data
	//Then calculate MAX in animation class
	std::mutex mutex; //TODO: must be global

	//Cast
	InputData *Data = (InputData *)userData;
	__int8* input = (__int8 *)inputBuffer;

	if (status)
	{
		std::cout << "Stream underflow detected!" << std::endl;
	}

	//Fill array
	mutex.lock();
	for (unsigned int i = 0; i < nFrames; ++i) {

		Data->inputBuffer[i] = *++input;
	}
	mutex.unlock();
	///*
	//Max
	//try to send inputBuffer not bufferarray

	//*/

	/*
	//Arithmetic mean
	// Add all frames with absolute value
	for (i = 0; i < nFrames; ++i) {

			sum = sum + std::abs(*++input);
	}

	//Calculate arithmetic mean
	mutex.lock();
	iData->level = sum / nFrames;
	mutex.unlock();
	*/

	return 0;
}

RTAudioApi::RTAudioApi(unsigned int device, unsigned int channels, unsigned int fs, unsigned int bufsize)
{
	this->device = device;
	this->channels = channels;
	this->fs = fs;
	this->bufferFrames = bufsize;
}

RTAudioApi::~RTAudioApi()
{
	delete data;
}

void RTAudioApi::setup()
{
	data = new InputData(&this->bufferFrames);
	adc.showWarnings(true);
	Params.deviceId = device;
	Params.nChannels = channels;
}

void RTAudioApi::startStream()
{
	try {
		adc.startStream();
	}
	catch (RtAudioError& e) {
		std::cout << '\n' << e.getMessage() << '\n' << std::endl;
		if (adc.isStreamOpen()) adc.closeStream();
	}
}

void RTAudioApi::openStream()
{
	try {
		adc.openStream(nullptr, &Params, RTAUDIO_SINT8, fs, &bufferFrames, &record, (void *)data);
	}
	catch (RtAudioError& e) {
		std::cout << '\n' << e.getMessage() << '\n' << std::endl;
		if (adc.isStreamOpen()) adc.closeStream();
	}
}

void RTAudioApi::stopStream()
{
	try {
		// Stop the stream
		adc.stopStream();
	}
	catch (RtAudioError& e) {
		e.printMessage();
	}
	if (adc.isStreamOpen()) adc.closeStream();
}

__int8 * RTAudioApi::getInputBuffer()
{
	return data->inputBuffer;
}

InputData::InputData(unsigned int bufferFrames) : bufferFrames(bufferFrames)
{
}