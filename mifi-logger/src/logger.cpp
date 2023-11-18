#include "logger.h"
#include <cassert>
#include <fstream>
#include <iostream>

namespace helpers{
    static const std::string string_from_log_level(log_level level)
    {
        switch(level)
        {
            case log_level::debug:
                return "DEBUG";
            
            case log_level::error:
                return "ERROR";
            
            case log_level::info:
                return "INFO";
            
            case log_level::warning:
                return "WARNING";
            
            default:
                return "INFO";
        }
    }
}

using namespace helpers;

struct logger::logger_impl
{
    log_level level = log_level::default_level;
    std::ofstream stream;
};

logger logger::get_logger()
{
    static logger singleton;
    if (!singleton.impl_)
    {
        auto impl = std::make_shared<logger::logger_impl>();
        impl->stream.open("log.txt", std::ios_base::app);
        if (!impl->stream.is_open())
        {
            throw std::runtime_error{"Cannot open the log file"};
        }
        singleton.impl_ = impl;
    }
    return singleton;
}

void logger::write(log_level level, const std::string &msg) const
{
    assert(impl_);
    if (level > impl_->level)
        return;
    
    impl_->stream
        << "["
        << string_from_log_level(level)
        << "]\t"
        << msg
        << '\n';
}

log_level logger::get_level() const
{
    assert(impl_);
    return impl_->level;
}

void logger::set_level(log_level level)
{
    assert(impl_);
    impl_->level = level;
}