#pragma once
#include <afxwin.h>
#include "CGetPathMacro.h"
#include <vector>
using namespace std;

class CGetPathAPI CGetPath{
public:
	//返回ocx所在路径，带\符号
	static string GetRegOcxPath(string classid);
	//返回本进程所在路径，带\符号
    static string GetCurrentExePath();
	//通过窗口获取文件夹路径，不能获取文件路径，带\符号，传入MFC句柄
    static string GetFolderFromWindow(HWND hWnd);
	//浏览窗口选取文件获取文件路径，成功返回绝对路径，失败返回CString字符串-1
	static string GetFileFromWindow(HWND hwnd);
#ifdef WTL
    static std::string GetFileFromWindow(HWND hwnd);
#endif
	//FileStr传文件名或后缀名不带点，不查找文件夹，得到的绝对路径放到vector里，这个函数是递归函数
	//strPath如果传必须传文件夹，寻找文件夹以下，如果不传则寻找当前路径及以下的所有文件夹，带不带\\都可以
	//flag = 1表示查找文件，2表示查找文件后缀名，3表示查找所有文件，FileStr不起作用
    static vector<string> FindFilePath(string FileStr, string strPath = "", BOOL flag = 1);
	//获取进程pid，传入进程名
    static vector<int> GetProcessID(string strProcessName);
	//根据pid获取窗口句柄
    static HWND GetHwndByProcessId(DWORD dwProcessId);
    //获取文件相关信息，flag1表示获取文件全名，flag2表示获取文件后缀名，flag3表示获取文件名，flag4表示获取前面的路径带\\符号
    static string GetName(const string& path, int flag);
};