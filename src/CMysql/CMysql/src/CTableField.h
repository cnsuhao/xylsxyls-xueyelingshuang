#pragma once
#include <afxwin.h>
#include "CMysqlMacro.h"

class CValue;
class CCondition;
class CMysqlAPI CTableField{
public:
	CString Table;
	CString Field;
public:
	//tf("User")["ID"];
	CTableField& operator()(CString Table);
	CTableField& operator[](CString Field);
public:
	CTableField();
	CTableField(const CTableField& tf);
	CTableField operator=(const CTableField& tf);

public:
	CTableField(CString Table,CString Field);

public:
	CCondition operator==(const CValue& value);
	CCondition operator!=(const CValue& value);
	CCondition operator<(const CValue& value);
	CCondition operator>(const CValue& value);
	CCondition operator<=(const CValue& value);
	CCondition operator>=(const CValue& value);
	//内联
	CCondition operator&&(const CTableField& tf);
	//左联合，左边的数据量大于等于右边的数据量
	CCondition operator<=(const CTableField& tf);
	//右联合，左边的数据量小于等于右边的数据量
	CCondition operator>=(const CTableField& tf);
	//全联
	CCondition operator||(const CTableField& tf);
};