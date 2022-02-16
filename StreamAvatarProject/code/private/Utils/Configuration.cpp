#include "Configuration.h"

Configuration::Configuration()
{
	pConf = new PropertyFileConfiguration();
}

void Configuration::loadConfigFile(const std::string& rPath)
{
	this->configPath = rPath;
	pConf->load(path);
}

unsigned int Configuration::getInt(const std::string& rKey)
{
	return pConf->getUInt(rKey);
}

bool Configuration::getBool(const std::string& rKey)
{
	return pConf->getBool(rKey);
}

std::string Configuration::getString(const std::string& rKey)
{
	return pConf->getString(rKey);
}

bool Configuration::hasKey(const std::string& rKey)
{
	return pConf->hasProperty(rKey);
}

std::vector<std::string> Configuration::getKeys()
{
	Poco::Util::AbstractConfiguration::Keys keys;
	pConf->keys(keys);
	return keys;
}
