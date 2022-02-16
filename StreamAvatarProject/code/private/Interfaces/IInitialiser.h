#pragma once

class IInitialiser
{
public:
	virtual ~IInitialiser() {};
	
	virtual bool init() = 0;
};