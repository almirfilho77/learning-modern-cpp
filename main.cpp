#include <iostream>
#include <string>

#include "mifi-logger/api/logger.h"

int main(int argc, char **argv)
{
    std::cout << "working\n";
    auto logger = helpers::logger::get_logger();
    logger.set_level(helpers::log_level::info);
    logger.write(helpers::log_level::info, "Starting up!");

    return 0;
}