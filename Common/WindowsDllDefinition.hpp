#pragma once

#if _WIN32
    #ifdef EXPORTED_DLL
    #define DLLEXPORT_API __declspec(dllexport)
    #else
    #define DLLEXPORT_API __declspec(dllimport)
    #endif
#else
    #define DLLEXPORT_API 
#endif //_WIN32