#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include "../Logger/Logger.h"
#include "../Logger/DateTime.h"
#include "../Logger/LogArgs.h"

int main(int argc, char* argv[])
{
    // Test DateTime class
    std::cout << "=== Test DateTime class ===" << std::endl;
    DateTime *time = new DateTime();
    std::cout << "Year = " << time->GetYear() << std::endl;
    std::cout << "Month = " << std::setfill('0') << std::setw(2) << time->GetMonth() << std::endl;
    std::cout << "Day = " << std::setfill('0') << std::setw(2) << time->GetDay() << std::endl;
    std::cout << "Hour = " << std::setfill('0') << std::setw(2) << time->GetHour() << std::endl;
    std::cout << "Minute = " << std::setfill('0') << std::setw(2) << time->GetMinute() << std::endl;
    std::cout << "Second = " << std::setfill('0') << std::setw(2) << time->GetSecond() << std::endl;
    std::cout << "Millisecond = " << std::setfill('0') << std::setw(3) << time->GetMillisecond() << std::endl;
    delete time;

    // Test LogArgs class
    std::cout << "\n\n=== Test LogArgs class ===" << std::endl;
    LogArgs* arg = new LogArgs(LogType::Camera, "You are going to do a great job!"); 
    std::cout << "type = " << EnumToString(arg->GetType()) << std::endl;
    std::cout << "message = " << arg->GetActionMessage() << std::endl;
    std::cout << "Level = " << EnumToString(arg->GetLevel()) << std::endl;
    std::cout << "Time = " << arg->GetLogTime() << std::endl;
    delete arg;

    std::cout << "\n\n=== Test Logger class ===" << std::endl;
    Logger::GetInstance().Initialize();
    Logger::GetInstance().AsyncWrite(LogType::Application, "test", LogLevel::LOGERROR);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "end testing" << std::endl;

    getchar();
    return EXIT_SUCCESS;
}