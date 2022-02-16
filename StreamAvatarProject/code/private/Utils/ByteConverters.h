#pragma once

#include <vector>
//#include <string>
#include <string>

#define ByteConverter_TEST

class IByteConverter
{	
};

class ByteConverter
{
protected:
	std::vector<char>* m_buffer;

public:
	
	std::vector<char>* convert(const std::wstring& rData);
	std::vector<char>* convert(const std::string& rData);

#ifndef ByteConverter_TEST
	std::vector<uint8_t>* convertu(const std::wstring& rData);

	std::vector<uint8_t>* convertu(const std::string& rData);
#endif // !ByteConverter_TEST

	std::vector<wchar_t>* convertw(const std::wstring& rData);

	std::vector<wchar_t>* convertw(const std::string& rData);
};  


