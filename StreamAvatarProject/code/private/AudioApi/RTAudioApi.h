#pragma once

#include "IAudioApi.h"
#include "RtAudio.h"

namespace RtAudioApi
{

	struct InputData
	{
	public:
		uint8_t	inputBuffer[512]; // buffer size
		unsigned int* const pBufferFrames = nullptr;     // ptr to RTManager's member
	};

	class RTAudioApi final: public IAudioApi
	{
	private:
		RtAudio					  m_adc;   //rt instance
		RtAudio::StreamParameters m_params;
		InputData*				  m_pData = nullptr;  //data for callback function

		unsigned int	m_channels = 1 /*channel 1 microphone jacked in*/, 
						m_fs = 48000 /*frequency is setted as broadcast requaers*/, 
						m_device = 1 /*device is Focusrite(you can check device's id by calling rt api function)*/,
						m_bufferFrames = 512; //its not const because openStream() not allow it

	public:
		RTAudioApi(uint32_t device, uint32_t channels, uint32_t fs, uint32_t bufsize);
		~RTAudioApi();

		void setup() override final;
		void startStream() override final;
		void openStream() override final;
		void stopStream() override final;

		uint8_t* getInputBuffer() override final;

};


}