#pragma once

#include <thread>

class IStreamService //Move this to other module
{
	virtual ~IStreamService() = default;
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual std::thread* getThread() = 0;
};