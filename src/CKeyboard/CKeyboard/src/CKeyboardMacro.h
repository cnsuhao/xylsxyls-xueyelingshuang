#pragma once

#ifdef _CKeyboardAPI
#define CKeyboardAPI _declspec(dllimport)
#else
#define CKeyboardAPI _declspec(dllexport)
#endif

#if defined(STATIC_LIB)
#undef CKeyboardAPI
#define CKeyboardAPI 
#endif