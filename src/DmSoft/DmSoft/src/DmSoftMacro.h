#pragma once

#ifdef _DmSoftAPI
#define DmSoftAPI _declspec(dllimport)
#else
#define DmSoftAPI _declspec(dllexport)
#endif

#if defined(STATIC_LIB)
#undef DmSoftAPI
#define DmSoftAPI 
#endif