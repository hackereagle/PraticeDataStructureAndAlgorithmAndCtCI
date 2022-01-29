#ifndef _RORZE_LOGGER_H_
#define _RORZE_LOGGER_H_ 

#include <cstddef>
#include <thread>
#include <queue>
#include <memory>
#include <string>
#include "LogArgs.h"

#ifdef _WIN32
class DLLEXPORT_LOGGER_API Logger
#else
class Logger
#endif
{
public:
    ~Logger();
    static Logger& GetInstance();
    bool Initialize(LogLevel fileLogLevel = LogLevel::LOGINFO);
    void AsyncWrite(LogType type, const char *msg, LogLevel level = LogLevel::LOGINFO, std::shared_ptr<DateTime> time = nullptr);
    void AsyncWrite(LogType type, std::string msg, LogLevel level = LogLevel::LOGINFO, std::shared_ptr<DateTime> time = nullptr);
    void SyncWrite(LogType type, const char *msg, LogLevel level = LogLevel::LOGINFO, std::shared_ptr<DateTime> time = nullptr);
    void RestarAsyncWrite();
    void StopAsyncWrite();

private:
    static Logger* mInstance;
    std::thread mBackgroundWriteLog;
    int mWritePeriod = 5; // unit: ms
    bool mIsInitialize = false;
    std::queue<std::unique_ptr<LogArgs>> mLogBuffer;
    bool mIsAsyncWrite = true;
    mutable std::string mLogPath;
    const std::string mPathSpacer = std::string("/");
    // setting
    // TODO: In future, the setting would be wraped to a class and judge whether write log.
    LogLevel mLevel;

    Logger();
    void AsyncWriteLogService();
    void CheckDirectoryExist(std::string& path);
    void WriteToFile(std::unique_ptr<LogArgs> log);
};
 #endif //_RORZE_LOGGER_H_