#pragma once

#include "thirdparty/Poco/Util/PropertyFileConfiguration.h"

using Poco::AutoPtr; 
using Poco::Util::PropertyFileConfiguration;

class Configuration
{
private:
	std::string m_configPath;
	AutoPtr<PropertyFileConfiguration> m_pConf;
	
public:
	Configuration();

	void loadConfigFile(const std::string& rPath);
	unsigned int getInt(const std::string& rKey);
	bool getBool(const std::string& rKey);
	std::string getString(const std::string& rKey);
	bool hasKey(const std::string& rKey);
	std::vector<std::string> getKeys();
};

