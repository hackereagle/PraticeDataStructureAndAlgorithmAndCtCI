#pragma once

#ifndef _SCLOG_H_
#define _SCLOG_H_

enum LogLevels
{
	LOGALL,
	LOGTRACE,
	LOGDEBUG,
	LOGINFO,
	LOGWARN,
	LOGERROR,
	LOGFATAL,
	LOGOFF
};

enum RequestType
{
	LogTimeStamp,
	LogFileName
};

//void SetLogPath(char* path);
//void SetLogLevel(LogLevels level = LOGINFO);
void initialLog(char* path = "./Log", LogLevels level = LOGINFO, char* title = "Log");
void scLog(LogLevels level, const char* message, const char* function);
#endif // !_SCLOG_H_
