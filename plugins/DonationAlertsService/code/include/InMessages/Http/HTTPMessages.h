#pragma once

#include "Incl.h"
#include "Variables.h"
#include "IProcessMessage.h"

class AccessTokenMessage : public IResponseMessage
{
public:
	AccessTokenMessage(const std::string& rMsg);
	bool process();
};

class CentrifugoChannelMessage : public IResponseMessage
{
public:
	CentrifugoChannelMessage(const std::string& rMsg);
	bool process();
};

class CentrifugoTokenMessage : public IResponseMessage
{
public:
	CentrifugoTokenMessage(const std::string& rMsg);
	bool process();
};

class UnknownMessage : public IResponseMessage
{
public:
	UnknownMessage(const std::string& rMsg);
	bool process();
};

class EmptyMessage : public IResponseMessage
{
public:
	EmptyMessage(const std::string& rMsg);
	bool process();
};