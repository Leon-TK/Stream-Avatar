#pragma once

//#include <iostream>
//#include <cstdlib>
//#include <cstring>
//#include <stdio.h>
//#include <cmath>
//#include <algorithm> 
//#include <mutex>
//#include <array>

//#include "RtAudio.h"
//#include "IAudioApi.h"
#include "RTAudioApi.h"
//#include "RtAudio.h"
//#include "IAudioApi.h"
#include "RTAudioApi.h"

class IAudioApi;

namespace AudioApi
{

	class AudioApiManager
	{
	private:
		RtAudioApi::RTAudioApi	m_RtApiObj; //choose api
		IAudioApi* m_pApi = nullptr;   //interface for coosen api

		unsigned int const  m_channels = 1 /*channel 1 microphone jacked in*/,
							m_fs = 48000 /*frequency is setted as broadcast requaers*/,
							m_device = 1 /*device is Focusrite(you can check device's id by calling rt api function)*/, 
							m_bufferFrames = 512; //
	public:
		AudioApiManager ();
		~AudioApiManager ();

		void setupData();
		void startStream();
		void openStream();
		void stopStream();

		uint8_t* getInputBuffer();
	};


}