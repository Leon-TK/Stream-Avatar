#pragma once

#include <vector>
#include <string>

#define G_ByteConverter_TEST

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

#ifndef G_ByteConverter_TEST
	std::vector<uint8_t>* convertu(const std::wstring& rData);

	std::vector<uint8_t>* convertu(const std::string& rData);
#endif // !G_ByteConverter_TEST

	std::vector<wchar_t>* convertw(const std::wstring& rData);

	std::vector<wchar_t>* convertw(const std::string& rData);
};  


