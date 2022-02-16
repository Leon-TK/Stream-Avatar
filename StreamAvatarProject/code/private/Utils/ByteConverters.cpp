#include "ByteConverters.h"

std::vector<char>* ByteConverter::convert(const std::wstring& rData)
{
	char const* p = reinterpret_cast<char const*>(&rData[0]);
	std::size_t size = rData->size() * sizeof(rData->front());
	buffer = new std::vector<char>(p, p + size);

	return buffer;
}

std::vector<char>* ByteConverter::convert(const std::string& rData)
{
	//std::string str = "asdasdasdasd";
	buffer = new std::vector<char>(rData->begin(), rData->end());
	//buffer->assign(*rData->begin(), *rData->end());
	buffer->shrink_to_fit();
	return buffer;
}
#ifndef  G_ByteConverter_TEST



std::vector<uint8_t>* ByteConverter::convertu(const std::wstring& rData)
{
//#ifdef asda
	//std::string str = "asdasdasdasd";
	std::vector<uint8_t>* buffer = new std::vector<uint8_t>(rData->begin(), rData->end());
	//buffer->assign(*rData->begin(), *rData->end());
	buffer->shrink_to_fit();
	return buffer;
//#endif
}

std::vector<uint8_t>* ByteConverter::convertu(const std::string& rData)
{
//#ifdef asda
	//std::string str = "asdasdasdasd";
	std::vector<uint8_t> * buffer = new std::vector<uint8_t>(rData->begin(), rData->end());
	//buffer->assign(*rData->begin(), *rData->end());
	buffer->shrink_to_fit();
	return buffer;
//#endif

}
#endif // ! G_ByteConverter_TEST
std::vector<wchar_t>* ByteConverter::convertw(const std::wstring& rData)
{
	//std::string str = "asdasdasdasd";
	std::vector<wchar_t> * buffer = new std::vector<wchar_t>(rData->begin(), rData->end());
	//buffer->assign(*rData->begin(), *rData->end());
	buffer->shrink_to_fit();
	return buffer;
}

std::vector<wchar_t>* ByteConverter::convertw(const std::string& rData)
{
	std::wstring widestr = std::wstring(rData->begin(), rData->end());
	//std::string str = "asdasdasdasd";
	std::vector<wchar_t> * buffer = new std::vector<wchar_t>(widestr.begin(), widestr.end());
	//buffer->assign(*rData->begin(), *rData->end());
	buffer->shrink_to_fit();
	return buffer;
}
