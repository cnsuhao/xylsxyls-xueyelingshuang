#pragma once
#include <afxwin.h>
#include <map>
using namespace std;
#include "CValue.h"
#include "CMysqlMacro.h"

class CMysqlAPI CUpdate{
public:
public:
	//一条记录中字段名对应字段值
	map<CString,CValue> mapValue;
	CString strCurrentField;

public:
	CUpdate();
	CUpdate(const CUpdate& upd);
	CUpdate operator=(const CUpdate& upd);
public:
	CUpdate operator=(const CValue& value);
	CUpdate& operator[](CString Field);
	
public:
	CString toCString();
};