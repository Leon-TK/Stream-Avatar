#include "UParseManager.h"


UParseManager::UParseManager()
{
}

std::string UParseManager::constructAouthUrl()
{

	std::string url = std::string(DONATIONAUTH) + "?response_type=code&client_id=" + std::string(APPID)
					  + "&redirect_uri=" + std::string(DONATIONREDIRECT) + "&scope=" + std::string(DONATIONSCOPE) + "+" + std::string(DONATIONSCOPE2);

#ifdef G_DEBUGPARSERS
	std::cout << url;
	std::cout << std::endl;
#endif // G_DEBUGPARSERS

	return url;
}
std::string UParseManager::extractAccessCode(const std::string& rUrl)
{
	//std::string p1 =			"https://localhost"; //TODO: it was DONATIONREDIRECT
	std::string p2 =			DONATIONCODEURL;
	int index =				    rUrl.find(p2);
	std::string Code =			rUrl.substr(index + 7); //7 len of "?code=" //26 for test minus 'def' in code str

#ifdef G_DEBUGPARSERS
	std::cout << Code;
	std::cout << std::endl;
#endif // G_DEBUGPARSERS

	return Code;
}

std::string UParseManager::constructAccessCodeRequestBody()
{
	std::string str = "grant_type=authorization_code&client_id=" + std::string(APPID) + "&client_secret="+ std::string(USERCODE) + "&redirect_uri=" + std::string(DONATIONREDIRECT) + "&code=" + Variables::m_AccessCode;

#ifdef G_DEBUGPARSERS
	std::cout << str;
	std::cout << std::endl;
#endif // G_DEBUGPARSERS

	return str;
}

Poco::JSON::Object::Ptr UParseManager::constructAccessCodeRequestJson()
{
	std::string str1 = "{\"grant_type\" : \"authorization_code\", \"client_id\" : \"" + std::string(APPID) + std::string("\", "); 
	std::string str2 = "\"client_secret\" : \"" + std::string(APPCODE) + std::string("\", ");
	std::string str3 = "\"redirect_uri\" : \"" + std::string(DONATIONREDIRECT) + std::string("\", ");
	std::string str4 = "\"code\" : \"" + Variables::m_AccessCode + "\"}";
	std::string str = str1 + str2 + str3 + str4;

	Poco::JSON::Parser* parser =  new Poco::JSON::Parser(); //DELETE!!!
	Poco::Dynamic::Var var =	  parser->parse(str);
	parser->reset();

	Poco::JSON::Object::Ptr obj = var.extract<Poco::JSON::Object::Ptr>();


#ifdef G_DEBUGPARSERS
	std::cout << str;
	std::cout << std::endl;
#endif // G_DEBUGPARSERS
	delete parser;
	return obj;
}

Poco::JSON::Object::Ptr UParseManager::constructCentrifugoMessage(int type)
{
	Poco::JSON::Parser *parser = new Poco::JSON::Parser();
	std::string str = "";
	if (type == 1)
	{
		str = "{\"params\":{ \"token\":\"" + Variables::m_CentrifugoToken + std::string("\"}, \"id\":\"1\"}");
		std::cout << str;
	}

	if (type == 2)
	{
		str = "{\"channels\":[ \"$alerts:donation_" + Variables::m_UserID + std::string("\"], \"client\":\"") + Variables::m_CentrifugoID + std::string("\"}");
		std::cout << str;
	}

	if (type == 2)
	{
		str = "{\"params\":{ \"channel\":\""  + Variables::m_CentrifugoChannel +  std::string("\", \"token\":\"") + Variables::m_CentrifugoChannelToken + std::string("\"}, \"method\":\"1\", \"id\":\"2\"}");
		std::cout << str;
	}

	Poco::Dynamic::Var obj = parser->parse(str);
	Poco::JSON::Object::Ptr json = obj.extract< Poco::JSON::Object::Ptr>();
	delete parser;
	return json;
}


