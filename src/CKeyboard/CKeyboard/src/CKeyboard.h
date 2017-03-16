#pragma once
#include <string>
#include <vector>
#include <windows.h>
#include "CKeyboardMacro.h"
using namespace std;

class CKeyboardAPI CKeyboard{
public:
	enum{
		Esc = VK_ESCAPE,
		F1 = VK_F1,
		F2 = VK_F2,
		F3 = VK_F3,
		F4 = VK_F4,
		F5 = VK_F5,
		F6 = VK_F6,
		F7 = VK_F7,
		F8 = VK_F8,
		F9 = VK_F9,
		F10 = VK_F10,
		F11 = VK_F11,
		F12 = VK_F12,
		PrintScreen = VK_PRINT,
		ScrollLock = VK_SCROLL,
		Pause = VK_PAUSE,
		Backspace = VK_BACK,
		Insert = VK_INSERT,
		Home = VK_HOME,
		PageUp = VK_PRIOR,
		Delete = VK_DELETE,
		End = VK_END,
		PageDown = VK_NEXT,
		NumLock = VK_NUMLOCK,
		CapsLock = VK_CAPITAL,
		Shift = VK_SHIFT,
		Up = VK_UP,
		Left = VK_LEFT,
		Down = VK_DOWN,
		Right = VK_RIGHT,
		Ctrl = VK_CONTROL,
		Win = VK_LWIN,
		Alt = VK_MENU,
		MouseRightClick = VK_APPS
	};
public:
	//?���¼���
	static bool KeyDown(int code);
	//?�������
	static bool KeyUp(int code);
	//?���µ������ʱ�䣬Ĭ��100-300����
	static bool KeyPress(int code, int sleepTime = -1);
	//?�����ַ��������ʱ�䣬֧�����е����ַ����룬����!@֮�࣬���Ƕ���Ӣ���ַ�
	static bool InputString(const string& str, int sleepTime = -1);
	//?������ϼ������ʱ�䣬Ctrl+Alt+Delete�޷�ģ�⣬���������������������ʹ��Ctrl+Shift+Esc
	static bool KeyManyPress(const vector<int>& vecCode, int sleepTime = -1);
	//?���������ַ���

	//?��ȡ���룬��������Ӣ���ַ��ķ���-1
	static vector<int> GetCode(char c);
};