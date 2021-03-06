#ifndef _LOG_ENTRY_
#define _LOG_ENTRY_

#include <string>
#include <iostream>
#include <sstream>

#include <core/logger/log_levels.h>
#include <core/datetime_utility.h>
#include <core/string_utility.h>

namespace core
{

class LogEntry
{
    public :

    LogEntry()
    {
    };

    LogEntry(const LogLevel level, const std::string sender, const std::string message, const std::string sourceCode, const std::string sourceCodeLineNumber)
        : m_logLevel(level), m_sender(sender), m_message(message), m_sourceCode(sourceCode), m_sourceCodeLineNumber(sourceCodeLineNumber)
    {
    }

    LogEntry(const LogLevel level, const std::string sender, const std::string message, const std::string sourceCode, const std::string sourceCodeLineNumber, const std::string exclusiveSink)
    : LogEntry(level, sender, message, sourceCode, sourceCodeLineNumber)// CPP11 Constructor delegation
    {
        m_exclusiveSink = exclusiveSink;
    }

    friend std::ostream& operator<<(std::ostream& os, LogEntry& entry)
    {
        std::string logLevel;

        switch (entry.m_logLevel)
        {
            case LogLevel::LEVEL_INFO:
                logLevel = "INFO";
                break;

            case LogLevel::LEVEL_WARNING:
                logLevel = "WARNING";
                break;

            case LogLevel::LEVEL_ERROR:
                logLevel = "ERROR";
                break;
        }

        os << core::format("[ %s : %s ]",  entry.m_sourceCode, entry.m_sourceCodeLineNumber);
        os << std::endl;
        os << core::format("%s : %s , %s , %s", getCurrentDateTime(), logLevel, entry.m_sender, entry.m_message);
        return os;
    }

    const std::string getExclusiveSink() const
    {
        return m_exclusiveSink;
    }

    const std::string toString() const
    {
        std::stringstream stream;
        stream << this;
        return stream.str();
    }

    const std::string& getMessage() const
    {
        return m_message;
    }

    private :
        LogLevel m_logLevel;
        std::string m_sender;
        std::string m_message;
        std::string m_sourceCode;
        std::string m_sourceCodeLineNumber;
        std::string m_exclusiveSink; // If set this log will be processed by only one sink
};

}

#endif