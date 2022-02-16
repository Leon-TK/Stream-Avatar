#pragma once

class ISubProgram
{
public:
	virtual ~ISubProgram() {};
	
	virtual void start() = 0;
	virtual void setup() = 0;
	virtual void stop() = 0;
};

