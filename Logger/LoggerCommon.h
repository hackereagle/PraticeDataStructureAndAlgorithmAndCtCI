#pragma once
#ifndef _LOGGER_COMMON_H_
#define _LOGGER_COMMON_H_

#define LOGTYPE_VALUE_TABLE \
    LOGTYPE_TABLE(Start,       "Start") \
    LOGTYPE_TABLE(Camera,      "Camera") \
    LOGTYPE_TABLE(Socket,      "Socket") \
    LOGTYPE_TABLE(TeachData,   "TeachData") \
    LOGTYPE_TABLE(Application, "Application") \
    LOGTYPE_TABLE(Algorithm,   "Algorithm") \
    LOGTYPE_TABLE(Exception,   "Exception") \
    LOGTYPE_TABLE(Final,       "Final") 

#define LOGTYPE_TABLE(a, b) a,
enum LogType {LOGTYPE_VALUE_TABLE};
#undef LOGTYPE_TABLE

inline const char* EnumToString(LogType value) {
#define LOGTYPE_TABLE(a, b) b,
    static const char* table[] = {LOGTYPE_VALUE_TABLE};
#undef LOGTYPE_TABLE
    return table[value];
};

enum LogLevel
{
    LOGALL = 0,
    LOGTRACE,
    LOGDEBUG,
    LOGINFO,
    LOGWARN,
    LOGERROR,
    LOGFATAL,
    LOGOFF,
};

#define PRINT_STEP_TIME(STEP, ELAPSED_TIME_MS) std::cout << STEP << " spend " << ELAPSED_TIME_MS << " ms" << std::endl;
#endif // _LOGGER_COMMON_H_