#pragma once

#ifdef _CStorageAPI
	#define CStorageAPI _declspec(dllimport)
#else
	#define CStorageAPI _declspec(dllexport)
#endif
