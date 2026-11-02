#include <string>
#include "logger.h"
#include "tracked_string.h"

int main() {
    Logger& logger = Logger::getInstance(
        std::string(LOG_DIR) + "/task04.log"
    );

    {
        TrackedString x;
        TrackedString y("test");
    }
}
