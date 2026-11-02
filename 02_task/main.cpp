#include "tracked_string.h"
#include "logger.h"
#include <string>

int main() {
    Logger& logger = Logger::getInstance(
        std::string(LOG_DIR) + "/task02.log"
    );
    logger.setLevel(Logger::Level::DEBUG);

    {
        TrackedString a;
        TrackedString b("hello");
        std::string s="world";
        TrackedString c(s);
        TrackedString d=c;
        a = b;
    }

    logger.log("totalCreated = " + std::to_string(TrackedString::getTotalCreated()),Logger::Level::INFO
    );

    logger.log("aliveCount = " + std::to_string(TrackedString::getAliveCount()),Logger::Level::INFO
    );
}
