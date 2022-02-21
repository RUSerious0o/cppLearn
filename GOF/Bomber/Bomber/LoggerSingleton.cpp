#pragma once

#include <iostream>
#include <fstream>
#include <chrono>

using std::string;
using std::ios_base;
using std::endl;

class FileLoggerSingleton {
public:
    static FileLoggerSingleton& getInstance()
    {
        static FileLoggerSingleton instance;
        return instance;
    }

    void __fastcall OpenLogFile(const string& FN)
    {
        logOut.open(FN, ios_base::out);
    }

    void CloseLogFile()
    {
        if (logOut.is_open())
        {
            logOut.close();
        }
    }

    void __fastcall WriteToLog(const string& str)
    {
        if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << endl;
        }
    }

    void __fastcall WriteToLog(const string& str, int n)
    {
        if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << n << endl;
        }
    }

    void __fastcall WriteToLog(const string& str, double d)
    {
        if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << d << endl;
        }
    }

private:
    std::ofstream logOut;

    FileLoggerSingleton() {}
    FileLoggerSingleton(const FileLoggerSingleton& base) = delete;
    FileLoggerSingleton& operator=(const FileLoggerSingleton& base) = delete;

    static string GetCurDateTime()
    {
        auto cur = std::chrono::system_clock::now();
        time_t time = std::chrono::system_clock::to_time_t(cur);
        char buf[64] = { 0 };
        ctime_s(buf, 64, &time);
        buf[strlen(buf) - 1] = '\0';
        return string(buf);
    }
};