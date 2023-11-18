#pragma once

#include <memory>
#include <string>
#include <sstream>

#include <iostream>

namespace helpers {

    enum class log_level : int {
        off = 0,
        error,
        warning,
        info,
        default_level = info,
        debug,
        _last
    };

    class logger {
    public:
        static logger get_logger();

        // Copy c'tor... copying is cheap, thanks to shared implementation (pimpl idiom)
        logger(const logger &) = default;
        // Copy asignment operator
        logger &operator=(const logger &) = default;

        // Get current log level
        log_level get_level() const;
        // Messages with a higher log level will be ignored by the logger
        void set_level(log_level level);

        // Write the log messages within the log level restriction
        void write(log_level level, const std::string &msg) const;

    private:
        // For singleton, use get_logger instead
        logger() = default;

        // All loggers use the same implementation (pimpl idiom)
        struct logger_impl;
        std::shared_ptr<logger_impl> impl_;

    };
}

namespace details {
    template<typename MessagePart>
    inline void stream_parts(std::stringstream &stream, const MessagePart &msg_part)
    {
        stream << " " << msg_part;
    }

    template<typename MessagePart, typename... MessageParts>
    inline void stream_parts(std::stringstream &stream, 
        const MessagePart &msg_part,
        const MessageParts &...more_parts)
    {
        stream << " " << msg_part;
        stream_parts(stream, more_parts...);
    }
}

template<typename... MessageParts>
inline void write_log(helpers::logger &logger, helpers::log_level level, const MessageParts &...msg_parts)
{
    if (level > logger.get_level())
    {
        return;
    }

    std::stringstream s;
    details::stream_parts(s, msg_parts...);
    logger.write(level, s.str());
}