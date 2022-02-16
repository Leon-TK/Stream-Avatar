#include "ByteConverters.h"

std::vector<char>* ByteConverter::convert(const std::wstring& rData)
{
	char const* p = reinterpret_cast<char const*>(&rData[0]);
	std::size_t size = rData.size() * sizeof(rData.front());
	m_buffer = new std::vector<char>(p, p + size);

	return m_buffer;
}

std::vector<char>* ByteConverter::convert(const std::string& rData)
{
	//std::string str = "asdasdasdasd";
	m_buffer = new std::vector<char>(rData.begin(), rData.end());
	//m_buffer->assign(*rData.begin(), *rData.end());
	m_buffer->shrink_to_fit();
	return m_buffer;
}
#ifndef  G_ByteConverter_TEST



std::vector<uint8_t>* ByteConverter::convertu(const std::wstring& rData)
{
//#ifdef asda
	//std::string str = "asdasdasdasd";
	std::vector<uint8_t>* m_buffer = new std::vector<uint8_t>(rData.begin(), rData.end());
	//m_buffer->assign(*rData.begin(), *rData.end());
	m_buffer->shrink_to_fit();
	return m_buffer;
//#endif
}

std::vector<uint8_t>* ByteConverter::convertu(const std::string& rData)
{
//#ifdef asda
	//std::string str = "asdasdasdasd";
	std::vector<uint8_t> * m_buffer = new std::vector<uint8_t>(rData.begin(), rData.end());
	//m_buffer->assign(*rData.begin(), *rData.end());
	m_buffer->shrink_to_fit();
	return m_buffer;
//#endif

}
#endif // ! G_ByteConverter_TEST
std::vector<wchar_t>* ByteConverter::convertw(const std::wstring& rData)
{
	//std::string str = "asdasdasdasd";
	std::vector<wchar_t> * m_buffer = new std::vector<wchar_t>(rData.begin(), rData.end());
	//m_buffer->assign(*rData.begin(), *rData.end());
	m_buffer->shrink_to_fit();
	return m_buffer;
}

std::vector<wchar_t>* ByteConverter::convertw(const std::string& rData)
{
	std::wstring widestr = std::wstring(rData.begin(), rData.end());
	//std::string str = "asdasdasdasd";
	std::vector<wchar_t> * m_buffer = new std::vector<wchar_t>(widestr.begin(), widestr.end());
	//m_buffer->assign(*rData.begin(), *rData.end());
	m_buffer->shrink_to_fit();
	return m_buffer;
}
