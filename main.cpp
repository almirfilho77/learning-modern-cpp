#include <iostream>
#include <string>

#include "mifi-logger/api/logger.h"

int main(int argc, char **argv)
{
    std::cout << "working\n";
    auto logger = helpers::logger::get_logger();
    logger.set_level(helpers::log_level::info);
    logger.write(helpers::log_level::info, "Starting up!");

    write_log(logger, helpers::log_level::info, 
        "testing several alguments with variadic templates:", 
        100, 
        "boo", 
        -10);

    return 0;
}