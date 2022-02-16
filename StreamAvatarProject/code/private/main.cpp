#pragma once

//#define TEST

#ifndef TEST
	#include <thread>
	#include <SFML/Graphics.hpp>

	#include "DonateAlertsApi.h"
	#include "GraphManager.h"
	#include "CallManager.h"
	#include "EventManager.h"
	#include "AnimationManager.h"
	#include "Timer.h"
	#include "CameraAnimation.h"
	#include "MouthAnimations.h"
	#include "BodyAnimations.h"
	#include "AudioApiManager.h"

	//sleep routines.
	#define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds ) 

	GraphicThread gth;
	DaApiThread dath;
	RtAudioThread rtath;
#endif // !TEST

#ifdef TEST
	//#include <stdio.h>
	//#include<windows.h>

	#include "AWebSocketManager.h"
	#include "TwitchSocketManager.h"
	#include "TwitchApi.h"
	#include "IApi.h"
	
	//#include "fcntl.h"
	//#include "io.h"
	//#include "Program.h"

	TwitchApi ta;
	IApi * twapi;
	//Program pr;
#endif // TEST

int main()
{
#ifndef TEST
	//Setup
	gth.setUp();
	//dath.setUp();
	//std::thread* recieveThread = dath.getApi()->getThread();
	//rtath.setUp();
	//rtath.GetRtManager()->openStream();
	//rtath.GetRtManager()->startStream(); // i think it runs on another thread
	//gth.GetGraphManager()->getAnimationManager()->SetRT(rtath.GetRtManager());
	//gth.GetGraphManager()->getAnimationManager()->SetIdleAnimation();
	gth.update();
	//threads
	//std::thread th1 = dath.getApi()->getThread();
	//std::thread th2 = gth.getThread();
	//th1.detach();
	//th2.detach();
	//recieveThread->detach();

	//TODO: Check if we need while loop here

	std::cout << "\nWorking ... press <enter> to quit.\n";
	std::system("pause");

	//dath.getApi()->stopRecieveData();
	//rtath.getRtManager()->stopStream();
	
	return 0;

#endif // !TEST
#ifdef TEST
	//_setmode(_fileno(stdout), _O_U16TEXT);
	twapi = &ta;
	twapi->start();
	//pr.loadConfig("config/config.txt");
	//pr.setup();
	return 0;
#endif // TEST
}

