#pragma once

#ifdef _CStringManagerAPI
#define CStringManagerAPI _declspec(dllimport)
#else
#define CStringManagerAPI _declspec(dllexport)
#endif

#if defined(STATIC_LIB)
#undef CStringManagerAPI
#define CStringManagerAPI 
#endif