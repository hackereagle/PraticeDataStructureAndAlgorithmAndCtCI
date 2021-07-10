// This method of writting log is refering to https://teddybearfp.github.io/2019/04/08/C-logger/
#include "scLog.h"
#include <stdio.h>
#include <direct.h>
#include <time.h>
#include <windows.h>
#include <io.h>

LogLevels logThreshold;
char folderPath[_MAX_PATH];
char filePath[_MAX_PATH];
char title[100];

inline static const char* GetLogLevel(int level)
{
	switch (level)
	{
	case LogLevels::LOGALL: return "[TRACE] ";
	case LogLevels::LOGDEBUG: return "[DEBUG] ";
	case LogLevels::LOGINFO: return "[INFO] ";
	case LogLevels::LOGWARN: return "[WARN] ";
	case LogLevels::LOGERROR: return "[ERROR] ";
	case LogLevels::LOGFATAL: return "[FATAL] ";
	default:
		return "";
		break;
	}
	return "";
}

char* GetTime(RequestType request)
{
	char currentTime[200];
	memset((void*)currentTime, 0, sizeof(currentTime));

	// get time
	time_t now = time(NULL);
	SYSTEMTIME sysTime;
	GetSystemTime(&sysTime);
	char ms[10];
	int time_ms = sysTime.wMilliseconds;

	if (LogTimeStamp == request) {
		strftime(currentTime, 30, "%F %T", localtime(&now));
		sprintf_s(ms, ".%03d", time_ms);
		strcat_s(currentTime, ms);
	}
	else {
		strftime(currentTime, 30, "%Y%m%d%H%M", localtime(&now));
	}

	return currentTime;
}

void initialLog(char* path, LogLevels level, char* title)
{
	memcpy(folderPath, path, sizeof(folderPath));
	memcpy(filePath, folderPath, sizeof(filePath));

	char* date = GetTime(LogFileName);
	strcat_s(filePath, "/");
	strcat_s(filePath, title);
	strcat_s(filePath, date);
	strcat_s(filePath, ".log");

	logThreshold = level;
}

void scLog(LogLevels level, const char* message, const char* function)
{
	if (filePath[0] == '\0')
		return;

	char _msg[600];
	memset(_msg, 0, sizeof(_msg));

	FILE* fp = NULL;
	mkdir(folderPath);

	if (level >= logThreshold) {
		int threadId = GetCurrentThreadId();
		char time[30];
		memset(time, 0, sizeof(time));
		strcat_s(time, GetTime(LogTimeStamp));
		sprintf_s(_msg, "%s, %s, Thread ID [%d], %s: %s", time, GetLogLevel(level), threadId, function, message);

		fp = fopen(filePath, "a");
		fprintf(fp, "%s", _msg);
		fclose(fp);
	}
}