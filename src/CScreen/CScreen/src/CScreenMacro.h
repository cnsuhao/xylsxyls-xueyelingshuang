#pragma once

#ifdef _CScreenAPI
#define CScreenAPI _declspec(dllimport)
#else
#define CScreenAPI _declspec(dllexport)
#endif

#if defined(STATIC_LIB)
#undef CScreenAPI
#define CScreenAPI 
#endif