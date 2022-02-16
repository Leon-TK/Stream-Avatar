#pragma once

class IDonation
{
public:
	virtual ~IDonation() {};
	virtual int sendData() = 0;
};

