#pragma once

// TODO Мысль с прикручиваем прокси в том, чтобы синглтон оставить на верхнем уровне, а внутрь него 
// запихнуть класс, который будет делать всю полезную работу, с его интерфейсом и прокси
// Да, и нахвания тоже надо будет подкрутить

#include <iostream>
#include <fstream>
#include <chrono>
#include <memory>

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void __fastcall write(const std::string& str) {
        if (!out.is_open()) return;
        if (!writer) return;
        writer->write(str); 
    }

    void __fastcall write(const std::string& str, int n) {
        if (!out.is_open()) return;
        if (!writer) return;
        writer->write(str, n); 
    }

    void __fastcall write(const std::string& str, double d) { 
        if (!out.is_open()) return;
        if (!writer) return;
        writer->write(str, d); 
    }
    
private:
    Logger() : writer(std::shared_ptr<NumberedWriter>{new NumberedWriter(*this)}) {        
        openLog("newLog.txt");
    }
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    ~Logger() {
        closeLog();
    }

    void __fastcall openLog(const std::string& fileName) {
        out.open(fileName, std::ios::out);
    }

    void closeLog() {
        if (!out.is_open()) return;
        out.close();
    }

    class Writer {
    public:
        virtual ~Writer() = default;
        Writer(Logger& logger) : logger(logger) {}

        virtual void __fastcall write(const std::string& str) = 0;
        virtual void __fastcall write(const std::string& str, int n) = 0;
        virtual void __fastcall write(const std::string& str, double d) = 0;
    protected:
        Logger& logger;
    };

    class BaseWriter : public Writer {
    public:
        BaseWriter(Logger& logger) : Writer(logger) {}

        void __fastcall write(const std::string& str) override {
            logger.out << Logger::getCurDateTime() << " - " << str << std::endl;
        }

        void __fastcall write(const std::string& str, int n) override {
            logger.out << Logger::getCurDateTime() << " - " << str << n << std::endl;
        }

        void __fastcall write(const std::string& str, double d) override {
            logger.out << Logger::getCurDateTime() << " - " << str << d << std::endl;
        }
    };

    class NumberedWriter : public Writer {
    public:
        NumberedWriter(Logger& logger) : Writer(logger), 
            baseWriter(std::shared_ptr<BaseWriter>{new BaseWriter(logger)}), recordNumber(0) {}

        void __fastcall write(const std::string& str) override {
            if (!baseWriter) return;

            logger.out << ++recordNumber << ". ";
            baseWriter->write(str);
        }

        void __fastcall write(const std::string& str, int n) override {
            if (!baseWriter) return;

            logger.out << ++recordNumber << ". ";
            baseWriter->write(str, n);
        }

        void __fastcall write(const std::string& str, double d) override {
            if (!baseWriter) return;

            logger.out << ++recordNumber << ". ";
            baseWriter->write(str, d);
        }
    private:
        std::shared_ptr<BaseWriter> baseWriter;
        int recordNumber;
    };

    static std::string getCurDateTime() {
        auto cur = std::chrono::system_clock::now();
        time_t time = std::chrono::system_clock::to_time_t(cur);
        char buf[64] = { 0 };
        ctime_s(buf, 64, &time);
        buf[strlen(buf) - 1] = '\0';
        return std::string(buf);
    }

    std::ofstream out;
    std::shared_ptr<Writer> writer;
};