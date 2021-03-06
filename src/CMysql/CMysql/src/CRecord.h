#pragma once
#include <afxwin.h>
#include <list>
#include <map>
using namespace std;
#include "CValue.h"
#include "CMysqlMacro.h"

class CTable;
class CMysqlAPI CRecord{
public:
	//不使用table中定义字段名的模式，因为无法添加新字段
	map<CString,CValue> mapValue;
	//存储修改的字段名，在Add执行之后清空
	list<CString> listReviseAttri;

	CString strCurrentField;
	CTable* pTable;
public:
	CRecord(CTable* pTable);
	CRecord(const CRecord& record);
	CRecord operator=(const CRecord& record);

public:
	//查询了错误的字段名不会导致记录里的字段增加
	CRecord& operator[](CString Field);
	//给记录赋值字段值，不存在则添加
	CRecord operator=(const CValue& value);

public:
	//一旦设置属性则添加属性，即便字段名不存在
	CAttri* operator->();
	CValue toValue();

public:
	CString ToCString();

};