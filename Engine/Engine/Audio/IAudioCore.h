#pragma once

class IAudioCore
{
public:
	virtual ~IAudioCore() = default;
	
	virtual void setup() = 0;
	virtual void startStream() = 0;
	virtual void openStream() = 0;
	virtual void stopStream() = 0;
	virtual int8_t	getInputBuffer() = 0;
};

