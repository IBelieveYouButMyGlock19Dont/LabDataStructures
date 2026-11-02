#include <string>
#include "logger.h"

int main() {
    Logger& logger = Logger::getInstance(
        std::string(LOG_DIR) + "/task01.log");
    logger.setLevel(Logger::Level::DEBUG);

    logger.log("Error 1", Logger::Level::ERROR);
    logger.log("Warning 1", Logger::Level::WARNING);
    logger.log("Info 1", Logger::Level::INFO);
    logger.log("Debug 1", Logger::Level::DEBUG);

    logger.setLevel(Logger::Level::WARNING);

    logger.log("Error 2", Logger::Level::ERROR);
    logger.log("Warning 2", Logger::Level::WARNING);
    logger.log("Info 2", Logger::Level::INFO);
    logger.log("Debug 2", Logger::Level::DEBUG);

    Logger& logger2 = Logger::getInstance();

    if (&logger==&logger2) {
        logger.log("Same instance", Logger::Level::WARNING);
    }
    else {
        logger.log("Different instances", Logger::Level::WARNING);
    }
    logger.setFile(std::string(LOG_DIR) + "/task01_second.log");
    logger.log("Second file", Logger::Level::WARNING);
}

