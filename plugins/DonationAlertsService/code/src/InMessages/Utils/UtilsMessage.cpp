#include "UtilsMessage.h"

UtilsMessage::UtilsMessage()
{
}

void UtilsMessage::setDonateData(const std::vector<DonateData>& rDonateData)
{
	this->donateData = donateData;
}

IResponseMessage* UtilsMessage::getResponseMessage(const std::string& rMsg)
{

	//Requset messages
	if (rMsg.find("access_token") != -1 && rMsg.find("token_type") != -1)
	{
		return new AccessTokenMessage(rMsg);
	}
	if (rMsg.find("socket_connection_token") != -1)
	{
	
		return new CentrifugoTokenMessage(rMsg);
	}
	if (rMsg.find("$alerts:donation") != -1 && rMsg.find("token") != -1)
	{
	
		return new CentrifugoChannelMessage(rMsg);
	}
	

	if (!rMsg.empty())
	{
		
		return new UnknownMessage(rMsg);
	}
	else
	{
	
		return new EmptyMessage("");
	}
	
}

std::vector<IWebSocketMessage*> UtilsMessage::getWsMessages(const std::string& rMsg)
{
	if (rMsg.find("\"shown_at\"") != -1 && rMsg.find("\"currency\"") != -1)
	{
		std::vector<int> indexes;
		int counter = CheckDataForMultiplyMessages(&rMsg, &indexes);

		if (counter > 1)
		{
			std::cout << "count of donate msgs: " << counter;
			std::cout << std::endl;
			GetDonateMsgArray(counter, indexes, &rMsg);
			std::vector<IWebSocketMessage*> msgs;
			msgs.push_back(new WsMessages::UnknownMessageWs(rMsg));
			return msgs;
		}
		std::vector<IWebSocketMessage*> msgs;
		msgs.push_back(new WsMessages::DonateMessage(rMsg, this->donateData));
		return msgs;
	}

	if (rMsg.find("\"client\":") != -1 && rMsg.find("\"version\":") != -1)
	{
		std::vector<IWebSocketMessage*> msgs;
		msgs.push_back(new WsMessages::CentrifugoIDMessage(rMsg));
		return msgs;
	}
	if (rMsg.find("ping") != -1 && rMsg.length() < 6)
	{
		std::vector<IWebSocketMessage*> msgs;
		msgs.push_back(new WsMessages::PingMessage());
		return msgs;
	}
	else
	{
		std::vector<IWebSocketMessage*> msgs;
		msgs.push_back(new WsMessages::UnknownMessageWs(rMsg));
		return msgs;
	}
	std::vector<IWebSocketMessage*> msgs;
	return msgs;
}

int UtilsMessage::checkDataForMultiplyMessages(const std::string& rData, std::vector<int>& rOutIndexes)
{
	int counter = 0;
	int i = 0;
	int offset = 15;
	while (i != -1)
	{
		i = data->find("\"shown_at\"", i + offset);
		if (i != -1)
		{
			++counter;
			outIndexes->push_back(i);
		}
	}

	return counter;
}

void UtilsMessage::getDonateMsgArray(int count, const std::vector<int>& rIndexes, const std::string& rData)
{
	std::cout << "We have recieved multiply donate messages, data is: "; //TODO: asdsa
	std::cout << std::endl;
}



