#pragma once
#include <map>
#include "boost/any.hpp"
#include <string>
#include <unordered_map>
#include <afxwin.h>
#include "CStorageMacro.h"

using namespace std;
using namespace boost;

class CStorageAPI CStorage{
public:
	string strCurrentKey;
	unordered_map<string,any> mapData;

	CStorage& operator[](CString key);
	CStorage operator=(any anyValue);

	template<typename T>
	T toValue();
};