#pragma once

#ifdef _CMouseAPI
#define CMouseAPI _declspec(dllimport)
#else
#define CMouseAPI _declspec(dllexport)
#endif

#if defined(STATIC_LIB)
#undef CMouseAPI
#define CMouseAPI 
#endif