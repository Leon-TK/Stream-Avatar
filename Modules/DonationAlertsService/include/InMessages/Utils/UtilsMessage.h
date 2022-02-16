#pragma once

#include <array>
#include <vector>

#include "thirdparty/Poco/StreamCopier.h"

#include "Incl.h"
#include "InMessages.h"

class UtilsMessage
{
private:
	std::vector<DonateData>* m_pDonateData = nullptr;

public:
	UtilsMessage();
	void setDonateData(std::vector<DonateData>& rDonateData);
	IResponseMessage* getResponseMessage(const std::string& rMsg);
	//IWebSocketMessage* GetWsMessage(std::string msg);
	std::vector<IWebSocketMessage*> getWsMessages(const std::string& rMsg);
	int checkDataForMultiplyMessages(const std::string& rData, std::vector<int>& rOutIndexes);
	void getDonateMsgArray(int count, const std::vector<int>& rIndexes, const std::string& rData);
};

