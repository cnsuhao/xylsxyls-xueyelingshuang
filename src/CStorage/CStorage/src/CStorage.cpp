#include <SDKDDKVer.h>
#include "CStorage.h"

CStorage& CStorage::operator[](CString key){
	strCurrentKey = key;
	return *this;
}

CStorage CStorage::operator=(any anyValue){
	mapData[strCurrentKey] = anyValue;
	return *this;
}

template<typename T>
T CStorage::toValue(){
	auto it = mapData.find(strCurrentKey);
	any anyValue;
	CString strError;
	try{
		if(it != mapData.end()){
			anyValue = it->second;
			return any_cast<T>(anyValue);
		}
		strError.Format("key值：%s，不存在",strCurrentKey.c_str());
		AfxMessageBox(strError);
		return T();
	}
	catch (boost::bad_any_cast &e){
		strError.Format("错误，类型为:%s，\nboost解释：%s",it->second.type().name(),e.what());
		AfxMessageBox(strError);
		return T();
	}
}

/*
int main(){
	CStorage stor;
	stor["2222"] = CString("3333");
	//stor["2222"] = 3.3;
	CString xxxxxxxx = stor["2222"].toValue<CString>();

	map<std::string,boost::any> map;
	any ai;
	any as;
	ai = 3;
	ai = std::string("5");
	ai = 6;
	as = std::string("2");
	string x = "1";
	map[x] = 1;
	x = std::string("2");
	map[x] = std::string("22");
	string str = map["2"].type().name();
	
	try   
	{
		int xxx = any_cast<int>(map["2"]);
	}
	catch(boost::bad_any_cast & e)
	{
		string xxxx = e.what();
		int x = 3;
	}   
	//as = "2";
	//ai = "1";
	//char*s = any_cast<char*>(ai);
	return 0;
}*/