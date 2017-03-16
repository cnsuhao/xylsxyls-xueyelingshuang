#include "CMouse.h"
#include "DmSoft/DmSoftAPI.h"
#include "CRandom/CRandomAPI.h"
#include <math.h>
#include <map>

enum{
	ClickTimeMin = 100,
	ClickTimeMax = 300,
	MoveTimeMin = 50,
	MoveTimeMax = 1000
};

bool CMouse::LeftDown(){
	return DmSoft::LeftDown() == 1;
}

bool CMouse::RightDown(){
	return DmSoft::RightDown() == 1;
}

bool CMouse::LeftUp(){
	return DmSoft::LeftUp() == 1;
}

bool CMouse::RightUp(){
	return DmSoft::RightUp() == 1;
}

bool CMouse::LeftClick(int sleepTime){
	bool result = true;
	result = result && (DmSoft::LeftDown() == 1);
	if (sleepTime == -1) sleepTime = CRandom::Int(ClickTimeMin, ClickTimeMax);
	Sleep(sleepTime);
	result = result && (DmSoft::LeftUp() == 1);
	return result;
}

bool CMouse::RightClick(int sleepTime){
	bool result = true;
	result = result && (DmSoft::RightDown() == 1);
	if (sleepTime == -1) sleepTime = CRandom::Int(ClickTimeMin, ClickTimeMax);
	Sleep(sleepTime);
	result = result && (DmSoft::RightUp() == 1);
	return result;
}

bool CMouse::LeftDoubleClick(int sleepTime){
	//?��ȡɢ��
	if (sleepTime == -1) sleepTime = CRandom::Int(ClickTimeMin, ClickTimeMax);
	vector<int> vecSleepTime = CRandom::Hash(sleepTime, 3);
	bool result = true;
	result = result && LeftClick(vecSleepTime.at(0));
	Sleep(vecSleepTime.at(1));
	result = result && LeftClick(vecSleepTime.at(2));
	return result;
}

bool CMouse::RightDoubleClick(int sleepTime){
	if (sleepTime == -1) sleepTime = CRandom::Int(ClickTimeMin, ClickTimeMax);
	vector<int> vecSleepTime = CRandom::Hash(sleepTime, 3);
	bool result = true;
	result = result && RightClick(vecSleepTime.at(0));
	Sleep(vecSleepTime.at(1));
	result = result && RightClick(vecSleepTime.at(2));
	return result;
}

bool CMouse::LeftManyClick(int times, int sleepTime){
	if (sleepTime == -1) sleepTime = CRandom::Int(ClickTimeMin, ClickTimeMax);
	vector<int> vecSleepTime = CRandom::Hash(sleepTime, times * 2 - 1);
	bool result = true;
	int i = -1;
	while (i++ != vecSleepTime.size() - 2){
		result = result && LeftClick(vecSleepTime.at(i));
		i++;
		Sleep(vecSleepTime.at(i));
	}
	result = result && LeftClick(vecSleepTime.at(i));
	return result;
}

bool CMouse::RightManyClick(int times, int sleepTime){
	if (sleepTime == -1) sleepTime = CRandom::Int(ClickTimeMin * (times * 2 - 1), ClickTimeMax * (times * 2 - 1));
	vector<int> vecSleepTime = CRandom::Hash(sleepTime, times * 2 - 1);
	bool result = true;
	int i = -1;
	while (i++ != vecSleepTime.size() - 2){
		result = result && RightClick(vecSleepTime.at(i));
		i++;
		Sleep(vecSleepTime.at(i));
	}
	result = result && RightClick(vecSleepTime.at(i));
	return result;
}

bool CMouse::MoveAbsolute(Rect rect, int sleepTime){
	if (sleepTime == -1) sleepTime = CRandom::Int(MoveTimeMin, MoveTimeMax);
	//?����һ����
	Point pointResult(CRandom::Int(rect.left, rect.right), CRandom::Int(rect.top, rect.bottom));
	//?�Ƿ���������
	if (sleepTime == 0) return DmSoft::MoveTo(pointResult.x, pointResult.y) == 1;
	//?������������
	else{
		//?��ǰλ��
		Point currentPoint = GetCurrentPos();
		int step = abs(currentPoint.x - pointResult.x) + abs(currentPoint.y - pointResult.y);
		map<string, int> mapCard;
		mapCard[currentPoint.x < pointResult.x ? "1,0" : "-1,0"] = abs(currentPoint.x - pointResult.x);
		mapCard[currentPoint.y < pointResult.y ? "0,1" : "0,-1"] = abs(currentPoint.y - pointResult.y);
		//?�������·��
		vector<string> vecRoad = CRandom::Deal(mapCard);
		//?����������ʱ��
		vector<int> vecSleepTime = CRandom::Hash(sleepTime, step - 1);
		bool result = true;
		int i = -1;
		while (i++ != vecRoad.size() - 1){
			if (vecRoad.at(i) == "1,0") result = result && (DmSoft::MoveR(1, 0) == 1);
			else if (vecRoad.at(i) == "-1,0") result = result && (DmSoft::MoveR(-1, 0) == 1);
			else if (vecRoad.at(i) == "0,1") result = result && (DmSoft::MoveR(0, 1) == 1);
			else if (vecRoad.at(i) == "0,-1") result = result && (DmSoft::MoveR(0, -1) == 1);
			if (i == vecRoad.size() - 1) break;
			Sleep(vecSleepTime.at(i));
		}
		return result;
	}
}

bool CMouse::MoveOpposite(Rect rect, int sleepTime){
	Point currentPoint = GetCurrentPos();
	Rect rectAbsolute(currentPoint.x + rect.left, currentPoint.y + rect.top, currentPoint.x + rect.right, currentPoint.y + rect.bottom);
	return MoveAbsolute(rectAbsolute, sleepTime);
}

bool CMouse::MidWheelDown(){
	return DmSoft::WheelDown() == 1;
}

bool CMouse::MidWheelUp(){
	return DmSoft::WheelUp() == 1;
}

Point CMouse::GetCurrentPos(){
	VARIANT x, y;
	DmSoft::GetCursorPos(&x, &y);
	return Point(x.intVal,y.intVal);
}

/*
int main(){
	printf("1");
	Sleep(2000);
	bool xx = CMouse::LeftManyClick(3);
	printf("%d",xx);
	getchar();
	int x = 3;
	return 0;
}*/