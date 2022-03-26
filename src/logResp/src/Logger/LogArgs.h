#ifndef _LOG_ARGS_H_
#define _LOG_ARGS_H_

#include <sstream> // for ostringstream can work
#include <iostream>
#include <memory>
#include <string>
#include "LoggerCommon.h"
#include "DateTime.h"

class LogArgs
{
public:
    LogArgs(LogType type, std::string msg, LogLevel level = LogLevel::LOGINFO, std::shared_ptr<DateTime> time = nullptr)
    {
        mLevel = level;
        mType = type;
        mActionMessage = msg;
        if(time == nullptr)
            mTime = std::make_shared<DateTime>();
    }

    ~LogArgs(){
    }

    std::string GetLogTime(){
        std::string time;
        try{
            std::ostringstream ss;
            ss << std::setfill('0') << std::setw(2) << mTime->GetHour()
               << ":" << std::setfill('0') << std::setw(2) << mTime->GetMinute()
               << ":" << std::setfill('0') << std::setw(2) << mTime->GetSecond()
               << "." << std::setfill('0') << std::setw(2) << mTime->GetMillisecond();
            time = ss.str();
        }
        catch(std::exception ex){
            std::cout << "In LogArgs occur ERROR: " << ex.what() << std::endl;
        }
        return time;
    }

    std::string GetLogDate(){
        std::string time;
        try{
            std::ostringstream ss;
            ss << std::setfill('0') << std::setw(4) << mTime->GetYear()
               << "-" << std::setfill('0') << std::setw(2) << mTime->GetMonth()
               << "-" << std::setfill('0') << std::setw(2) << mTime->GetDay();
            time = ss.str();
        }
        catch(std::exception ex){
            std::cout << "In LogArgs occur ERROR: " << ex.what() << std::endl;
        }
        return time;
    }

    std::string GetLogHour(){
        std::string time;
        try{
            std::ostringstream ss;
            ss << std::setfill('0') << std::setw(2) << mTime->GetHour();
            time = ss.str();
        }
        catch(std::exception ex){
            std::cout << "In LogArgs occur ERROR: " << ex.what() << std::endl;
        }
        return time;

    }

    LogType GetType(){ return mType;}
    LogLevel GetLevel(){ return mLevel;}
    std::string GetActionMessage(){ return mActionMessage;}

private:
    std::string mActionMessage; 
    LogLevel mLevel;
    LogType mType;
    std::shared_ptr<DateTime> mTime;
};

#endif // _LOG_ARGS_H_