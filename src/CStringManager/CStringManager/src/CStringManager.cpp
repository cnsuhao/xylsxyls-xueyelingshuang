#include "CStringManager.h"
#include <stdarg.h>
#include <algorithm>

int CStringManager::FindOther(const std::string& str, char cLeft, char cRight, int nSelect){
	std::vector<int> vecn;
	int nSelectSize = 0;
	int n = 0;
	while (str[n]){
		if (str[n] == cLeft){
			vecn.push_back(n);
			//?nSelect在左，记下现在的nSelectSize
			if(nSelect == n) nSelectSize = (int)vecn.size();
		}
		if (str[n] == cRight){
			if(nSelect == n){
				if(vecn.size() > 0) return vecn.at(vecn.size() - 1);
				else return -1;
			}
			//?如果弹出之前发现size大小等于之前记录的，说明找到了对应的右侧
			if(vecn.size() == nSelectSize && nSelectSize > 0){
				return n;
			}
			if(vecn.size() > 0) vecn.pop_back();
		}
		n++;
	}
	return -1;
}

std::vector<std::string> CStringManager::split(std::string splitString, std::string separate_character){
	std::vector<std::string> strs;
	//?分割字符串的长度,这样就可以支持如“,,”多字符串的分隔符
	int separate_characterLen = (int)separate_character.length();
	int lastPosition = 0,index = -1;
	while (-1 != (index = (int)splitString.find(separate_character, lastPosition))){
		strs.push_back(splitString.substr(lastPosition, index - lastPosition).c_str());
		lastPosition = index + separate_characterLen;   
	}
	//?截取最后一个分隔符后的内容
	std::string lastString = splitString.substr(lastPosition);
	//?if (!lastString.empty()) //如果最后一个分隔符后还有内容就入队
	strs.push_back(lastString.c_str());
	return strs;
}

std::vector<std::wstring> CStringManager::split(std::wstring splitString, std::wstring separate_character)
{
    std::vector<std::wstring> strs;
	//?分割字符串的长度,这样就可以支持如“,,”多字符串的分隔符
	int separate_characterLen = separate_character.length();
	int lastPosition = 0, index = -1;
	while (-1 != (index = splitString.find(separate_character, lastPosition)))
	{
		strs.push_back(splitString.substr(lastPosition, index - lastPosition).c_str());
		lastPosition = index + separate_characterLen;
	}
	//?截取最后一个分隔符后的内容
    std::wstring lastString = splitString.substr(lastPosition);
	//?if (!lastString.empty()) //如果最后一个分隔符后还有内容就入队
	strs.push_back(lastString.c_str());
	return strs;
}

void CStringManager::ReplaceAll(std::string& str, const std::string& old_value, const std::string& new_value){
	while(true){
		std::string::size_type pos(0);
		if ((pos = str.find(old_value)) != std::string::npos) str.replace(pos, old_value.length(), new_value);
		else break;
	}
}

std::string CStringManager::Mid(const std::string & str, size_t offset, size_t count)
{
	return str.substr(offset, count);
}

std::string CStringManager::Left(const std::string & str, size_t count)
{
	return Mid(str, 0, count);
}

std::string CStringManager::Right(const std::string & str, size_t count)
{
	return Mid(str, str.size() - count, count);
}

size_t CStringManager::Find(const std::string & str, const std::string & right, size_t offset)
{
	return str.find(right, offset);
}

size_t CStringManager::Find(const std::string & str, char ch, size_t offset)
{
	return str.find(ch, offset);
}

size_t CStringManager::ReserveFind(const std::string & str, const std::string & right)
{
	return str.rfind(right);
}

size_t CStringManager::ReserveFind(const std::string & str, char ch)
{
	return str.rfind(ch);
}

size_t CStringManager::GetLength(const std::string & str)
{
	return str.length();
}

size_t CStringManager::Delete(std::string & str, size_t offset, size_t count)
{
	return str.erase(offset, count).length();
}

size_t CStringManager::Insert(std::string & str, size_t offset, const std::string & right)
{
	return str.insert(offset, right).length();
}

size_t CStringManager::Insert(std::string & str, size_t offset, char ch)
{
	return str.insert(offset, &ch, 1).length();
}

size_t CStringManager::Replace(std::string & str, const std::string & oldstr, const std::string & newstr)
{
	size_t count = 0;
	size_t pos = 0;
	while (true)
	{
		pos = str.find(oldstr, pos);
		if (pos != std::string::npos)
		{
			str.replace(pos, oldstr.length(), newstr);
			pos += newstr.length();
			++count;
		}
		else
			break;
	}
	return count;
}

std::string CStringManager::Replace(const char * str, const std::string & oldstr, const std::string & newstr)
{
	if (str == nullptr)
	{
		return std::string();
	}
	std::string result = str;
	Replace(result, oldstr, newstr);
	return result;
}

size_t CStringManager::Replace(std::wstring & str, const std::wstring & oldstr, const std::wstring & newstr)
{
	size_t count = 0;
	size_t pos = 0;
	while (true)
	{
		pos = str.find(oldstr, pos);
		if (pos != std::wstring::npos)
		{
			str.replace(pos, oldstr.length(), newstr);
			pos += newstr.length();
			++count;
		}
		else
			break;
	}
	return count;
}

size_t CStringManager::Replace(std::string & str, char ch1, char ch2)
{
	size_t count = 0;
	for (size_t pos = 0; pos != str.size(); ++pos)
	{
		if (str[pos] == ch1)
		{
			str[pos] = ch2;
			++count;
		}
	}
	return count;
}

void CStringManager::Format(std::string & str, const char * fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	int size = _vscprintf(fmt, args);
	//?resize分配后string类会自动在最后分配\0，resize(5)则总长6
	str.resize(size);
	if (size != 0)
	{
		//?即便分配了足够内存，长度必须加1，否则会崩溃
		vsprintf_s(&str[0], size + 1, fmt, args);
	}
	va_end(args);
}

std::string CStringManager::Format(const char * fmt, ...){
	std::string result;
    va_list args;
    va_start(args, fmt);
    int size = _vscprintf(fmt, args);
    //?resize分配后string类会自动在最后分配\0，resize(5)则总长6
    result.resize(size);
	if (size != 0)
	{
		//?即便分配了足够内存，长度必须加1，否则会崩溃
		vsprintf_s(&result[0], size + 1, fmt, args);
	}
    va_end(args);
    return result;
}

void CStringManager::Format(std::wstring& str, const wchar_t * fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	int size = _vscwprintf(fmt, args);
	//?resize分配后string类会自动在最后分配\0，resize(5)则总长6
	str.resize(size);
	if (size != 0)
	{
		//?即便分配了足够内存，长度必须加1，否则会崩溃
		vswprintf_s(&str[0], size + 1, fmt, args);
	}
	va_end(args);
}

std::wstring CStringManager::Format(const wchar_t * fmt, ...)
{
	std::wstring result;
	va_list args;
	va_start(args, fmt);
	int size = _vscwprintf(fmt, args);
	//?resize分配后string类会自动在最后分配\0，resize(5)则总长6
	result.resize(size);
	if (size != 0)
	{
		//?即便分配了足够内存，长度必须加1，否则会崩溃
		vswprintf_s(&result[0], size + 1, fmt, args);
	}
	va_end(args);
	return result;
}

void CStringManager::MakeReverse(std::string & str)
{
	std::reverse(str.begin(),str.end());
}

std::string CStringManager::MakeUpper(const std::string& src)
{
	std::string dst;
	//如果dst是有值的话则第三个参数传dst.begin()，从头开始覆盖
	std::transform(src.begin(), src.end(), std::back_inserter(dst), ::toupper);
	return dst;
}

std::string CStringManager::MakeLower(const std::string& src)
{
	std::string dst;
	std::transform(src.begin(), src.end(), std::back_inserter(dst), ::tolower);
	return dst;
}

std::wstring CStringManager::MakeUpper(const std::wstring& src)
{
	std::wstring dst;
	std::transform(src.begin(), src.end(), std::back_inserter(dst), ::toupper);
	return dst;
}

std::wstring CStringManager::MakeLower(const std::wstring& src)
{
	std::wstring dst;
	std::transform(src.begin(), src.end(), std::back_inserter(dst), ::tolower);
	return dst;
}

std::string CStringManager::GetMidString(const std::string& src, const std::string& leftString, const std::string& rightString)
{
	int left = (int)src.find(leftString);
	int right = (int)src.find(rightString);
	return Mid(src, left + 1, right - left - 1);
}