#pragma once

#include <vector>
#include <mutex>

#include "Incl.h"
#include "Variables.h"
#include "IWebSocketMessage.h"
#include "DonateData.h"

using std::string;
using std::cout;
using std::istream;
using std::ostream;

namespace WsMessages
{

	class DonateMessage : public IWebSocketMessage
	{
	private:
		std::mutex m_mtx;
		std::vector<DonateData>* m_pDonateData = nullptr;

	public:
		DonateMessage(const std::string& rMsg, const std::vector<DonateData>& rDonateData);
		void process();
		DonateData parseData(const std::string& rData);
	};

	class PingMessage : public IWebSocketMessage
	{
	public:
		PingMessage();
		void process();
	};

	class CentrifugoIDMessage : public IWebSocketMessage
	{
	public:
		CentrifugoIDMessage(const std::string& rMsg);
		void process();
	};

	class UnknownMessageWs : public IWebSocketMessage
	{
	public:
		UnknownMessageWs(const std::string& rMsg);
		void process();
	};

	class EmptyMessageWs : public IWebSocketMessage
	{
	public:
		EmptyMessageWs();
		void process();
	};


}